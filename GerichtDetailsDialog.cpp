#include "GerichtDetailsDialog.h"
#include "ui_GerichtDetailsDialog.h"



GerichtDetailsDialog::GerichtDetailsDialog(qint64 key, QWidget *parent) : QDialog(parent), ui(new Ui::GerichtDetailsDialog)
{
    ui->setupUi(this);

    dlgKey = key;

    init();
}

GerichtDetailsDialog::~GerichtDetailsDialog()
{
    delete ui;
}


// private Methoden:
void GerichtDetailsDialog::init()
{
    isModified = false;

    if (dlgKey > 0)
        readEntry(dlgKey);
}

void GerichtDetailsDialog::readEntry(qint64 key)
{
    // Informationen aus Tabelle 'Gerichte' einlesen
    Gericht* meal = GerichteDAO::readGericht(key);
    if (meal == nullptr)
        return;

    ui->textGerichtName->setText(meal->getGerichtName());
//    ui->textKategorie->setText(category->getKategorie());
    ui->textDauer->setText(meal->getDauer());
    ui->textPersonen->setText(meal->getPersonen());
    ui->textAnleitung->setText(meal->getZubereitung());



    // Informationen aus Tabelle 'Zutaten' einlesen
    Zutat* ingredient = ZutatenDAO::readZutat(key);
    if (ingredient == nullptr)
        return;

    ui->textEinheit_1->setText(ingredient->getEinheit());




    isModified = false;

    // TimeStamp sichern
    timeStamp = meal->getTimeStamp();
    timeStamp = ingredient->getTimeStamp();

    // 'meal' und 'ingredient' vom Heap löschen
    delete meal;
    delete ingredient;
}

// Schliessen des Dialogs über die 'close()'-Fkt
void GerichtDetailsDialog::closeEvent(QCloseEvent *event)
{
    if (querySave())
        event->accept();
    else
        event->ignore();
}
// Schliessen mit der Esc-Taste
void GerichtDetailsDialog::reject()
{
    close();
}

bool GerichtDetailsDialog::querySave()
{
    bool retValue = false;

    if (!isModified)
        return true;

    int msgValue = QMessageBox::question(this, this->windowTitle(),
                                        "Die Daten wurden geändert.\nWollen Sie ihre Änderungen speichern",
                                         QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
                                         QMessageBox::Cancel);

    // Änderungen verwerfen und Dialog schließen
    if (msgValue == QMessageBox::Discard)
        retValue = true;
    // Abbrechen, zurück in den Dialog
    else if (msgValue == QMessageBox::Cancel)
        retValue = false;
    // Speichern, wenn erfolgreich Dialog schließen
    else
        retValue = saveEntry();

    return retValue;
}

bool GerichtDetailsDialog::saveEntry()
{
    bool retValue = false;

//    if (!entryIsValid())
//        return retValue;

//    if (dlgKey > 0)
//        retValue = updateEntry(dlgKey);
//    else
//        retValue = insertEntry();

//    if (retValue)
//        emit refreshData(dlgKey);

    // Modified Flag setzen
    isModified = !retValue;
    return retValue;
}






// Slots:
void GerichtDetailsDialog::on_btnAbbrechen_clicked()
{
    close();
}

void GerichtDetailsDialog::on_btnEtwasAendern_clicked()
{
    ui->textGerichtName->setEnabled(true);
    ui->rbFruehstueck->setEnabled(true);
    ui->rbMittag->setEnabled(true);
    ui->rbAbendbrot->setEnabled(true);
    ui->rbSnack->setEnabled(true);
    ui->rbNachtisch->setEnabled(true);

    ui->textMenge_1->setEnabled(true);
    ui->textEinheit_1->setEnabled(true);
    ui->textKomponente_1->setEnabled(true);

    ui->textMenge_2->setEnabled(true);
    ui->textEinheit_2->setEnabled(true);
    ui->textKomponente_2->setEnabled(true);

    ui->textMenge_3->setEnabled(true);
    ui->textEinheit_3->setEnabled(true);
    ui->textKomponente_3->setEnabled(true);

    ui->textMenge_4->setEnabled(true);
    ui->textEinheit_4->setEnabled(true);
    ui->textKomponente_4->setEnabled(true);

    ui->textMenge_5->setEnabled(true);
    ui->textEinheit_5->setEnabled(true);
    ui->textKomponente_5->setEnabled(true);

    ui->textMenge_6->setEnabled(true);
    ui->textEinheit_6->setEnabled(true);
    ui->textKomponente_6->setEnabled(true);

    ui->textMenge_7->setEnabled(true);
    ui->textEinheit_7->setEnabled(true);
    ui->textKomponente_7->setEnabled(true);

    ui->textMenge_8->setEnabled(true);
    ui->textEinheit_8->setEnabled(true);
    ui->textKomponente_8->setEnabled(true);

    ui->textMenge_9->setEnabled(true);
    ui->textEinheit_9->setEnabled(true);
    ui->textKomponente_9->setEnabled(true);

    ui->textMenge_10->setEnabled(true);
    ui->textEinheit_10->setEnabled(true);
    ui->textKomponente_10->setEnabled(true);

    ui->textMenge_11->setEnabled(true);
    ui->textEinheit_11->setEnabled(true);
    ui->textKomponente_11->setEnabled(true);

    ui->textMenge_12->setEnabled(true);
    ui->textEinheit_12->setEnabled(true);
    ui->textKomponente_12->setEnabled(true);

    ui->textMenge_13->setEnabled(true);
    ui->textEinheit_13->setEnabled(true);
    ui->textKomponente_13->setEnabled(true);

    ui->textMenge_14->setEnabled(true);
    ui->textEinheit_14->setEnabled(true);
    ui->textKomponente_14->setEnabled(true);

    ui->textMenge_15->setEnabled(true);
    ui->textEinheit_15->setEnabled(true);
    ui->textKomponente_15->setEnabled(true);

    ui->textMenge_16->setEnabled(true);
    ui->textEinheit_16->setEnabled(true);
    ui->textKomponente_16->setEnabled(true);

    ui->textMenge_17->setEnabled(true);
    ui->textEinheit_17->setEnabled(true);
    ui->textKomponente_17->setEnabled(true);

    ui->textMenge_18->setEnabled(true);
    ui->textEinheit_18->setEnabled(true);
    ui->textKomponente_18->setEnabled(true);

    ui->textMenge_19->setEnabled(true);
    ui->textEinheit_19->setEnabled(true);
    ui->textKomponente_19->setEnabled(true);

    ui->textMenge_20->setEnabled(true);
    ui->textEinheit_20->setEnabled(true);
    ui->textKomponente_20->setEnabled(true);

    ui->textMenge_21->setEnabled(true);
    ui->textEinheit_21->setEnabled(true);
    ui->textKomponente_21->setEnabled(true);

    ui->textMenge_22->setEnabled(true);
    ui->textEinheit_22->setEnabled(true);
    ui->textKomponente_22->setEnabled(true);

    ui->textMenge_23->setEnabled(true);
    ui->textEinheit_23->setEnabled(true);
    ui->textKomponente_23->setEnabled(true);

    ui->textMenge_24->setEnabled(true);
    ui->textEinheit_24->setEnabled(true);
    ui->textKomponente_24->setEnabled(true);

    ui->textMenge_25->setEnabled(true);
    ui->textEinheit_25->setEnabled(true);
    ui->textKomponente_25->setEnabled(true);

    ui->textDauer->setEnabled(true);
    ui->textPersonen->setEnabled(true);
    ui->textAnleitung->setEnabled(true);
}

