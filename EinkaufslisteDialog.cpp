#include "EinkaufslisteDialog.h"
#include "ui_EinkaufslisteDialog.h"

EinkaufslisteDialog::EinkaufslisteDialog(QWidget *parent) : QDialog(parent), ui(new Ui::EinkaufslisteDialog)
{
    ui->setupUi(this);

    init();
}

EinkaufslisteDialog::~EinkaufslisteDialog()
{
    delete ui;
}



// private Methoden:
void EinkaufslisteDialog::init()
{
    // Mit öffnen des Dialogs auch 'aktListe' öffen
    openFile();
}

void EinkaufslisteDialog::openFile()
{
//    QString actDir;
//    QString defaultFilter = tr("Textdokumente (*.txt)");

//    // Gibt das Heimatverzeichnis des benutzers zurück.
//    QDir("C:/Users/vikto/Desktop/C++_Qt-Entwickler/Qt_alfatraining/Student/Projekt/Kochbuch/aktListe.txt");

//    QString filename = QFileDialog::getOpenFileName(this, tr("Textdokument öffnen"), actDir,
//                                 tr("Alle Dateien (*.*);;") + defaultFilter,
//                                 &defaultFilter);

//    if (!filename.isEmpty())
//        readFile(filename);
}

void EinkaufslisteDialog::readFile(const QString &filename)
{
//    // Öffnen der Datei
//    QFile file(filename);
//    if (!file.open(QFile::ReadOnly | QFile::Text))
//    {
//        QMessageBox::critical(this, tr("Datei öffnen"),
//                              QString(tr("Die Datei konnte nicht geöffnet werden %1:\n%2")).
//                                    arg(filename).
//                                    arg(file.errorString()));
//        return;
//    }

//    // Übergabe des Dateinamens an einen TextStream
//    QTextStream inStream(&file);

//    ui->textEdit->setPlainText(inStream.readAll());

//    file.close();

//    // Den Namen der aktuellen Datei sichern
//    actFile = filename;
}



// Slots:
void EinkaufslisteDialog::on_btnAbbrechen_2_clicked()
{
    close();
}

void EinkaufslisteDialog::on_btnDokumentErstellen_clicked()
{

}

void EinkaufslisteDialog::on_btnListeLeeren_clicked()
{

}

