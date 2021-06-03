#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DAOLib.h"
#include "GerichteDAO.h"
#include "ZutatenDAO.h"
#include "GerichtDetailsDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Deutsche Übersetzung der Qt-Texte laden
    sysTranslator = new QTranslator();
    bSysTranslatorLoaded = sysTranslator->load("qt_de", QLibraryInfo::path(QLibraryInfo::TranslationsPath));
    if (bSysTranslatorLoaded)
        qApp->installTranslator(sysTranslator);

    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}



// private Methoden:
void MainWindow::init()
{
    ui->btnZurEinkaufslisteHinzufuegen->setEnabled(false);
    // Einen neuen Label erstellen für die Anzeige der geladenen Datenbank in der Statusanzeige
    statusLabel = new QLabel();
    // Labeltext innerhalb des Labels einrücken
    statusLabel->setIndent(5);
    // Label zur Statusbar hinzufügen
    // diese soll sich links positionieren
    // der 2. Parameter strech = 1 dehnt den Label über die gesamte Statusbar aus
    statusBar()->addWidget(statusLabel, 1);

    // Menüeinträge aktivieren mit 'enableDatabase'
    enableDatabase(openDatabase("DESKTOP-PNDMIUO\\SQLEXPRESS",       // localhost ist letzlich die flexible Angabe der IP-Adresse
                                "dueck"));                           // Name der Datenbank

    // Einen Event-Filter zur TableView hinzufügen
    ui->tableView->installEventFilter(this);

    // Eine leere Zeichenkette für die Kategorien anlegen
    category = QString();

    // Ändert die Text- und Hintergrundfarbe der slektierten Zeile der TableView
    // damit die Selektion auch beim Fokusverlust durch Anzeige des Dialogs
    // sichtbar bleibt.
    QPalette pal = ui->tableView->palette();
    pal.setColor(QPalette::HighlightedText, Qt::white);
    pal.setColor(QPalette::Highlight, QColor(18, 125, 230));
    ui->tableView->setPalette(pal);

    showTable();
}

void MainWindow::enableDatabase(bool bEnable)
{
    // Menüeinträge aktivieren mit 'enableDatabase'
    ui->menuStammdaten->setEnabled(bEnable);
    ui->menu_Extras->setEnabled(bEnable);

    if (bEnable)
    {
        statusLabel->setText("Datenbank: " + DAOLib::getDatabaseName());
    }
    else
    {
        statusLabel->setText("Datenbank: (keine)");
    }

}

bool MainWindow::openDatabase(const QString &server, const QString &databaseN)
{
    QString driver = "QODBC";                        // 'QODBC' = open database connectivity
    QString driverName = "DRIVER={SQL Server}";

    // öffnen der Datenbank
    // #include "DAOLib.h"
    return DAOLib::connectToDatabase(driver, driverName, server, databaseN);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Datenbank Schliessen
    DAOLib::closeConnection();
}

void MainWindow::showTable()
{
    // Ein TableModel als Datenquelle für die tableView verwenden
    QSqlQueryModel* model = setTableViewModel();

    // Spaltenüberschriften verändern:
    // Schriftgrösse
    QFont font = ui->tableView->horizontalHeader()->font();
    font.setPixelSize(16);
    ui->tableView->horizontalHeader()->setFont(font);
    // Schriftfarbe
    ui->tableView->horizontalHeader()->setStyleSheet("color: rgb(180, 180, 175);");
    // Hintergrundfarbe der Spaltenüberschriften
    ui->tableView->setStyleSheet("QHeaderView::section {background-color: lightgrey;}");
    // alle Spaltenüberschriften linksbündig
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);


    // Spalten ausblenden
    // PRIMARYKEY
    ui->tableView->hideColumn(model->record().indexOf("PRIMARYKEY"));
    // ZUBEREITUNG
    ui->tableView->hideColumn(model->record().indexOf("ZUBEREITUNG"));
    // TIMESTAMP
    ui->tableView->hideColumn(model->record().indexOf("TIMESTAMP"));


    // Spaltenbreite verändern
    // Die Spalten 1, 2 und 3 sollen so breit wie deren breitesterInhalt (also Wort) sein
    ui->tableView->resizeColumnToContents(1);
    ui->tableView->resizeColumnToContents(2);
    ui->tableView->resizeColumnToContents(3);
    // Die letzte Spalte nimmt die gesamte restliche Breite der TableView ein
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    // Per default soll die erste Zeile in der TableView ausgewählt sein
    if (model->rowCount() > 0)
        ui->tableView->selectRow(0);
}

