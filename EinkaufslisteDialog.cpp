#include "EinkaufslisteDialog.h"
#include "ui_EinkaufslisteDialog.h"

EinkaufslisteDialog::EinkaufslisteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EinkaufslisteDialog)
{
    ui->setupUi(this);
}

EinkaufslisteDialog::~EinkaufslisteDialog()
{
    delete ui;
}
