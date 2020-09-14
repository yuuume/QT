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

private slots:
    void on_btnexit_clicked();

    void on_btnstart_clicked();

    void on_loadgame_clicked();

    void on_reset_clicked();

    void setallpopsdisappear();

    void setallpopsappear();

    void showcurstypigs(int);

    void on_btnstyshow_clicked();

    void setcurstytypetxt();

    void on_btnload_2_clicked();

    void on_btndata_clicked();

    void on_btnshop_clicked();

    void on_btnbuff_clicked();

    void on_btnset_clicked();

    void Datashow();

    void on_btnmix_clicked();

    void on_btnsingle_clicked();

    void moveallreset();

    void on_btnleft_clicked();

    void on_btnright_clicked();

    void on_btnleft2_clicked();

    void on_btnright2_clicked();

    void on_btnclose0_clicked();

    void on_btncondata_clicked();

    void on_btnlocksty_clicked();

    void on_spinBox_1_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_btncost_clicked();

    void on_btnclose2_clicked();

    void on_btnbuff1_clicked();

    void on_btnbuff2_clicked();

    void on_btnbuff3_clicked();

    void on_btnbuff4_clicked();

    void on_btnbuff5_clicked();

    void on_btnbuffcost_clicked();

    void on_btnclose3_clicked();

    void on_btnexit_2_clicked();

    void on_btnsave_clicked();

    void on_btnnextmonth_clicked();

    void on_btnok_clicked();

    void on_btnclose1_clicked();

    void on_btnreset_clicked();

private:
    Ui::MyMainWindow *ui;
    QMovie *bigpig;
    QMovie *colouredpig;
    QMovie *blackpig;
    QMovie *nullmovie;
};

#endif // MYMAINWINDOW_H
