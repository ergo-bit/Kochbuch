#include "NeuDialog.h"
#include "ui_NeuDialog.h"

NeuDialog::NeuDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NeuDialog)
{
    ui->setupUi(this);

    init();
}

NeuDialog::~NeuDialog()
{
    delete ui;
}


// private Methoden:
void NeuDialog::init()
{
    // Installation des eventFilters fuer die zu ueberwachenden Textfelder
    //'this' = QMainWindow = QObject -> es wird in meiner eigenen Klasse geprüft, ob die Mehtode verwendet wird
    ui->textPersonen->installEventFilter(this);
    ui->textDauer->installEventFilter(this);

    ui->textMenge_1->installEventFilter(this);
    ui->textMenge_2->installEventFilter(this);
    ui->textMenge_3->installEventFilter(this);
    ui->textMenge_4->installEventFilter(this);
    ui->textMenge_5->installEventFilter(this);
    ui->textMenge_6->installEventFilter(this);
    ui->textMenge_7->installEventFilter(this);
    ui->textMenge_8->installEventFilter(this);
    ui->textMenge_9->installEventFilter(this);
    ui->textMenge_10->installEventFilter(this);
    ui->textMenge_11->installEventFilter(this);
    ui->textMenge_12->installEventFilter(this);
    ui->textMenge_13->installEventFilter(this);
    ui->textMenge_14->installEventFilter(this);
    ui->textMenge_15->installEventFilter(this);
    ui->textMenge_16->installEventFilter(this);
    ui->textMenge_17->installEventFilter(this);
    ui->textMenge_18->installEventFilter(this);
    ui->textMenge_19->installEventFilter(this);
    ui->textMenge_20->installEventFilter(this);
    ui->textMenge_21->installEventFilter(this);
    ui->textMenge_22->installEventFilter(this);
    ui->textMenge_23->installEventFilter(this);
    ui->textMenge_24->installEventFilter(this);
    ui->textMenge_25->installEventFilter(this);

    setIngredientEnable();

    // den RadioButton per default auf 'Frühstück' setzen
    ui->rbFruehstueck->setChecked(true);
    category = QString("Frühstück");
}

