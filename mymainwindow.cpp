#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include<QPainter>
#include<QList>
#include<QMenu>
#include<QAction>
#include<QMessageBox>
#include<QWidget>
#include<QMovie>
#include<QDebug>
#include<QString>
#include<QLayout>
#include<QFrame>
#include<QFile>
#include<QDesktopServices>
struct pig
{
    double w;
    int boughtmonth,type;
};
QList <pig> pigs[100];
int curmonth,cursty,maxlocksty,gold;
int buffprice=100,buffspeed=100;
int stytype[105];
int buffmap[2][15];
int buf;
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    //图标
    setWindowIcon(QIcon(":/pigsres/window.jpg"));
    //首页
    //GameMenu显示
    setallpopsdisappear();
    ui->Buff->hide();
    ui->CurTotal->hide();
    ui->Data->hide();
    ui->SellBox->hide();
    ui->Set->hide();
    ui->Shop->hide();
    ui->StySet->hide();
    ui->TopMenuList->hide();
    ui->btnlocksty->hide();
    //load功能（load&&reset)
    QMenu* load_menu=new QMenu;
    QAction* loaddata = new QAction("load game");
    QAction* resetdata = new QAction("reset game");
    load_menu->addAction(loaddata);
    load_menu->addAction(resetdata);
    ui->btnload->setMenu(load_menu);
    connect(loaddata, SIGNAL(triggered(bool)), this, SLOT(on_loadgame_clicked()));
    connect(resetdata, SIGNAL(triggered(bool)), this, SLOT(on_reset_clicked()));
    //setpops
    nullmovie=new QMovie;
    bigpig=new QMovie;
    bigpig->setFileName(":/pigsres/bigpig.gif");
    blackpig=new QMovie;
    blackpig->setFileName(":/pigsres/blackpig.gif");
    colouredpig=new QMovie;
    colouredpig->setFileName(":/pigsres/colouredpig.gif");

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
    ui->frame->hide();
    //初始设置 混合型
    curmonth=1;
    cursty=1;
    maxlocksty=1;
    gold=1000;
    stytype[1]=1;
    pig hog={50.0,1,1};
    pigs[0].push_back(hog);
    pigs[0].push_back(hog);
    //游戏页面显示
    showcurstypigs(0);//cursty  setpops
    on_btnstyshow_clicked();//右侧显示
    setallpopsappear();
}
//首页分
void MyMainWindow::on_loadgame_clicked(){
    on_btnload_2_clicked();
}
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
void MyMainWindow::setallpopsdisappear()
{
    ui->pop1->setVisible(false);
    ui->pop2->setVisible(false);
    ui->pop3->setVisible(false);
    ui->pop4->setVisible(false);
    ui->pop5->setVisible(false);
    ui->pop6->setVisible(false);
    ui->pop7->setVisible(false);
    ui->pop8->setVisible(false);
    ui->pop9->setVisible(false);
    ui->pop10->setVisible(false);
}
void MyMainWindow::setallpopsappear(){
    ui->pop1->setVisible(true);
    ui->pop2->setVisible(true);
    ui->pop3->setVisible(true);
    ui->pop4->setVisible(true);
    ui->pop5->setVisible(true);
    ui->pop6->setVisible(true);
    ui->pop7->setVisible(true);
    ui->pop8->setVisible(true);
    ui->pop9->setVisible(true);
    ui->pop10->setVisible(true);
}
void MyMainWindow::showcurstypigs(int m)
{

    int n=pigs[m].size();
    qDebug()<<"Stysize:"<<n;
    if (n==1)
    {
        if (pigs[m][0].type==1)
           ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
           ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
           ui->pop1->setMovie(blackpig),blackpig->start();
    }
    if (n==2)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
    }
    if (n==3)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
    }
    if (n==4)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
    }
    if (n==5)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
        if (pigs[m][4].type==1)
            ui->pop5->setMovie(bigpig),bigpig->start();
        if (pigs[m][4].type==2)
            ui->pop5->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][4].type==3)
            ui->pop5->setMovie(blackpig),blackpig->start();
    }
    if (n==6)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
        if (pigs[m][4].type==1)
            ui->pop5->setMovie(bigpig),bigpig->start();
        if (pigs[m][4].type==2)
            ui->pop5->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][4].type==3)
            ui->pop5->setMovie(blackpig),blackpig->start();
        if (pigs[m][5].type==1)
            ui->pop6->setMovie(bigpig),bigpig->start();
        if (pigs[m][5].type==2)
            ui->pop6->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][5].type==3)
            ui->pop6->setMovie(blackpig),blackpig->start();
    }
    if (n==7)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
        if (pigs[m][4].type==1)
            ui->pop5->setMovie(bigpig),bigpig->start();
        if (pigs[m][4].type==2)
            ui->pop5->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][4].type==3)
            ui->pop5->setMovie(blackpig),blackpig->start();
        if (pigs[m][5].type==1)
            ui->pop6->setMovie(bigpig),bigpig->start();
        if (pigs[m][5].type==2)
            ui->pop6->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][5].type==3)
            ui->pop6->setMovie(blackpig),blackpig->start();
        if (pigs[m][6].type==1)
            ui->pop7->setMovie(bigpig),bigpig->start();
        if (pigs[m][6].type==2)
            ui->pop7->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][6].type==3)
            ui->pop7->setMovie(blackpig),blackpig->start();
    }
    if (n==8)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
        if (pigs[m][4].type==1)
            ui->pop5->setMovie(bigpig),bigpig->start();
        if (pigs[m][4].type==2)
            ui->pop5->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][4].type==3)
            ui->pop5->setMovie(blackpig),blackpig->start();
        if (pigs[m][5].type==1)
            ui->pop6->setMovie(bigpig),bigpig->start();
        if (pigs[m][5].type==2)
            ui->pop6->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][5].type==3)
            ui->pop6->setMovie(blackpig),blackpig->start();
        if (pigs[m][6].type==1)
            ui->pop7->setMovie(bigpig),bigpig->start();
        if (pigs[m][6].type==2)
            ui->pop7->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][6].type==3)
            ui->pop7->setMovie(blackpig),blackpig->start();
        if (pigs[m][7].type==1)
            ui->pop8->setMovie(bigpig),bigpig->start();
        if (pigs[m][7].type==2)
            ui->pop8->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][7].type==3)
            ui->pop8->setMovie(blackpig),blackpig->start();
    }
    if (n==9)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
        if (pigs[m][4].type==1)
            ui->pop5->setMovie(bigpig),bigpig->start();
        if (pigs[m][4].type==2)
            ui->pop5->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][4].type==3)
            ui->pop5->setMovie(blackpig),blackpig->start();
        if (pigs[m][5].type==1)
            ui->pop6->setMovie(bigpig),bigpig->start();
        if (pigs[m][5].type==2)
            ui->pop6->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][5].type==3)
            ui->pop6->setMovie(blackpig),blackpig->start();
        if (pigs[m][6].type==1)
            ui->pop7->setMovie(bigpig),bigpig->start();
        if (pigs[m][6].type==2)
            ui->pop7->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][6].type==3)
            ui->pop7->setMovie(blackpig),blackpig->start();
        if (pigs[m][7].type==1)
            ui->pop8->setMovie(bigpig),bigpig->start();
        if (pigs[m][7].type==2)
            ui->pop8->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][7].type==3)
            ui->pop8->setMovie(blackpig),blackpig->start();
        if (pigs[m][8].type==1)
            ui->pop9->setMovie(bigpig),bigpig->start();
        if (pigs[m][8].type==2)
            ui->pop9->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][8].type==3)
            ui->pop9->setMovie(blackpig),blackpig->start();
    }
    if (n==10)
    {
        if (pigs[m][0].type==1)
            ui->pop1->setMovie(bigpig),bigpig->start();
        if (pigs[m][0].type==2)
            ui->pop1->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][0].type==3)
            ui->pop1->setMovie(blackpig),blackpig->start();
        if (pigs[m][1].type==1)
            ui->pop2->setMovie(bigpig),bigpig->start();
        if (pigs[m][1].type==2)
            ui->pop2->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][1].type==3)
            ui->pop2->setMovie(blackpig),blackpig->start();
        if (pigs[m][2].type==1)
            ui->pop3->setMovie(bigpig),bigpig->start();
        if (pigs[m][2].type==2)
            ui->pop3->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][2].type==3)
            ui->pop3->setMovie(blackpig),blackpig->start();
        if (pigs[m][3].type==1)
            ui->pop4->setMovie(bigpig),bigpig->start();
        if (pigs[m][3].type==2)
            ui->pop4->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][3].type==3)
            ui->pop4->setMovie(blackpig),blackpig->start();
        if (pigs[m][4].type==1)
            ui->pop5->setMovie(bigpig),bigpig->start();
        if (pigs[m][4].type==2)
            ui->pop5->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][4].type==3)
            ui->pop5->setMovie(blackpig),blackpig->start();
        if (pigs[m][5].type==1)
            ui->pop6->setMovie(bigpig),bigpig->start();
        if (pigs[m][5].type==2)
            ui->pop6->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][5].type==3)
            ui->pop6->setMovie(blackpig),blackpig->start();
        if (pigs[m][6].type==1)
            ui->pop7->setMovie(bigpig),bigpig->start();
        if (pigs[m][6].type==2)
            ui->pop7->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][6].type==3)
            ui->pop7->setMovie(blackpig),blackpig->start();
        if (pigs[m][7].type==1)
            ui->pop8->setMovie(bigpig),bigpig->start();
        if (pigs[m][7].type==2)
            ui->pop8->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][7].type==3)
            ui->pop8->setMovie(blackpig),blackpig->start();
        if (pigs[m][8].type==1)
            ui->pop9->setMovie(bigpig),bigpig->start();
        if (pigs[m][8].type==2)
            ui->pop9->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][8].type==3)
            ui->pop9->setMovie(blackpig),blackpig->start();
        if (pigs[m][9].type==1)
            ui->pop10->setMovie(bigpig),bigpig->start();
        if (pigs[m][9].type==2)
            ui->pop10->setMovie(colouredpig),colouredpig->start();
        if (pigs[m][9].type==3)
            ui->pop10->setMovie(blackpig),blackpig->start();
    }
}
void MyMainWindow::setcurstytypetxt()
{
    if (stytype[cursty]==0)
        ui->curstytype->setText("未设置");
    if (stytype[cursty]==1)
        ui->curstytype->setText("混合型");
    if (stytype[cursty]==2)
        ui->curstytype->setText("黑猪");
}
//内页显示
void MyMainWindow::on_btnstyshow_clicked()
{
        ui->TopMenuList->show();
        ui->StySet->show();
        ui->CurTotal->show();
        QString temp1,temp2;
        ui->gold->setText(QString::number(gold,10));
        ui->curtime->setText(QString::number(curmonth,10));
        int sum=0;
        for (int i=0;i<maxlocksty;i++)
        {
            sum+=pigs[i].size();
        }
        temp1=QString::number(sum,10);
        int temp=maxlocksty*10;
        temp2=QString::number(temp,10);
        temp1=temp1+"/"+temp2;
        ui->total->setText(temp1);
        setcurstytypetxt();
}
//猪圈类型
void MyMainWindow::on_btnmix_clicked()
{
    bool flag=true;
    for(int i=0;i<pigs[cursty-1].size();i++)
        if(pigs[cursty-1][i].type==3){
            flag=false;break;
        }
    if(flag==true) stytype[cursty]=1;
    else QMessageBox::about(NULL,"","该猪圈有黑猪，您无法设置");
    setcurstytypetxt();
}
void MyMainWindow::on_btnsingle_clicked()
{
    bool flag=true;
    for(int i=0;i<pigs[cursty-1].size();i++)
        if(pigs[cursty-1][i].type!=3){
            flag=false;break;
        }
    if(flag==true) stytype[cursty]=2;
    else QMessageBox::about(NULL,"","该猪圈有其他猪，您无法设置");
    setcurstytypetxt();
}
//猪圈改变 参数改变获取 页面显示
void MyMainWindow::moveallreset(){
    //获取信息
    setcurstytypetxt();
    QString temp1,temp2="/100";
    temp1=QString::number(cursty,10);
    temp1+=temp2;
    ui->curstynum->setText(temp1);
    //画面呈现
    ui->btnlocksty->setVisible(false);
    ui->pop1->setMovie(nullmovie);
    ui->pop2->setMovie(nullmovie);
    ui->pop3->setMovie(nullmovie);
    ui->pop4->setMovie(nullmovie);
    ui->pop5->setMovie(nullmovie);
    ui->pop6->setMovie(nullmovie);
    ui->pop7->setMovie(nullmovie);
    ui->pop8->setMovie(nullmovie);
    ui->pop9->setMovie(nullmovie);
    ui->pop10->setMovie(nullmovie);
    showcurstypigs(cursty-1);
    if(cursty>maxlocksty) ui->btnlocksty->setVisible(true);
}
//猪圈滚动
void MyMainWindow::on_btnleft_clicked()
{
    cursty--;
    if(cursty==0) cursty=100;
    moveallreset();
    Datashow();//信息更新
}
void MyMainWindow::on_btnright_clicked()
{
    cursty++;
    if(cursty==101) cursty=1;
    moveallreset();
    Datashow();//信息更新
}
void MyMainWindow::on_btnleft2_clicked()
{
    cursty-=10;
    if(cursty<1) cursty=100;
    moveallreset();
    Datashow();//信息更新
}
void MyMainWindow::on_btnright2_clicked()
{
    cursty+=10;
    if(cursty>100) cursty=1;
    moveallreset();
    Datashow();//信息更新
}
//解锁新猪圈
void MyMainWindow::on_btnlocksty_clicked()
{
    if(gold<1000) QMessageBox::about(NULL,"","您没有足够的金币");
    else if(cursty>maxlocksty+1) QMessageBox::about(NULL,"","请按顺序解锁");
    else{
        gold-=1000;
        maxlocksty++;
        moveallreset();
        ui->gold->setText(QString::number(gold,10));
        int sum;
        for(int i=0;i<cursty;i++){
            sum+=pigs[i].size();
        }
        QString temp1,temp2;
        temp1=QString::number(sum,10);
        int temp=cursty*10;
        temp2=QString::number(temp,10);
        temp1=temp1+"/"+temp2;
        ui->total->setText(temp1);
    }
}

