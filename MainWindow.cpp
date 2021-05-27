#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DAOLib.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
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
//    enableDatabase(openDatabase("DESKTOP-PNDMIUO\\SQLEXPRESS",       // localhost ist letzlich die flexible Angabe der IP-Adresse
//                                "dueck"));                           // Name der Datenbank

}

//void MainWindow::enableDatabase(bool bEnable)
//{
//    // Menüeinträge aktivieren mit 'enableDatabase'
//    ui->menuStammdaten->setEnabled(bEnable);
//    ui->menu_Extras->setEnabled(bEnable);

//    if (bEnable)
//    {
//        statusLabel->setText("Datenbank: " + DAOLib::getDatabaseName());
//    }
//    else
//    {
//        statusLabel->setText("Datenbank: (keine)");
//    }

//}

//bool MainWindow::openDatabase(const QString &server, const QString &databaseN)
//{
//    QString driver = "QODBC";                        // 'QODBC' = open database connectivity
//    QString driverName = "DRIVER={SQL Server}";

//    // öffnen der Datenbank
//    // #include "DAOLib.h"
//    return DAOLib::connectToDatabase(driver, driverName, server, databaseN);
//}

//void MainWindow::closeEvent(QCloseEvent *)
//{
//    // Datenbank Schliessen
//    DAOLib::closeConnection();
//}

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
void MainWindow::on_textSuchen_returnPressed()
{
    this->focusNextChild();
}

void MainWindow::on_textSuchen_editingFinished()
{
    //setSchriftSize();
}

void MainWindow::on_actionB_eenden_triggered()
{
    close();
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

