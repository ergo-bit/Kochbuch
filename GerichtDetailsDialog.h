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

    void on_rbFruehstueck_clicked();
    void on_rbMittag_clicked();
    void on_rbAbendbrot_clicked();
    void on_rbSnack_clicked();
    void on_rbNachtisch_clicked();

    void on_btnSpeichern_clicked();

    void on_textGerichtName_returnPressed();

    void on_textGerichtName_textChanged(const QString &arg1);

    void on_textPersonen_returnPressed();

    void on_textPersonen_textChanged(const QString &arg1);

    void on_textAnleitung_textChanged();

    void on_textDauer_returnPressed();

    void on_textDauer_textChanged(const QString &arg1);

private:
    Ui::GerichtDetailsDialog *ui;
    qint64 dlgKey;
    QString timeStamp;
    bool isModified;
    QString category = QString("");
    QString mealName = QString("");



    void init();
    void readEntry(qint64 key);
    void closeEvent(QCloseEvent* event) override;
    void reject() override;
    bool querySave();
    bool saveEntry();
    bool entryIsValid();
    bool updateEntry(qint64 key);
};

#endif // GERICHTDETAILSDIALOG_H