//信息
void MyMainWindow::Datashow(){
    ui->lb1y->setText("");ui->lb1w->setText("");ui->lb1t->setText("");
    ui->lb2y->setText("");ui->lb2w->setText("");ui->lb2t->setText("");
    ui->lb3y->setText("");ui->lb3w->setText("");ui->lb3t->setText("");
    ui->lb4y->setText("");ui->lb4w->setText("");ui->lb4t->setText("");
    ui->lb5y->setText("");ui->lb5w->setText("");ui->lb5t->setText("");
    ui->lb6y->setText("");ui->lb6w->setText("");ui->lb6t->setText("");
    ui->lb8y->setText("");ui->lb8w->setText("");ui->lb8t->setText("");
    ui->lb9y->setText("");ui->lb9w->setText("");ui->lb9t->setText("");
    ui->lb10y->setText("");ui->lb10w->setText("");ui->lb10t->setText("");
    int n=pigs[cursty-1].size();
    QString temp;
    if(n>=1){
        if(pigs[cursty-1][0].type==1) temp="大花白猪";
        if(pigs[cursty-1][0].type==2) temp="小花猪";
        if(pigs[cursty-1][0].type==3) temp="黑猪";
        ui->lb1y->setText(temp);
        ui->lb1w->setText(QString::number(pigs[cursty-1][0].w,10,2));
        ui->lb1t->setText(QString::number(pigs[cursty-1][0].boughtmonth,10));
    }
    if(n>=2){
        if(pigs[cursty-1][1].type==1) temp="大花白猪";
        if(pigs[cursty-1][1].type==2) temp="小花猪";
        if(pigs[cursty-1][1].type==3) temp="黑猪";
        ui->lb2y->setText(temp);
        ui->lb2w->setText(QString::number(pigs[cursty-1][1].w,10,2));
        ui->lb2t->setText(QString::number(pigs[cursty-1][1].boughtmonth,10));
    }
    if(n>=3){
        if(pigs[cursty-1][2].type==1) temp="大花白猪";
        if(pigs[cursty-1][2].type==2) temp="小花猪";
        if(pigs[cursty-1][2].type==3) temp="黑猪";
        ui->lb3y->setText(temp);
        ui->lb3w->setText(QString::number(pigs[cursty-1][2].w,10,2));
        ui->lb3t->setText(QString::number(pigs[cursty-1][2].boughtmonth,10));
    }
    if(n>=4){
        if(pigs[cursty-1][3].type==1) temp="大花白猪";
        if(pigs[cursty-1][3].type==2) temp="小花猪";
        if(pigs[cursty-1][3].type==3) temp="黑猪";
        ui->lb4y->setText(temp);
        ui->lb4w->setText(QString::number(pigs[cursty-1][3].w,10,2));
        ui->lb4t->setText(QString::number(pigs[cursty-1][3].boughtmonth,10));
    }
    if(n>=5){
        if(pigs[cursty-1][4].type==1) temp="大花白猪";
        if(pigs[cursty-1][4].type==2) temp="小花猪";
        if(pigs[cursty-1][4].type==3) temp="黑猪";
        ui->lb5y->setText(temp);
        ui->lb5w->setText(QString::number(pigs[cursty-1][4].w,10,2));
        ui->lb5t->setText(QString::number(pigs[cursty-1][4].boughtmonth,10));
    }
    if(n>=6){
        if(pigs[cursty-1][5].type==1) temp="大花白猪";
        if(pigs[cursty-1][5].type==2) temp="小花猪";
        if(pigs[cursty-1][5].type==3) temp="黑猪";
        ui->lb6y->setText(temp);
        ui->lb6w->setText(QString::number(pigs[cursty-1][5].w,10,2));
        ui->lb6t->setText(QString::number(pigs[cursty-1][5].boughtmonth,10));
    }
    if(n>=7){
        if(pigs[cursty-1][6].type==1) temp="大花白猪";
        if(pigs[cursty-1][6].type==2) temp="小花猪";
        if(pigs[cursty-1][6].type==3) temp="黑猪";
        ui->lb7y->setText(temp);
        ui->lb7w->setText(QString::number(pigs[cursty-1][6].w,10,2));
        ui->lb7t->setText(QString::number(pigs[cursty-1][6].boughtmonth,10));
    }
    if(n>=8){
        if(pigs[cursty-1][7].type==1) temp="大花白猪";
        if(pigs[cursty-1][7].type==2) temp="小花猪";
        if(pigs[cursty-1][7].type==3) temp="黑猪";
        ui->lb8y->setText(temp);
        ui->lb8w->setText(QString::number(pigs[cursty-1][7].w,10,2));
        ui->lb8t->setText(QString::number(pigs[cursty-1][7].boughtmonth,10));
    }
    if(n>=9){
        if(pigs[cursty-1][8].type==1) temp="大花白猪";
        if(pigs[cursty-1][8].type==2) temp="小花猪";
        if(pigs[cursty-1][8].type==3) temp="黑猪";
        ui->lb9y->setText(temp);
        ui->lb9w->setText(QString::number(pigs[cursty-1][8].w,10,2));
        ui->lb9t->setText(QString::number(pigs[cursty-1][8].boughtmonth,10));
    }
    if(n==10){
        if(pigs[cursty-1][9].type==1) temp="大花白猪";
        if(pigs[cursty-1][9].type==2) temp="小花猪";
        if(pigs[cursty-1][9].type==3) temp="黑猪";
        ui->lb10y->setText(temp);
        ui->lb10w->setText(QString::number(pigs[cursty-1][9].w,10,2));
        ui->lb10t->setText(QString::number(pigs[cursty-1][9].boughtmonth,10));
    }

}
//点击Data  open||close
void MyMainWindow::on_btndata_clicked()
{
    if(ui->Data->isVisible()){
        ui->Data->hide();
    }
    else{
        ui->Data->show();
        Datashow();//信息更新
    }
}
void MyMainWindow::on_btnclose0_clicked()
{
    qDebug()<<"shop close"<<endl;

    ui->Data->setVisible(false);
    qDebug()<<"shop close"<<endl;
}
//购入出售文件
void MyMainWindow::on_btncondata_clicked()
{
    QString strPath = "record.txt";
    QDesktopServices bs;
    bs.openUrl(QUrl(strPath));
}
//商店
void MyMainWindow::on_btnshop_clicked()
{
    if(ui->Shop->isVisible()){
        ui->spinBox_1->setValue(0);
        ui->spinBox_2->setValue(0);
        ui->spinBox_3->setValue(0);
        ui->cost->setText("0");
        ui->Shop->hide();
    }
    else {
        ui->Shop->show();
    }

}
void MyMainWindow::on_btnclose1_clicked()
{
    ui->spinBox_1->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->cost->setText("0");
    ui->Shop->hide();
}



