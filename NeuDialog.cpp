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

}

bool NeuDialog::eventFilter(QObject *absender, QEvent *event)
{
//    // Uns interessiert die Eingabe über die Tastatur
//    // Prüfen ob das Ereignis ein Tastendruck ist
//    if (event->type() == QEvent::KeyPress)
//    {
//        // Welche Taste wurde betätigt
//        // QEvent in einen QKeyEvent konvertieren
//        // #include <QKeyEvent>
//        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

//        // Ist die Adresse des Absender identisch mit dem 'TextDezRot'
//        if (absender == ui->textDezRot || absender == ui->textDezGruen || absender == ui->textDezBlau)
//        {

//            if (!isControlKey(keyEvent->key()))
//            {
//                // Merken des Textfeldes
//                // Das Objekt 'absender' in 'QLineEdit' konvertieren
//                // Das Objekt kommt als Zeiger an
//                QLineEdit* tf = static_cast<QLineEdit*>(absender);  //'tf' = Textfeld (Rot, Gruen oder Blau)

//                // Eventuell selektierten Text im Textfeld vorher löschen
//                if (tf->hasSelectedText())
//                {
//                    // Selektierter Text wird ueberschrieben
//                    tf->insert("");
//                }

//                // Ueber 'qDebug()' können wir uns jetzt die Taste die Gedrückt wurde ausgeben lassen
//                // z.B. die Dezomalziffer '1' entspricht '49' im ASCI-Code
//                //qDebug() << keyEvent->key();

//                // Plausibilitätsprüfung
//                // 'isDigit' => Nur Ziffern 0 bis 9
//                if (!QChar(keyEvent->key()).isDigit())
//                {
//                    // Fehlersignal aussenden
//                    QApplication::beep();
//                    return true;            // Mit 'return true' für den 'eventFilter'
//                                            // heißt ich habe das Zeichen abgefangen
//                                            // und es wird nicht an das Textfeld weitergeleitet
//                                            // und es wird abgebrochen
//                }
//                // Es handelt sich um eine Ziffer, aber wenn ich die Ziffer durchlasse,
//                // Entsteht dann ein Wert > 255
//                // ( Rückgabewert                                     )
//                if (convertTextFieldToValue(tf, QChar(keyEvent->key())) > COLOR_MAX)
//                {
//                    // Fehlersignal aussenden
//                    QApplication::beep();
//                    return true;            // Mit 'return true' für den 'eventFilter'
//                                            // heißt ich habe das Zeichen abgefangen
//                                            // und es wird nicht an das Textfeld weitergeleitet
//                                            // und es wird abgebrochen
//                }


//            }

//        }

//    }

//    // Event weiterleiten, wenn wir das Ereignes (event) nicht abfangen
//    return QObject::eventFilter(absender, event);
}


// Slots:
void NeuDialog::on_btnAbbrechen_clicked()
{
    close();
}



