#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include<QPainter>
#include<QList>
#include<QMenu>
#include<QAction>
#include<QMessageBox>
struct pig
{
    double w;
    int boughtmonth,type;
};
QList <pig> pigs[100];
int curmonth,cursty,maxlocksty,gold;
int buffprice=100,buffspeed=100;
int stytype[105];
int foodmap[2][15];
int fdx,fdy;
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    //图标
    setWindowIcon(QIcon(":/pigsres/window.jpg"));
    //load功能（load&&reset)
    QMenu* load_menu=new QMenu;
    QAction* loaddata = new QAction("load game");
    QAction* resetdata = new QAction("reset game");
    load_menu->addAction(loaddata);
    load_menu->addAction(resetdata);
    ui->btnload->setMenu(load_menu);
    QObject::connect(loaddata, SIGNAL(triggered(bool)), this, SLOT(on_loadgame_clicked()));
    QObject::connect(resetdata, SIGNAL(triggered(bool)), this, SLOT(on_reset_clicked()));
}
//背景
void MyMainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pigsres/pig0.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

//首页退出
void MyMainWindow::on_btnexit_clicked(){
    QMessageBox::StandardButton pop;
        pop = QMessageBox::critical(this, "","您确定要退出游戏吗？",QMessageBox::Yes| QMessageBox::No);
        if (pop == QMessageBox::Yes)
        {
            //canexit=0;
            QApplication* app;
            app->closeAllWindows();//退出程序
        }
}
void MyMainWindow::on_btnload_clicked(){}
void MyMainWindow::on_btnstart_clicked(){
    //创建文档  默认重置
    QFile file("record.txt");
    if ( file.exists())
    {
        file.remove();
    }
    file.open( QIODevice::WriteOnly );
    file.close();

    ui->btnstart->setVisible(false);
    ui->btnexit->setVisible(false);
    ui->btnload->setVisible(false);
    //初始设置 混合型
    curmonth=1;
    cursty=1;
    maxlocksty=1;
    gold=1000;
    stytype[1]=1;
    pig hog={50.0,1,1};
    pigs[0].push_back(hog);
    pigs[0].push_back(hog);
    //showpigs(0);
    //on_Qbtnpighome_clicked();
    //setAllbutaOn();
}
void MyMainWindow::on_loadgame_clicked(){}
void MyMainWindow::on_reset_clicked(){
    QMessageBox::StandardButton pop;
         pop = QMessageBox::critical(this, "","重置存档讲使您失去之前的存档，确定继续吗？",QMessageBox::Yes| QMessageBox::No);
        if (pop == QMessageBox::Yes)
        {
            QFile file("save.txt");
            if ( file.exists())
            {
                file.remove();
            }
        }
}
