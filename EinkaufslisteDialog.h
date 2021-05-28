#ifndef EINKAUFSLISTEDIALOG_H
#define EINKAUFSLISTEDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>


namespace Ui {
class EinkaufslisteDialog;
}

class EinkaufslisteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EinkaufslisteDialog(QWidget *parent = nullptr);
    ~EinkaufslisteDialog();

private slots:
    void on_btnAbbrechen_2_clicked();
    void on_btnDokumentErstellen_clicked();
    void on_btnListeLeeren_clicked();

private:
    Ui::EinkaufslisteDialog *ui;
    QString actFile;

    void init();

    void openFile();
    void readFile(const QString& filename);
};

#endif // EINKAUFSLISTEDIALOG_H
