#ifndef EINKAUFSLISTEDIALOG_H
#define EINKAUFSLISTEDIALOG_H

#include <QDialog>

namespace Ui {
class EinkaufslisteDialog;
}

class EinkaufslisteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EinkaufslisteDialog(QWidget *parent = nullptr);
    ~EinkaufslisteDialog();

private:
    Ui::EinkaufslisteDialog *ui;
};

#endif // EINKAUFSLISTEDIALOG_H
