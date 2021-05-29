#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DAOLib.h"
#include "GerichteDAO.h"

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

void MainWindow::showTable()
{
//    // Ein TableModel als Datenquelle für die tableView verwenden
//    QSqlTableModel* model = setTableViewModel();

//    // Schriftgrösse der Spaltenüberschriften etwas größer setzen
//    QFont font = ui->tableView->horizontalHeader()->font();
//    font.setPixelSize(14);
//    ui->tableView->horizontalHeader()->setFont(font);

//    // Schriftfarbe der Spaltenüberschriften ändern
//    ui->tableView->horizontalHeader()->setStyleSheet("color: blue;");

//    // Hintergrundfarbe der Spaltenüberschriften ändern
//    ui->tableView->setStyleSheet("QHeaderView::section {background-color: lightgrey;}");

//    // Alle Spaltenüberschriften linksbündig
//    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);


//    // Spalte PRIMARYKEY unsichtbar machen
//    ui->tableView->hideColumn(model->record().indexOf("PRIMARYKEY"));
//    // Spalte TIMESTAMP unsichtbar machen
//    ui->tableView->hideColumn(model->record().indexOf("TIMESTAMP"));

//    // Die letzte Spalte (ORT) nimmt die gesamte restliche Breite der TableView ein
//    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Erste Zeile in der TableView auswählen
//    if (model->rowCount() > 0)
//        ui->tableView->selectRow(0);

}

QSqlTableModel *MainWindow::setTableViewModel()
{

//    // Ein evtl. bereits vorhandenes Datenmodell löschen
//    delete ui->tableView->model();

//    QSqlTableModel* model = GerichteDAO::readGerichteIntoTableModel();

//    // Aufsteigende Sortierung nach Postleitzahl
//    model->sort(model->record().indexOf("PLZ"), Qt::SortOrder::AscendingOrder);

//    // Spaltenüberschriften der Tabelle setzen
//    model->setHeaderData(model->record().indexOf("PLZ"), Qt::Horizontal, "Postleitzahl");
//    model->setHeaderData(model->record().indexOf("ORT"), Qt::Horizontal, "Ort");

//    // Das Datenmodell zuweisen
//    ui->tableView->setModel(model);

//    // Die TableView liest initial nur die ersten 256 Datensätze.
//    // Das ist in der TableView festgelegt.

//    // Wenn aber von Anfang an alle Datensätze benötigt werden, kann man
//    // mit folgender Anweisung die vollständige Azahl der Datensätze
//    // im Datenmodell ermitteln.
//    while(model->canFetchMore())
//        model->fetchMore();


//    // Das Signal selectionChanged mit dem Slot tableView_slectionChanged verbinden.
//    // Über diesen Slot wird die aktuelle Zeilennummer von allen Zeilen in der TableView
//    // in der Statusbar angezeigt.
//    // Der eigene Slot tableView_selectionChanged() benötigt die beiden Argumente QItemSelection,
//    // welche vom Signal gesendet werden nicht. Deshalb werden sie auch nicht an den Slot
//    // weitergegeben.
//    connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
//                        this, SLOT(tableView_selectionChanged()));

//    return model;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Datenbank Schliessen
    DAOLib::closeConnection();
}

void MainWindow::newMeal()
{   
    // Erstellen eines nicht-modalen Dialogs
    // Nicht-modale Dialoge können nur auf dem Heap erstellt weden.
    if (newMealDlg == nullptr)
    {
        // Dialog erstellen
        newMealDlg = new NeuDialog(this);
        // Dialog anzeigen
        newMealDlg->show();
    }
    else if (newMealDlg != nullptr)
    {
        // Dialog wieder anzeigen
        newMealDlg->show();
        // Dialog aktivieren
        newMealDlg->activateWindow();
    }
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




// Slots:
void MainWindow::on_actionB_eenden_triggered()
{
    close();
}


// textSuchen
void MainWindow::on_textSuchen_returnPressed()
{
    this->focusNextChild();
}
void MainWindow::on_textSuchen_editingFinished()
{

}



void MainWindow::on_btnNeu_clicked()
{
    newMeal();
}
void MainWindow::on_action_Neu_2_triggered()
{
    newMeal();
}

void MainWindow::on_btnEinkaufsliste_clicked()
{
    shoppingList();
}
void MainWindow::on_actionZur_Einkaufs_liste_triggered()
{
    shoppingList();
}

