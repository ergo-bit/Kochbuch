#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QTranslator>
#include <QLibraryInfo>
#include <QSaveFile>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QLineEdit>

#include "NeuDialog.h"
#include "EinkaufslisteDialog.h"
#include "GerichteDAO.h"
#include "Gericht.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_actionB_eenden_triggered();
    void on_btnBeenden_clicked();

    void on_textSuchen_returnPressed();
    void on_textSuchen_editingFinished();
    void on_btnSuchen_clicked();

    void on_btnNeu_clicked();
    void on_action_Neu_2_triggered();

    void on_btnEinkaufsliste_clicked();
    void on_actionZur_Einkaufs_liste_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_btnGerichtLoeschen_clicked();
    void on_btnAlleGerichte_clicked();
    void on_btnFruehstueck_clicked();
    void on_btnMittag_clicked();
    void on_btnAbendbrot_clicked();
    void on_btnSnack_clicked();
    void on_btnNachtisch_clicked();

    void on_textPersonen_returnPressed();
    void on_textPersonen_editingFinished();
    void updateTableView(const qint64);

    void on_textPersonen_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QLabel* statusLabel;
    NeuDialog* newMealDlg = nullptr;
    EinkaufslisteDialog* shoppingListDlg = nullptr;
    QString actFile;
    QTranslator* sysTranslator;
    bool bSysTranslatorLoaded;
    QString category;
    QString mealSearched;



    void init();
    void enableDatabase(bool);
    bool openDatabase(const QString& server, const QString& databaseN);
    void closeEvent(QCloseEvent* event) override;
    void showTable();
//    QSqlTableModel* setTableViewModel();
    QSqlQueryModel* setTableViewModel();
    void newMeal(const qint64 key);
    void showGerichtDetailsDialog(const qint64 key);
    void shoppingList();
    void deleteEntry(const QModelIndex index);
    bool eventFilter(QObject* absender, QEvent* event) override;
    bool isControlKey(int key);
    int convertTextFieldToValue(QLineEdit* tf, QChar keyCharacter);
    void findItemInTableView(const QString& columnName, const QVariant& value);

    bool saveFile(const QString& filename);
    bool saveFileAs();
    bool queryExit();
    bool querySave();



};
#endif // MAINWINDOW_H
