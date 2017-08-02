#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QHostInfo>
#include <netassist.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *statusBarLabel;
};

#endif // MAINWINDOW_H