void MyMainWindow::on_spinBox_1_valueChanged(int arg1)
{
    int a=ui->spinBox_2->value()*330;
    int b=ui->spinBox_3->value()*520;
    int sum=arg1*230+a+b;
    QString temp=QString::number(sum,10);
    ui->cost->setText(temp);
}
void MyMainWindow::on_spinBox_2_valueChanged(int arg1)
{
    int a=ui->spinBox_1->value()*230;
    int b=ui->spinBox_3->value()*520;
    int sum=arg1*330+a+b;
    QString temp=QString::number(sum,10);
    ui->cost->setText(temp);
}
void MyMainWindow::on_spinBox_3_valueChanged(int arg1)
{
    int a=ui->spinBox_1->value()*230;
    int b=ui->spinBox_2->value()*330;
    int sum=arg1*520+a+b;
    QString temp=QString::number(sum,10);
    ui->cost->setText(temp);
}
void MyMainWindow::on_btncost_clicked()
{
    int a=ui->spinBox_1->value(),b=ui->spinBox_2->value(),c=ui->spinBox_3->value(),x=0,y=0;
    int cost=a*230+b*330+c*520;
    if(cost>gold){
        QMessageBox::about(NULL,"","当前金币不足");
        return;
    }
    for (int i=1;i<=maxlocksty;i++)
    {
        switch (stytype[i]){
        case 0:break;
        case 1:x+=10-pigs[i-1].size();break;
        case 2:y+=10-pigs[i-1].size();break;
        }
    }
    if (a+b>x||c>y)
    {
         QMessageBox::about(NULL, "", "猪圈无法放下这些猪");
         return;
    }
    //平均分配
    QFile data("record.txt");
    if (data.open(QFile::WriteOnly | QIODevice::Append|QIODevice::Text)) {
        QTextStream out(&data);
        out <<"In "<< curmonth<<" month,you have bought "<<a<<" big white pigs "<<b<<" little coloured pigs "<<c<<" blackpigs\n";
    }
    data.close();

    int xa=0,yb=0,zc=0,xn=0,zn=0;
    for(int i=0;i<maxlocksty;i++)
        for(int j=0;j<pigs[i].size();j++)
            if(pigs[i][j].type==1) xa+=1;
    qDebug()<<"a"<<a<<"  "<<"xa"<<xa<<endl;
    for(int i=1;i<=maxlocksty;i++)
        if(stytype[i]==1) xn+=1;
qDebug()<<"xn"<<xn<<endl;
    if(xn>0&&a>0){
        int ave=(xa+a)/xn;
        qDebug()<<"a"<<a<<"  "<<"xa"<<xa<<" "<<"xn"<<xn<<endl;
        qDebug()<<"ave"<<ave<<endl;
        for(int i=0;i<maxlocksty;i++){
            pig ww;ww.boughtmonth=curmonth;
            if(stytype[i+1]==1&&a>0){
                int l=0;
                for(int j=0;j<pigs[i].size();j++){

                    if(pigs[i][j].type==1)
                     l+=1;
                }
                if(l>=ave) continue;
                if(l<ave){
                    int n=ave-l;
                    while(n--){
                        if(a>0){
                            int m=qrand()%31+20;
                            double q=m*1.0;
                            ww.w=q;
                            ww.type=1;
                            pigs[i].push_back(ww);
                            a--;continue;

                        }
                    }
                }

            }
        }
        qDebug()<<"a"<<a<<endl;
        if(a>0){
            for(int i=0;i<maxlocksty;i++){
                pig ww;ww.boughtmonth=curmonth;
                if(stytype[i+1]==1&&a>0){
                    int l=10-pigs[i].size();
                    while(l--){
                        int m=qrand()%31+20;
                        double q=m*1.0;
                        ww.w=q;
                        ww.type=1;
                        pigs[i].push_back(ww);
                        a--;
                        if(a==0) break;
                        continue;
                    }
                }
            }

        }

    }
    xa=0,yb=0,zc=0,xn=0,zn=0;
    for(int i=0;i<maxlocksty;i++)
        for(int j=0;j<pigs[i].size();j++)
            if(pigs[i][j].type==2) yb+=1;
    for(int i=1;i<=maxlocksty;i++)
        if(stytype[i]==1) xn+=1;
    if(xn>0&&b>0){
        int ave=(yb+b)/xn;
        qDebug()<<"ave:"<<ave;
        for(int i=0;i<maxlocksty;i++){
            pig ww;ww.boughtmonth=curmonth;
            if(stytype[i+1]==1&&b>0){
                int l=0;
                for(int j=0;j<pigs[i].size();j++){

                    if(pigs[i][j].type==2)
                        l+=1;
                    }
                        if(l>=ave) continue;
                        if(l<ave){
                             int n=ave-l;
                             while(n--){
                               if(b>0){
                                int m=qrand()%31+20;
                                double q=m*1.0;
                                ww.w=q;
                                ww.type=2;
                                pigs[i].push_back(ww);
                                b--;continue;

                            }
                        }
                    }
            }
            qDebug()<<"Successfully"<<pigs[0].size();
            qDebug()<<"b"<<b;
        }
        if(b>0){

            for(int i=0;i<maxlocksty;i++){
                pig ww;ww.boughtmonth=curmonth;
                if(stytype[i+1]==1&&b>0){
                    int l=10-pigs[i].size();
                    while(l--){
                        int m=qrand()%31+20;
                        double q=m*1.0;
                        ww.w=q;
                        ww.type=2;
                        pigs[i].push_back(ww);
                        b--;
                        if(b==0) break;
                        continue;
                    }
                }
            }
        }
    }
    xa=0,yb=0,zc=0,xn=0,zn=0;
    for(int i=0;i<maxlocksty;i++)
        for(int j=0;j<pigs[i].size();j++)
            if(pigs[i][j].type==3) zc+=1;
    for(int i=1;i<=maxlocksty;i++)
        if(stytype[i]==2) zn+=1;
    if(zn>0&&c>0){
        int ave=(zc+c)/zn;
        for(int i=0;i<maxlocksty;i++){
            pig ww;ww.boughtmonth=curmonth;
            if(stytype[i+1]==2&&c>0){
                int l=0;
                for(int j=0;j<pigs[i].size();j++){

                    if(pigs[i][j].type==3)
                     l+=1;
              }
                if(l>=ave) continue;
                if(l<ave){
                    int n=ave-l;
                    while(n--){
                        if(c>0){
                            int m=qrand()%31+20;
                            double q=m*1.0;
                            ww.w=q;
                            ww.type=3;
                            pigs[i].push_back(ww);
                            c--;continue;

                        }
                    }
                }
            }
        }
        if(c>0){
            for(int i=0;i<maxlocksty;i++){
                pig ww;ww.boughtmonth=curmonth;
                if(stytype[i+1]==1&&c>0){
                    int l=10-pigs[i].size();
                    while(l--){
                        int m=qrand()%31+20;
                        double q=m*1.0;
                        ww.w=q;
                        ww.type=3;
                        pigs[i].push_back(ww);
                        c--;
                        if(c==0)break;
                        continue;
                    }
                }
            }
        }
    }
    qDebug()<<"Deal Successfully"<<pigs[0].size();
    gold-=cost;
    on_btnstyshow_clicked();
    moveallreset();
}
void MyMainWindow::on_btnbuff_clicked()
{
    if(ui->Buff->isVisible()){
        ui->Buff->hide();
    }
    else
        ui->Buff->show();
}
void MyMainWindow::on_btnclose2_clicked()
{
    ui->Buff->hide();
}
void MyMainWindow::on_btnbuff1_clicked()
{
    buf=1;
    ui->lbbuffeffect->setText("具体信息:");
    ui->lbbuffcost->setText("花费:");
    ui->buffname->setText("普奥土霉素");
    ui->buffeffect->setText("动态驱虫，诱食防泻；防止红/黄/白痢，<br/>抗菌消炎，增强免疫力；<br/>可加速猪猪们的增长速率20%，提高出售单价10%，<br/>你的猪猪们值得拥有哦~");
    ui->buffcost->setText("2000");
}
void MyMainWindow::on_btnbuff2_clicked()
{
    buf=2;
    ui->lbbuffeffect->setText("具体信息:");
    ui->lbbuffcost->setText("花费:");
    ui->buffname->setText("脱霉先锋");
    ui->buffeffect->setText("可解除霉菌毒素引起的诸多问题，<br/>如背皮结痂，调节肠道，促消化，提高存活率。<br/>可加速猪猪们的增长速率30%，提高出售单价20%，<br/>心动不如行动，快来抢购啦~");
    ui->buffcost->setText("4000");
}
void MyMainWindow::on_btnbuff3_clicked()
{
    buf=3;
    ui->lbbuffeffect->setText("具体信息:");
    ui->lbbuffcost->setText("花费:");
    ui->buffname->setText("肥壮素");
    ui->buffeffect->setText("提高适口性，增加采食量；加快微循环，<br/>改善外观体型；块大、多肉、省料少病、<br/>肉质好。可加速猪猪们的增长速率40%，<br/>提高出售单价30%，<br/>千万人的选择，不要再犹豫啦~");
    ui->buffcost->setText("6000");
}
void MyMainWindow::on_btnbuff4_clicked()
{
    buf=4;
    ui->lbbuffeffect->setText("具体信息:");
    ui->lbbuffcost->setText("花费:");
    ui->buffname->setText("速效多维");
    ui->buffeffect->setText("四季可用，抗应激；增加能量，补充维生素<br/>氨基酸；促进生长，提高饲料利用率。<br/>可加速猪猪们的增长速率50%,提高出售单价40%，<br/>超百万养殖户口碑推荐！！！");
    ui->buffcost->setText("8000");
}
void MyMainWindow::on_btnbuff5_clicked()
{
    buf=5;
    ui->lbbuffeffect->setText("具体信息:");
    ui->lbbuffcost->setText("花费:");
    ui->buffname->setText("肥立宝");
    ui->buffeffect->setText("安全催肥，瘦肉率高；补血健胃，提高食欲；<br/>调节内分泌，抗病保健；饲料转化高，清除内毒素。<br/>可加速猪猪们的增长速率65%,提高出售单价50%，<br/>看得见的好品质，为您打造。");
    ui->buffcost->setText("10000");
}
void MyMainWindow::on_btnbuffcost_clicked()
{
    int cost=buf*2000;
    if (gold<cost)
        {
            QMessageBox::about(NULL, "", "金币不足");
            return;
        }
        gold-=cost;
        ui->gold->setText(QString::number(gold,10));
    if(buf==1)
        buffspeed=120,buffprice=110;
    if(buf==2)
        buffspeed=130,buffprice=120;
    if(buf==3)
        buffspeed=140,buffprice=130;
    if(buf==4)
        buffspeed=150,buffprice=140;
    if(buf==5)
        buffspeed=165,buffprice=150;
    QMessageBox::about(NULL, "", "设置成功！");
}
void MyMainWindow::on_btnset_clicked()
{
    if(ui->Set->isVisible()){
        ui->Set->hide();
    }
    else
        ui->Set->show();
}
void MyMainWindow::on_btnclose3_clicked()
{
    ui->Set->hide();
}

