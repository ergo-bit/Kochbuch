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

    ui->btnSpeichern->setEnabled(false);
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

    mealName = QString(ui->textGerichtName->text());

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

    // Änderungen verwerfen
    if (msgValue == QMessageBox::Discard)
        retValue = true;
    // Abbrechen
    else if (msgValue == QMessageBox::Cancel)
        retValue = false;
    // Speichern
    else
        retValue = saveEntry();

    return retValue;
}

bool GerichtDetailsDialog::saveEntry()
{
    bool retValue = false;

    if (!entryIsValid())
        return retValue;

    retValue = updateEntry(dlgKey);

    if (retValue)
        emit refreshData(dlgKey);

    // Modified Flag setzen
    isModified = !retValue;
    return retValue;
}

bool GerichtDetailsDialog::entryIsValid()
{
    bool retValue = true;

        if (ui->textGerichtName->text().length() == 0)
        {
            QMessageBox::critical(this, this->windowTitle(), "Ein Name für das Gericht fehlt.");
            ui->textGerichtName->setFocus();
            retValue = false;
        }
        else if (ui->textPersonen->text().length() == 0)
        {
            QMessageBox::critical(this, this->windowTitle(), "Eine Angabe zu Personenzahl fehlt.");
            ui->textPersonen->setFocus();
            retValue = false;
        }
        else if (GerichteDAO::GerichtExists(ui->textGerichtName->text()))
        {
            QMessageBox::critical(this, this->windowTitle(), "Gericht ist bereits vorhanden");
            ui->textGerichtName->setFocus();
            retValue = false;
        }

        return retValue;
}

bool GerichtDetailsDialog::updateEntry(qint64 key)
{
    bool retValue = false;
    // Vor dem Update prüfen, ob der TimeStamp des Datensatzes
        // in der Zwischenzeit durch einen anderen Benutzer geändert wurde.
        Gericht* meal = GerichteDAO::readGericht(key);
        if (meal == nullptr)
            return false;


//        QString currentTimeStamp = meal->getTimeStamp();

        // Objekt meal vom Heap löschen
        delete meal;

//        if (timeStamp != currentTimeStamp)
//        {
//            QMessageBox::warning(this, this->windowTitle(),
//                                 "Dieser Eintrag wurde in der Zwischenzeit von einen anderen Benutzer geändert");

//            return true;
//        }

        ZutatenDAO::updateZutat(ui->textGerichtName->text(), mealName);
        retValue = GerichteDAO::updateGericht(key, ui->textGerichtName->text(), category ,ui->textDauer->text(), ui->textPersonen->text());

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

void GerichtDetailsDialog::on_btnSpeichern_clicked()
{
    if (isModified)
    {
        if (!saveEntry())
            return;
    }

    close();
}

// RadioBoxen der Kategorien
void GerichtDetailsDialog::on_rbFruehstueck_clicked()
{
    category = QString("Frühstück");
}
void GerichtDetailsDialog::on_rbMittag_clicked()
{
    category = QString("Mittag");
}
void GerichtDetailsDialog::on_rbAbendbrot_clicked()
{
    category = QString("Abendbrot");
}
void GerichtDetailsDialog::on_rbSnack_clicked()
{
    category = QString("Snack");
}
void GerichtDetailsDialog::on_rbNachtisch_clicked()
{
    category = QString("Nachtisch");
}

// textFelder
void GerichtDetailsDialog::on_textGerichtName_returnPressed()
{
    this->focusNextChild();
}
void GerichtDetailsDialog::on_textGerichtName_textChanged(const QString &)
{
    ui->btnSpeichern->setEnabled(true);
    isModified = true;
}

void GerichtDetailsDialog::on_textPersonen_returnPressed()
{
    this->focusNextChild();
}
void GerichtDetailsDialog::on_textPersonen_textChanged(const QString &)
{
    ui->btnSpeichern->setEnabled(true);
    isModified = true;
}

void GerichtDetailsDialog::on_textAnleitung_textChanged()
{
    ui->btnSpeichern->setEnabled(true);
    isModified = true;
}

void GerichtDetailsDialog::on_textDauer_returnPressed()
{
    this->focusNextChild();
}
void GerichtDetailsDialog::on_textDauer_textChanged(const QString &)
{
    ui->btnSpeichern->setEnabled(true);
    isModified = true;
}