void NeuDialog::setIngredientEnable()
{
    // Menge, Einheit, Zutaten-Spalten auswaehlbar setzen
    ui->textMenge_2->setEnabled(ui->textKomponente_1->text().length() > 0);
    ui->textEinheit_2->setEnabled(ui->textKomponente_1->text().length() > 0);
    ui->textKomponente_2->setEnabled(ui->textKomponente_1->text().length() > 0);

    ui->textMenge_3->setEnabled(ui->textKomponente_2->text().length() > 0);
    ui->textEinheit_3->setEnabled(ui->textMenge_3->isEnabled());
    ui->textKomponente_3->setEnabled(ui->textEinheit_3->isEnabled());

    ui->textMenge_4->setEnabled(ui->textKomponente_3->text().length() > 0);
    ui->textEinheit_4->setEnabled(ui->textMenge_4->isEnabled());
    ui->textKomponente_4->setEnabled(ui->textEinheit_4->isEnabled());

    ui->textMenge_5->setEnabled(ui->textKomponente_4->text().length() > 0);
    ui->textEinheit_5->setEnabled(ui->textMenge_5->isEnabled());
    ui->textKomponente_5->setEnabled(ui->textEinheit_5->isEnabled());

    ui->textMenge_6->setEnabled(ui->textKomponente_5->text().length() > 0);
    ui->textEinheit_6->setEnabled(ui->textMenge_6->isEnabled());
    ui->textKomponente_6->setEnabled(ui->textEinheit_6->isEnabled());

    ui->textMenge_7->setEnabled(ui->textKomponente_6->text().length() > 0);
    ui->textEinheit_7->setEnabled(ui->textMenge_7->isEnabled());
    ui->textKomponente_7->setEnabled(ui->textEinheit_7->isEnabled());

    ui->textMenge_8->setEnabled(ui->textKomponente_7->text().length() > 0);
    ui->textEinheit_8->setEnabled(ui->textMenge_8->isEnabled());
    ui->textKomponente_8->setEnabled(ui->textEinheit_8->isEnabled());

    ui->textMenge_9->setEnabled(ui->textKomponente_8->text().length() > 0);
    ui->textEinheit_9->setEnabled(ui->textMenge_9->isEnabled());
    ui->textKomponente_9->setEnabled(ui->textEinheit_9->isEnabled());

    ui->textMenge_10->setEnabled(ui->textKomponente_9->text().length() > 0);
    ui->textEinheit_10->setEnabled(ui->textMenge_10->isEnabled());
    ui->textKomponente_10->setEnabled(ui->textEinheit_10->isEnabled());

    ui->textMenge_11->setEnabled(ui->textKomponente_10->text().length() > 0);
    ui->textEinheit_11->setEnabled(ui->textMenge_11->isEnabled());
    ui->textKomponente_11->setEnabled(ui->textEinheit_11->isEnabled());

    ui->textMenge_12->setEnabled(ui->textKomponente_11->text().length() > 0);
    ui->textEinheit_12->setEnabled(ui->textMenge_12->isEnabled());
    ui->textKomponente_12->setEnabled(ui->textEinheit_12->isEnabled());

    ui->textMenge_13->setEnabled(ui->textKomponente_12->text().length() > 0);
    ui->textEinheit_13->setEnabled(ui->textMenge_13->isEnabled());
    ui->textKomponente_13->setEnabled(ui->textEinheit_13->isEnabled());

    ui->textMenge_14->setEnabled(ui->textKomponente_13->text().length() > 0);
    ui->textEinheit_14->setEnabled(ui->textMenge_14->isEnabled());
    ui->textKomponente_14->setEnabled(ui->textEinheit_14->isEnabled());

    ui->textMenge_15->setEnabled(ui->textKomponente_14->text().length() > 0);
    ui->textEinheit_15->setEnabled(ui->textMenge_15->isEnabled());
    ui->textKomponente_15->setEnabled(ui->textEinheit_15->isEnabled());

    ui->textMenge_16->setEnabled(ui->textKomponente_15->text().length() > 0);
    ui->textEinheit_16->setEnabled(ui->textMenge_16->isEnabled());
    ui->textKomponente_16->setEnabled(ui->textEinheit_16->isEnabled());

    ui->textMenge_17->setEnabled(ui->textKomponente_16->text().length() > 0);
    ui->textEinheit_17->setEnabled(ui->textMenge_17->isEnabled());
    ui->textKomponente_17->setEnabled(ui->textEinheit_17->isEnabled());

    ui->textMenge_18->setEnabled(ui->textKomponente_17->text().length() > 0);
    ui->textEinheit_18->setEnabled(ui->textMenge_18->isEnabled());
    ui->textKomponente_18->setEnabled(ui->textEinheit_18->isEnabled());

    ui->textMenge_19->setEnabled(ui->textKomponente_18->text().length() > 0);
    ui->textEinheit_19->setEnabled(ui->textMenge_19->isEnabled());
    ui->textKomponente_19->setEnabled(ui->textEinheit_19->isEnabled());

    ui->textMenge_20->setEnabled(ui->textKomponente_19->text().length() > 0);
    ui->textEinheit_20->setEnabled(ui->textMenge_20->isEnabled());
    ui->textKomponente_20->setEnabled(ui->textEinheit_20->isEnabled());

    ui->textMenge_21->setEnabled(ui->textKomponente_20->text().length() > 0);
    ui->textEinheit_21->setEnabled(ui->textMenge_21->isEnabled());
    ui->textKomponente_21->setEnabled(ui->textEinheit_21->isEnabled());

    ui->textMenge_22->setEnabled(ui->textKomponente_21->text().length() > 0);
    ui->textEinheit_22->setEnabled(ui->textMenge_22->isEnabled());
    ui->textKomponente_22->setEnabled(ui->textEinheit_22->isEnabled());

    ui->textMenge_23->setEnabled(ui->textKomponente_22->text().length() > 0);
    ui->textEinheit_23->setEnabled(ui->textMenge_23->isEnabled());
    ui->textKomponente_23->setEnabled(ui->textEinheit_23->isEnabled());

    ui->textMenge_24->setEnabled(ui->textKomponente_23->text().length() > 0);
    ui->textEinheit_24->setEnabled(ui->textMenge_24->isEnabled());
    ui->textKomponente_24->setEnabled(ui->textEinheit_24->isEnabled());

    ui->textMenge_25->setEnabled(ui->textKomponente_24->text().length() > 0);
    ui->textEinheit_25->setEnabled(ui->textMenge_25->isEnabled());
    ui->textKomponente_25->setEnabled(ui->textEinheit_25->isEnabled());
}