void MyMainWindow::on_btnexit_2_clicked()
{
    on_btnexit_clicked();
}
void MyMainWindow::on_btnsave_clicked()
{
    QFile file("save.txt");
    if(file.exists()){
        file.remove();
    }
    file.open(QIODevice::WriteOnly);
    file.close();
    if(file.open(QFile::WriteOnly|QIODevice::Append|QIODevice::Text)){//只写、追加
        QTextStream out(&file);//文本流写
        out<<gold<<endl;
        out<<curmonth<<endl;
        out<<maxlocksty<<endl;
        out<<buffprice<<endl;
        out<<buffspeed<<endl;
        for(int i=1;i<=100;i++)
            out<<stytype[i]<<endl;
        for(int i=0;i<maxlocksty;i++){
            out<<pigs[i].size()<<endl;
            for(int j=0;j<pigs[i].size();j++)
                out<<pigs[i][j].w<<endl<<pigs[i][j].boughtmonth<<endl<<pigs[i][j].type<<endl;
        }
    }
    file.close();;
    QMessageBox::about(NULL,"","Save Completed");
    //for(int i=0;i<maxlocksty;i++){
    //for(int j=0;j<pigs[i].size();j++)
        //qDebug()<<pigs[i][j].w<<endl<<pigs[i][j].boughtmonth<<endl<<pigs[i][j].type<<endl;
}
void MyMainWindow::on_btnload_2_clicked()
{
    for(int i=0;i<maxlocksty;i++) pigs[i].clear();
    QFile file("save.txt");

    int cnt=0,round=0,n=1,k=0,l=0;
    pig temp;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Open failed." << endl;
               return ;
    }
    QString strline;
    QTextStream in(&file);
    while(!in.atEnd()){
        strline=in.readLine();
        if(cnt==0) gold=strline.toInt();
        if(cnt==1) curmonth=strline.toInt();
        if(cnt==2) maxlocksty=strline.toInt();
        if(cnt==3) buffprice=strline.toInt();
        if(cnt==4) buffspeed=strline.toInt();
        if(cnt>=5&&cnt<=104)
            stytype[n++]=strline.toInt();
        if(cnt>=105){
            if (round==0)l=strline.toInt();//读入这个猪圈有几头猪
            if (round==1)temp.w=strline.toDouble();
            if (round==2)temp.boughtmonth=strline.toInt();
            if (round==3){
                temp.type=strline.toInt();
                pigs[k].push_back(temp);
                l--;
                round=0;
                if (l==0)
                    k++,round=-1;
              }
              round+=1;
          }
           cnt+=1;
    }
    file.close();
    ui->frame->hide();
    ui->Buff->hide();
    ui->Data->hide();
    ui->Set->hide();
    ui->btnstart->hide();
    ui->btnexit->hide();
    ui->btnload->hide();
    cursty=1;
    showcurstypigs(0);
    on_btnstyshow_clicked();
    setallpopsappear();
}
void MyMainWindow::on_btnnextmonth_clicked()
{
    curmonth++;
    ui->curtime->setText(QString::number(curmonth,10));
    for(int i=0;i<maxlocksty;i++){
        for(int j=0;j<pigs[i].size();i++){
            qDebug()<<"buffspeed"<<buffspeed<<endl;
            for(int x=0;x<30;x++){
                int a=qrand()%13;
                double b=a*1.0*buffspeed/1000;
                pigs[i][j].w+=b;
            }
        }
    }
    if((curmonth-1)%3==0){
        ui->SellBox->show();
        int a=0,b=0,c=0;//总数量
        double aw=0.0,bw=0.0,cw=0.0;//总重量
        for(int i=0;i<maxlocksty;i++){
            for(QList<pig>::iterator it=pigs[i].begin();it!=pigs[i].end();){
                if(curmonth-it->boughtmonth>=12||it->w>=150.0){
                    if(it->type==1){
                        a++;
                        aw+=it->w;
                        it=pigs[i].erase(it);
                    }
                    if(it->type==2){
                        b++;
                        bw+=it->w;
                        it=pigs[i].erase(it);
                    }
                    if(it->type==1){
                        c++;
                        cw+=it->w;
                        it=pigs[i].erase(it);
                    }
                }
                else it++;
            }
        }
        double a1=6.0*buffprice/100,b1=7.0*buffprice/100,c1=15.0*buffprice/100;
        ui->pricewp->setText(QString::number(a1,10,2));
        ui->pricesp->setText(QString::number(b1,10,2));
        ui->pricebp->setText(QString::number(c1,10,2));
        ui->countwp->setText(QString::number(a,10));
        ui->countsp->setText(QString::number(b,10));
        ui->countbp->setText(QString::number(c,10));
        ui->weightwp->setText(QString::number(aw,10,2));
        ui->weightsp->setText(QString::number(bw,10,2));
        ui->weightbp->setText(QString::number(cw,10,2));
        int p1=a1*aw,p2=b1*bw,p3=c1*cw;
        ui->profitwp->setText(QString::number(p1,10));
        ui->profitsp->setText(QString::number(p2,10));
        ui->profitbp->setText(QString::number(p3,10));
        int sum=p1+p2+p3;
        ui->profitsum->setText(QString::number(sum,10));
        QFile data("record.txt");
        if(data.open(QFile::WriteOnly | QIODevice::Append|QIODevice::Text)) {
            QTextStream out(&data);
            out <<"In "<< curmonth<<" month,you sold "<<a<<" big white pigs "<<b<<" little coloured pigs "<<c<<" blackpigs and get "<<sum<<" gold\n";
        }
        data.close();
        gold+=sum;
        ui->btnnextmonth->setEnabled(false);
        on_btnstyshow_clicked();
    }
    Datashow();//信息更新
}
void MyMainWindow::on_btnok_clicked()
{
    moveallreset();
    ui->btnnextmonth->setEnabled(true);
    ui->SellBox->hide();
}


