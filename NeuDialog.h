#ifndef NEUDIALOG_H
#define NEUDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <QLineEdit>
#include <QDebug>
#include <QTextEdit>

#include "GerichteDAO.h"
#include "ZutatenDAO.h"

namespace Ui {
class NeuDialog;
}

class NeuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NeuDialog(QWidget *parent = nullptr);
    ~NeuDialog();

signals:
    void refreshData(const qint64 key);

private slots:
    void on_btnAbbrechen_clicked();

    void on_btnHinzufuegen_clicked();

    void on_textGerichtName_editingFinished();
    void on_textGerichtName_returnPressed();

    void on_textPersonen_editingFinished();
    void on_textPersonen_returnPressed();

    void on_textDauer_editingFinished();
    void on_textDauer_returnPressed();

    void on_rbFruehstueck_clicked();
    void on_rbMittag_clicked();
    void on_rbAbendbrot_clicked();
    void on_rbSnack_clicked();
    void on_rbNachtisch_clicked();

    void on_textKomponente_1_returnPressed();
    void on_textKomponente_1_textChanged(const QString &arg1);
    void on_textKomponente_2_returnPressed();
    void on_textKomponente_2_textChanged(const QString &arg1);
    void on_textKomponente_3_returnPressed();
    void on_textKomponente_3_textChanged(const QString &arg1);
    void on_textKomponente_4_returnPressed();
    void on_textKomponente_4_textChanged(const QString &arg1);
    void on_textKomponente_5_returnPressed();
    void on_textKomponente_5_textChanged(const QString &arg1);
    void on_textKomponente_6_returnPressed();
    void on_textKomponente_6_textChanged(const QString &arg1);
    void on_textKomponente_7_returnPressed();
    void on_textKomponente_7_textChanged(const QString &arg1);
    void on_textKomponente_8_returnPressed();
    void on_textKomponente_8_textChanged(const QString &arg1);
    void on_textKomponente_9_returnPressed();
    void on_textKomponente_9_textChanged(const QString &arg1);
    void on_textKomponente_10_returnPressed();
    void on_textKomponente_10_textChanged(const QString &arg1);
    void on_textKomponente_11_returnPressed();
    void on_textKomponente_11_textChanged(const QString &arg1);
    void on_textKomponente_12_returnPressed();
    void on_textKomponente_12_textChanged(const QString &arg1);
    void on_textKomponente_13_returnPressed();
    void on_textKomponente_13_textChanged(const QString &arg1);
    void on_textKomponente_14_returnPressed();
    void on_textKomponente_14_textChanged(const QString &arg1);
    void on_textKomponente_15_returnPressed();
    void on_textKomponente_15_textChanged(const QString &arg1);
    void on_textKomponente_16_returnPressed();
    void on_textKomponente_16_textChanged(const QString &arg1);
    void on_textKomponente_17_returnPressed();
    void on_textKomponente_17_textChanged(const QString &arg1);
    void on_textKomponente_18_returnPressed();
    void on_textKomponente_18_textChanged(const QString &arg1);
    void on_textKomponente_19_returnPressed();
    void on_textKomponente_19_textChanged(const QString &arg1);
    void on_textKomponente_20_returnPressed();
    void on_textKomponente_20_textChanged(const QString &arg1);
    void on_textKomponente_21_returnPressed();
    void on_textKomponente_21_textChanged(const QString &arg1);
    void on_textKomponente_22_returnPressed();
    void on_textKomponente_22_textChanged(const QString &arg1);
    void on_textKomponente_23_returnPressed();
    void on_textKomponente_23_textChanged(const QString &arg1);
    void on_textKomponente_24_returnPressed();
    void on_textKomponente_24_textChanged(const QString &arg1);
    void on_textKomponente_25_returnPressed();
    void on_textKomponente_25_textChanged(const QString &arg1);

private:
    Ui::NeuDialog *ui;
    QString category = QString("");

    void init();

    void setIngredientEnable();

    bool eventFilter(QObject* absender, QEvent* event) override;
    bool isControlKey(int key);     // Prueft ob es sich bei dem Tastaturcode um Steuertastenhandelt (z.B. Key_Return, Key_Delete, Key_Home, Key_End, Key_Left etc...)
    int convertTextFieldToValue(QLineEdit* tf, QChar keyCharacter);  // #include <QLineEdit>

};

#endif // NEUDIALOG_H
