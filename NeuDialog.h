#ifndef NEUDIALOG_H
#define NEUDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <QLineEdit>
#include <QDebug>

namespace Ui {
class NeuDialog;
}

class NeuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NeuDialog(QWidget *parent = nullptr);
    ~NeuDialog();

private slots:
    void on_btnAbbrechen_clicked();

    void on_btnHinzufuegen_clicked();

    void on_textGerichtName_editingFinished();
    void on_textGerichtName_returnPressed();

    void on_textPersonen_editingFinished();
    void on_textPersonen_returnPressed();

    void on_textDauer_editingFinished();
    void on_textDauer_returnPressed();

private:
    Ui::NeuDialog *ui;

    void init();
    QString getGerichtName(const QString& mealName);
    QString getKategorie(const QString& category);
    QString getDauer(const QString& time);
    QString getPersonenZahl(const QString& numberOfPeople);
    void importGerichtIntoDatabase(const QString &mealName, const QString &category, const QString &time, const QString &numberOfPeople);
    bool eventFilter(QObject* absender, QEvent* event) override;
    bool isControlKey(int key);     // Prueft ob es sich bei dem Tastaturcode um Steuertastenhandelt
                                    // z.B. Key_Return, Key_Delete, Key_Home, Key_End, Key_Left etc...
    // #include <QLineEdit>
    int convertTextFieldToValue(QLineEdit* tf, QChar c);

};

#endif // NEUDIALOG_H
