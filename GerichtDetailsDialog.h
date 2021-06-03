#ifndef GERICHTDETAILSDIALOG_H
#define GERICHTDETAILSDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QDebug>

#include "GerichteDAO.h"
#include "Gericht.h"
#include "ZutatenDAO.h"
#include "Zutat.h"

namespace Ui {
class GerichtDetailsDialog;
}

class GerichtDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GerichtDetailsDialog(qint64 key, QWidget *parent = nullptr);
    ~GerichtDetailsDialog();

signals:
    void refreshData(const qint64 key);

private slots:
    void on_btnAbbrechen_clicked();
    void on_btnEtwasAendern_clicked();

private:
    Ui::GerichtDetailsDialog *ui;
    qint64 dlgKey;
    QString timeStamp;
    bool isModified;


    void init();
    void readEntry(qint64 key);
    void closeEvent(QCloseEvent* event) override;
    void reject() override;
    bool querySave();
    bool saveEntry();
};

#endif // GERICHTDETAILSDIALOG_H
