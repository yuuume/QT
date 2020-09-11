#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

    void paintEvent(QPaintEvent *event);
private slots:
    void on_btnexit_clicked();

    void on_btnload_clicked();

    void on_btnstart_clicked();

    void on_loadgame_clicked();

    void on_reset_clicked();
private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