bool NeuDialog::eventFilter(QObject *absender, QEvent *event)
{
    // Uns interessiert die Eingabe über die Tastatur prüfen ob das Ereignis ein Tastendruck ist
    if (event->type() == QEvent::KeyPress)
    {
        // Welche Taste wurde betätigt
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

        // Ist die Adresse des Absender identisch mit den text Feldern
        if (absender == ui->textPersonen || absender == ui->textDauer
                || absender == ui->textMenge_1 || absender == ui->textMenge_2 || absender == ui->textMenge_3 || absender == ui->textMenge_4 || absender == ui->textMenge_5 || absender == ui->textMenge_6 || absender == ui->textMenge_7 || absender == ui->textMenge_8 || absender == ui->textMenge_9 || absender == ui->textMenge_10
                || absender == ui->textMenge_11 || absender == ui->textMenge_12 || absender == ui->textMenge_13 || absender == ui->textMenge_14 || absender == ui->textMenge_15|| absender == ui->textMenge_16 || absender == ui->textMenge_17|| absender == ui->textMenge_18 || absender == ui->textMenge_19 || absender == ui->textMenge_20
                || absender == ui->textMenge_21 || absender == ui->textMenge_22 || absender == ui->textMenge_23 || absender == ui->textMenge_24 || absender == ui->textMenge_25)
        {

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
    // Event weiterleiten, falls das Ereignes (event) nicht abgefangt wird
    return QObject::eventFilter(absender, event);
}

bool NeuDialog::isControlKey(int key)
{
    // In der Dokumentation ist die Enumeration Qt::Key aufgeführt:
    //
    //
    // Die Steuertasten beginnen mit dem Hex-Wert: 0x0100 0000 = 16'777'216
    // Alle anderen Tasten beginnen bei: 0x0000 0020 = 32
    // Deshalb koennen alle Steuertasten mit einer Anweisung abgefangen werden
    return (key >= 16'777'216);
}

int NeuDialog::convertTextFieldToValue(QLineEdit *tf, QChar keyCharacter)
{
    // Position an der Das Zeichen eingefügt wurde abfragen/ermitteln
    int charPos = tf->cursorPosition();

    // 'keyCharacter' ist das Zeichen, welches noch auf dem Weg in das Textfeld ist
    // mit 'mid()' hole ich mir die Zeichenkette ab der ersten Position bis zur Curserposition
    QString s = tf->text().mid(0, charPos) + keyCharacter + tf->text().mid(charPos);
    // Konvertierung geling garantiert, das im Textfeld nur noch Ziffern eingeben werden können
    return s.toInt();
}




// Slots:
void NeuDialog::on_btnAbbrechen_clicked()
{
    close();
}

void NeuDialog::on_btnHinzufuegen_clicked()
{
    // fuer die GerichteDAO:
    QString mealName = QString(ui->textGerichtName->text());
    QString duration = QString(ui->textDauer->text());
    QString numberOfPeople = QString(ui->textPersonen->text());
    QString preparation = ui->textAnleitung->toPlainText();

    //fuer die ZutatenDAO:
    int value = ui->textMenge_1->text().toInt();
    value = value/(numberOfPeople.toInt());         // Menge auf die Personen gerechnet
    QString amount = QString::number(value);
    QString unit = QString(ui->textEinheit_1->text());
    QString ingredient = QString(ui->textKomponente_1->text());

    if (mealName.length() > 0 && numberOfPeople.length() > 0)
    {
        if (GerichteDAO::checkIfNewMealIsOccupied(mealName))
        {
            int msgValue = QMessageBox::information(this, this->windowTitle(),
                                                    "Es ist bereits ein Gericht mit dem Namen: '" + mealName + "' vergeben.\n Klicke auf 'Abbrechen' um das neue Gericht umzubenennen.",
                                                    QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Cancel);
            if (msgValue == QMessageBox::Cancel)
                return;
        }
        else if (!GerichteDAO::checkIfNewMealIsOccupied(mealName))
        {
            GerichteDAO::insertNewMealIntoGerichte(mealName, category, duration, numberOfPeople, preparation);
            ZutatenDAO::insertNewMealIntoZutaten(mealName, amount, unit, ingredient);
        }
    }

    // Nach dem Hinzufügen schliessen
    close();

}

// textGericht
void NeuDialog::on_textGerichtName_editingFinished()
{
    ui->textGerichtName->text();
}
void NeuDialog::on_textGerichtName_returnPressed()
{
    this->focusNextChild();
}

// textPersonen
void NeuDialog::on_textPersonen_editingFinished()
{
    ui->textPersonen->text();
}
void NeuDialog::on_textPersonen_returnPressed()
{
    this->focusNextChild();
}

// textDauer
void NeuDialog::on_textDauer_editingFinished()
{
    ui->textDauer->text();
}
void NeuDialog::on_textDauer_returnPressed()
{
    this->focusNextChild();
}

// RadioBoxen der Kategorien
void NeuDialog::on_rbFruehstueck_clicked()
{
    category = QString("Frühstück");
}
void NeuDialog::on_rbMittag_clicked()
{
    category = QString("Mittag");
}
void NeuDialog::on_rbAbendbrot_clicked()
{
    category = QString("Abendbrot");
}
void NeuDialog::on_rbSnack_clicked()
{
    category = QString("Snack");
}
void NeuDialog::on_rbNachtisch_clicked()
{
    category = QString("Nachtisch");
}

// Zutaten
void NeuDialog::on_textKomponente_1_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_1_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_2_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_2_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_3_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_3_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_4_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_4_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_5_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_5_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_6_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_6_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_7_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_7_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_8_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_8_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_9_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_9_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_10_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_10_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_11_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_11_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_12_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_12_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_13_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_13_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_14_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_14_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_15_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_15_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_16_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_16_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_17_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_17_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_18_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_18_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_19_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_19_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_20_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_20_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_21_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_21_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_22_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_22_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_23_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_23_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_24_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_24_textChanged(const QString &)
{
    setIngredientEnable();
}

void NeuDialog::on_textKomponente_25_returnPressed()
{
    this->focusNextChild();
}
void NeuDialog::on_textKomponente_25_textChanged(const QString &)
{
    setIngredientEnable();
}