QSqlQueryModel *MainWindow::setTableViewModel()
{
    // Ein evtl. bereits vorhandenes Datenmodell löschen
    delete ui->tableView->model();

    QSqlQueryModel* model;

    if (mealSearched.length() > 0)
    {
        // Bei einer Suche
        model = GerichteDAO::readSearchedGerichteIntoQueryModel(mealSearched);
    }
    else if (mealSearched.length() < 1)
    {
        // QSqlTableModel* model = GerichteDAO::readGerichteIntoTableModel();
        model = GerichteDAO::readGerichteIntoQueryModel(category);
    }

    // Spaltenüberschriften der Tabelle setzen
        model->setHeaderData(model->record().indexOf("DAUER"), Qt::Horizontal, "DAUER (MIN)");

    // Das Datenmodell zuweisen
    ui->tableView->setModel(model);

    // Die TableView liest initial nur die ersten 256 Datensätze. Das ist in der TableView festgelegt.
    // Wenn aber von Anfang an alle Datensätze benötigt werden, kann man mit folgender Anweisung die
    // vollständige Azahl der Datensätze im Datenmodell ermitteln.
    while(model->canFetchMore())
        model->fetchMore();

    // Das Signal selectionChanged mit dem Slot tableView_slectionChanged verbinden. Über diesen Slot wird die aktuelle
    // Zeilennummer von allen Zeilen in der TableView in der Statusbar angezeigt. Der eigene Slot tableView_selectionChanged()
    // benötigt die beiden Argumente QItemSelection, welche vom Signal gesendet werden nicht. Deshalb werden sie
    // auch nicht an den Slot weitergegeben.
    connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
                        this, SLOT(tableView_selectionChanged()));

    return model;
}

