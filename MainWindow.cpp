#include "MainWindow.h"
#include "ui_MainWindow.h"

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

