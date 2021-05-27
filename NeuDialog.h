#ifndef NEUDIALOG_H
#define NEUDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <QLineEdit>

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

private:
    Ui::NeuDialog *ui;

    void init();
    bool eventFilter(QObject* absender, QEvent* event) override;
    bool isControlKey(int key);     // Prueft ob es sich bei dem Tastaturcode um Steuertastenhandelt
                                    // z.B. Key_Return, Key_Delete, Key_Home, Key_End, Key_Left etc...
    // #include <QLineEdit>
    int convertTextFieldToValue(QLineEdit* tf, QChar c);
};

#endif // NEUDIALOG_H
