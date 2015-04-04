#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "create_network.h"
#include "network.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Network network;
    ~MainWindow();

private slots:
    void on_pB_UsunSiec_pressed();

    void on_rB_StworzSiecRecznie_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
