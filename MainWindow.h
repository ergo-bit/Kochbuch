#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;

    void init();
};
#endif // MAINWINDOW_H