void MainWindow::newMeal(const qint64 key)
{   
    // Erstellen eines nicht-modalen Dialogs
    if (newMealDlg == nullptr)
    {
        // Dialog erstellen
        newMealDlg = new NeuDialog(this);
        // dann Dialog anzeigen
        newMealDlg->show();
    }
    else if (newMealDlg != nullptr)
    {
        int msgValue = QMessageBox::question(this, this->windowTitle(),
                                             "Es wird bereits ein neues Gericht angelegt. Soll dieses verworfenwerden um ein leeres neues Gericht zu bearbeiten?",
                                             QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
        if (msgValue == QMessageBox::Cancel)
        {
            //return;
            // Dialog wieder anzeigen
            newMealDlg->show();
            // dann Dialog aktivieren
            newMealDlg->activateWindow();
        }
        else if (msgValue == QMessageBox::Yes)
        {
            // Dialog erst löschen
            delete newMealDlg;
            // dann Dialog erstellen
            newMealDlg = new NeuDialog(this);
            // dann Dialog anzeigen
            newMealDlg->show();
        }
    }
    GerichtDetailsDialog gerichtDetailsDialog(key, this);
    // Die Signale für UPDATE und INSERT mit dem Slot verbinden
    connect(&gerichtDetailsDialog, SIGNAL(refreshData(const qint64)), this, SLOT(updateTableView(const qint64)));
}

void MainWindow::showGerichtDetailsDialog(const qint64 key)
{
    GerichtDetailsDialog gerichtDetailsDialog(key, this);
    // Die Signale für UPDATE und INSERT mit dem Slot verbinden
    connect(&gerichtDetailsDialog, SIGNAL(refreshData(const qint64)), this, SLOT(updateTableView(const qint64)));

    gerichtDetailsDialog.exec();
}

void MainWindow::shoppingList()
{
    // Erstellen eines nicht-modalen Dialogs
    // Nicht-modale Dialoge können nur auf dem Heap erstellt weden.
    if (shoppingListDlg == nullptr)
    {
        // Dialog erstellen
        shoppingListDlg = new EinkaufslisteDialog(this);
        // Dialog anzeigen
        shoppingListDlg->show();
    }
    else if (shoppingListDlg != nullptr)
    {
        // Dialog wieder anzeigen
        shoppingListDlg->show();
        // Dialog aktivieren
        shoppingListDlg->activateWindow();
    }
}

void MainWindow::deleteEntry(const QModelIndex index)
{
    // Das Datenmodell der TableView statt in ein QSqlTableModel in ein QSqlQueryModel konvertieren
    QSqlQueryModel* model = static_cast<QSqlQueryModel*>(ui->tableView->model());

    // Ermitteln des Primärschlüssel in der Spalte PRIMARYKEY über den als
    // Parameter übergebenen QModelIndex.
    qint64 key = model->record(index.row()).value("PRIMARYKEY").toLongLong();

    // Lesen des Gerichtes aus dem Datenmodell zur Anzeige im Message Dialog
    QString gericht = model->record(index.row()).value("Gericht").toString();

    int msgValue = QMessageBox::question(this, this->windowTitle(),
                                         "Das Gericht: '" + gericht + "' löschen?",
                                         QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
    if (msgValue == QMessageBox::Cancel)
        return;

    // Löschen des Gerichtes aus der Tabelle 'Gerichte' über den 'Primärschlüssel'
    if (!GerichteDAO::deleteGericht(key))
        return;

    // Lesen des Gerichtnamens aus dem Datenmodell zur späteren Suche in Tabelle 'Zutaten'
    QString zutaten = model->record(index.row()).value("Gericht").toString();

    // Löschen des Gerichtes aus der Tabelle 'Zutaten' über Namen 'Gericht'
    if (!ZutatenDAO::deleteZutaten(zutaten))
        return;

    statusLabel->setText("Einträge werden aktualisiert...");
    QApplication::processEvents();

    // Postleitzahlen neu in das Datenmodell einlesen
    setTableViewModel();

    // Sicherstellen, das der Row-Index nicht negativ wird.
    int row = (index.row() - 1 < 0) ? 0 : index.row() - 1;

    if (ui->tableView->model()->rowCount() > 0)
        ui->tableView->selectRow(row);
}

bool MainWindow::eventFilter(QObject *absender, QEvent *event)
{
    if (absender == ui->textPersonen)
    {
        // Uns interessiert die Eingabe über die Tastatur prüfen ob das Ereignis ein Tastendruck ist
        if (event->type() == QEvent::KeyPress)
        {
            // Welche Taste wurde betätigt
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

            if (!isControlKey(keyEvent->key()))
            {
                // Merken des Textfeldes. Das Objekt 'absender' in 'QLineEdit' konvertieren
                QLineEdit* tf = static_cast<QLineEdit*>(absender);

                // Eventuell selektierten Text im Textfeld vorher löschen
                if (tf->hasSelectedText())
                {
                    // Selektierter Text wird ueberschrieben
                    tf->insert("");
                }

                // Plausibilitätsprüfung: 'isDigit' => Nur Ziffern 0 bis 9
                if (!QChar(keyEvent->key()).isDigit())
                {
                    // Fehlersignal aussenden
                    QApplication::beep();
                    return true;
                }
                // Wert soll nicht groesser als 9999 sein.
                if (convertTextFieldToValue(tf, QChar(keyEvent->key())) > 9999)
                {
                    // Fehlersignal aussenden
                    QApplication::beep();
                    return true;
                }
            }
        }
    }


    if (absender == ui->tableView)
        {
            if (event->type() == QEvent::KeyPress)
            {
                QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

                if (keyEvent->key() == Qt::Key_Home)
                {
                    ui->tableView->scrollToTop();
                    ui->tableView->selectRow(0);
                }
                else if (keyEvent->key()== Qt::Key_End)
                {
                    ui->tableView->scrollToBottom();
                    ui->tableView->selectRow(ui->tableView->model()->rowCount() - 1);
                }
                else if (keyEvent->key() == Qt::Key_Return)
                {
                    // Den Index der selektierten Zeile ermitteln
                    on_tableView_doubleClicked(ui->tableView->currentIndex());
                }
                else if (keyEvent->key() == Qt::Key_Delete)
                    deleteEntry(ui->tableView->currentIndex());
            }
        }

    // Event am alle anderen Widgets weiterleiten, falls das Ereignes (event) nicht abgefangt wird
    return QObject::eventFilter(absender, event);
}

bool MainWindow::isControlKey(int key)
{
    return (key >= 16'777'216);
}

int MainWindow::convertTextFieldToValue(QLineEdit *tf, QChar keyCharacter)
{
    int charPos = tf->cursorPosition();

    QString s = tf->text().mid(0, charPos) + keyCharacter + tf->text().mid(charPos);

    return s.toInt();
}

void MainWindow::findItemInTableView(const QString &columnName, const QVariant &value)
{
    int row;
    bool found = false;

    // Konvertieren des Datenmodells in ein QSqlTableModel
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableView->model());

    // Auf die Datensätze innerhalb des Datenmodells zugreifen
    QSqlQuery query = model->query();

    // Spaltenindex des Spaltennames über das Datenmodell ermitteln
    int colIndex = model->record().indexOf(columnName);
    if (colIndex < 0)
        return;

    // Auf den ersten Eintrag der Query positionieren
    query.first();

    row = query.at();

    do
    {
        if (query.value(colIndex).toString().contains(value.toString(), Qt::CaseInsensitive))
        {
            found = true;
            break;
        }

        row++;

    } while (query.next());

    if (found)
        ui->tableView->selectRow(row);
    else
        ui->tableView->selectRow(0);
}




// Slots:
// Beenden
void MainWindow::on_actionB_eenden_triggered()
{
    close();
}
void MainWindow::on_btnBeenden_clicked()
{
    close();
}

// Suchen
void MainWindow::on_textSuchen_returnPressed()
{
    this->focusNextChild();
}
void MainWindow::on_textSuchen_editingFinished()
{
    mealSearched = ui->textSuchen->text();
    setTableViewModel();
    mealSearched = QString();
}
void MainWindow::on_btnSuchen_clicked()
{
    mealSearched = ui->textSuchen->text();
    setTableViewModel();
    mealSearched = QString();
}

// Neu
void MainWindow::on_btnNeu_clicked()
{
    newMeal(-1);
}
void MainWindow::on_action_Neu_2_triggered()
{
    newMeal(-1);
}

// Einkaufsliste
void MainWindow::on_btnEinkaufsliste_clicked()
{
    shoppingList();
}
void MainWindow::on_actionZur_Einkaufs_liste_triggered()
{
    shoppingList();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    // Das Datenmodell der TableView in eine QSqlTableModel konvertieren
    QSqlQueryModel* model = static_cast<QSqlQueryModel*>(ui->tableView->model());

    showGerichtDetailsDialog(model->record(index.row()).value("PRIMARYKEY").toLongLong());
}

void MainWindow::on_btnGerichtLoeschen_clicked()
{
    deleteEntry(ui->tableView->currentIndex());
    setTableViewModel();
}

// Nach Kategorien anzeigen
void MainWindow::on_btnAlleGerichte_clicked()
{
    category = "";
    setTableViewModel();
}
void MainWindow::on_btnFruehstueck_clicked()
{
    category = "Frühstück";
    setTableViewModel();
}
void MainWindow::on_btnMittag_clicked()
{
    category = "Mittag";
    setTableViewModel();
}
void MainWindow::on_btnAbendbrot_clicked()
{
    category = "Abendbrot";
    setTableViewModel();
}
void MainWindow::on_btnSnack_clicked()
{
    category = "Snack";
    setTableViewModel();
}
void MainWindow::on_btnNachtisch_clicked()
{
    category = "Nachtisch";
    setTableViewModel();
}

// textPersonen
void MainWindow::on_textPersonen_returnPressed()
{
    this->focusNextChild();
}
void MainWindow::on_textPersonen_editingFinished()
{
    ui->textPersonen->text();
}
void MainWindow::on_textPersonen_textChanged(const QString &)
{
    ui->btnZurEinkaufslisteHinzufuegen->setEnabled(true);
}

void MainWindow::updateTableView(const qint64 key)
{
    statusLabel->setText("Einträge werden aktualisiert...");
    QApplication::processEvents();

    setTableViewModel();

    // Den Cursor auf den geänderten Eintrag positionieren
    findItemInTableView("PRIMARYKEY", QVariant(key));
}




