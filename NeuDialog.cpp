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
}

QString NeuDialog::getGerichtName(const QString &mealName)
{

}

QString NeuDialog::getKategorie(const QString &category)
{

}

QString NeuDialog::getDauer(const QString &time)
{

}

QString NeuDialog::getPersonenZahl(const QString &numberOfPeople)
{

}

void NeuDialog::importGerichtIntoDatabase(const QString &mealName, const QString &category, const QString &time, const QString &numberOfPeople)
{

}

bool NeuDialog::eventFilter(QObject *absender, QEvent *event)
{
    // Uns interessiert die Eingabe über die Tastatur
    // Prüfen ob das Ereignis ein Tastendruck ist
    if (event->type() == QEvent::KeyPress)
    {
        // Welche Taste wurde betätigt
        // QEvent in einen QKeyEvent konvertieren
        // #include <QKeyEvent>
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

        // Ist die Adresse des Absender identisch mit den text Feldern
        if (absender == ui->textPersonen || absender == ui->textDauer
                || absender == ui->textMenge_1 || absender == ui->textMenge_2 || absender == ui->textMenge_3 || absender == ui->textMenge_4 || absender == ui->textMenge_5 || absender == ui->textMenge_6 || absender == ui->textMenge_7 || absender == ui->textMenge_8 || absender == ui->textMenge_9 || absender == ui->textMenge_10
                || absender == ui->textMenge_11 || absender == ui->textMenge_12 || absender == ui->textMenge_13 || absender == ui->textMenge_14 || absender == ui->textMenge_15|| absender == ui->textMenge_16 || absender == ui->textMenge_17|| absender == ui->textMenge_18 || absender == ui->textMenge_19 || absender == ui->textMenge_20
                || absender == ui->textMenge_21 || absender == ui->textMenge_22 || absender == ui->textMenge_23 || absender == ui->textMenge_24 || absender == ui->textMenge_25)
        {

            if (!isControlKey(keyEvent->key()))
            {
                // Merken des Textfeldes
                // Das Objekt 'absender' in 'QLineEdit' konvertieren
                // Das Objekt kommt als Zeiger an
                QLineEdit* tf = static_cast<QLineEdit*>(absender);  //'tf' = Textfeld (allgemein)

                // Eventuell selektierten Text im Textfeld vorher löschen
                if (tf->hasSelectedText())
                {
                    // Selektierter Text wird ueberschrieben
                    tf->insert("");
                }

                // Ueber 'qDebug()' können wir uns jetzt die Taste die Gedrückt wurde ausgeben lassen
                // z.B. die Dezomalziffer '1' entspricht '49' im ASCI-Code
                //qDebug() << keyEvent->key();

                // Plausibilitätsprüfung
                // 'isDigit' => Nur Ziffern 0 bis 9
                if (!QChar(keyEvent->key()).isDigit())
                {
                    // Fehlersignal aussenden
                    QApplication::beep();
                    return true;            // Mit 'return true' für den 'eventFilter'
                                            // heißt ich habe das Zeichen abgefangen
                                            // und es wird nicht an das Textfeld weitergeleitet
                                            // und es wird abgebrochen
                }
                // Es handelt sich um eine Ziffer, aber wenn ich die Ziffer durchlasse,
                // Entsteht dann ein Wert > 255
                // ( Rückgabewert                                     )
                if (convertTextFieldToValue(tf, QChar(keyEvent->key())) > 9999)
                {
                    // Fehlersignal aussenden
                    QApplication::beep();
                    return true;            // Mit 'return true' für den 'eventFilter'
                                            // heißt ich habe das Zeichen abgefangen
                                            // und es wird nicht an das Textfeld weitergeleitet
                                            // und es wird abgebrochen
                }


            }

        }

    }

    // Event weiterleiten, wenn wir das Ereignes (event) nicht abfangen
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
    // 'tf' = textfeld
    // 'mid' = ich hole mir ab der ersten Position der Zeichenkette bis zur Curserposition,
    // hole ich mir die Zeichenkette raus
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
    importGerichtIntoDatabase();
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

//




