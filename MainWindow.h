#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDir>
#include <QFileDialog>
#include <QDebug>

#include "NeuDialog.h"
#include "EinkaufslisteDialog.h"

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
    void on_textSuchen_returnPressed();
    void on_textSuchen_editingFinished();

    void on_actionB_eenden_triggered();

    void on_btnNeu_clicked();
    void on_action_Neu_2_triggered();


    void on_btnEinkaufsliste_clicked();

    void on_actionZur_Einkaufs_liste_triggered();

private:
    Ui::MainWindow *ui;
    // #include <QLabel>
    QLabel* statusLabel;
    NeuDialog* newMealDlg = nullptr;
    EinkaufslisteDialog* shoppingListDlg = nullptr;

    void init();

    void enableDatabase(bool);
    bool openDatabase(const QString& server,
                      const QString& databaseN); // Name der Datenban
    //void closeEvent(QCloseEvent* event) override;

    void newMeal();
    void shoppingList();

    void importGerichtIntoDatabase();
};
#endif // MAINWINDOW_H
