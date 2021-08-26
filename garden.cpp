#include "garden.h"
#include "ui_garden.h"
#include<QPainter>
#include <QMovie>
#include<QMovie>
#include<QVBoxLayout>
#include<QDebug>
#include<QTime>
Garden::Garden(QWidget *parent,Pet* pet ) :
    QMainWindow(parent)
{
    this->pet = pet ;
    setWindowTitle("Q小鹅的后花园");
    setFixedSize(1100,650);


    //设置宠物动图
    //我的gif图片
    label8=new QLabel(this);
    QMovie* moive1=new QMovie(":/new/prefix1/resource/qq.gif");
    label8->setMovie(moive1);
    moive1->start();
    label8->setScaledContents(true);
    label8->setFixedSize(120,120);
    label8->move(90,350);
    //添加太阳图片
    label9 = new QLabel( this ) ;
    label9->setStyleSheet({"border-image:url(:/new/prefix1/resource/sun.png)"});
    label9->setAutoFillBackground(true);
    label9->setFixedSize(120,120);
    label9->move(950,80);
    label9->show();

    //添加选择按钮
    //设置按钮格式
    xiangrikui1 = new QPushButton("",this) ;
    //设置按钮格式
    xiangrikui1->move(2,564);
    xiangrikui1->setStyleSheet({"border-image:url(:/new/prefix1/resource/xiangrikui1.png)"});
    xiangrikui1->setAutoFillBackground(true);
    xiangrikui1->setFixedSize(80,80);
    xiangrikui1->show() ;



    //设置按钮格式
    yinghua = new QPushButton("",this) ;
    //设置按钮格式
    yinghua->move(70,563);
    yinghua->setStyleSheet({"border-image:url(:/new/prefix1/resource/yinghua.png)"});
    yinghua->setAutoFillBackground(true);
    yinghua->setFixedSize(90,90);
    yinghua->show() ;

    //设置按钮格式
    mantianxing = new QPushButton("",this) ;
    //设置按钮格式
    mantianxing->move(150,570);
    mantianxing->setStyleSheet({"border-image:url(:/new/prefix1/resource/mantianxing.png)"});
    mantianxing->setAutoFillBackground(true);
    mantianxing->setFixedSize(80,80);
    mantianxing->show() ;
    //三个槽函数连接
    connect(xiangrikui1,SIGNAL(clicked()) , this,SLOT( xiangrikui1_click() )) ;
    connect(mantianxing,SIGNAL(clicked()) , this,SLOT( mantianxing_click() )) ;
    connect(yinghua,SIGNAL(clicked()) , this,SLOT( yinghua_click() )) ;
    //判断植物是否种植，引发相应事件
    back = new QPushButton("" ,this ) ;
    //设置按钮格式
    back->move(900,550);
    back->setStyleSheet({"border-image:url(:/new/prefix1/resource/back.png)"});
    back->setAutoFillBackground(true);
    back->setFixedSize(60,60);
    back->show() ;
    //返回到主卧室界面
    connect(back,SIGNAL(clicked()) , this,SLOT( back_click() )) ;

}

Garden::~Garden()
{

}


//设置花园背景图片
void Garden::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/garden.png"));

}


//设置宠物可以移动
void Garden::mousePressEvent(QMouseEvent *e){

        //当鼠标右键点击时.
        if (e->button() == Qt::RightButton)
        {
            QMovie* moive3=new QMovie(":/new/prefix1/resource/qq.gif");
            label8->setMovie(moive3);
            moive3->start();
            label8->setScaledContents(true);
            label8->setFixedSize(120,120);
            label8->move(e->pos().x() - 30,e->pos().y() - 30);

        }
}

//定义三个槽函数
void Garden::xiangrikui1_click(){
    QMessageBox::information( NULL , "提示界面" , "你确定要花费8个金币购买向日葵吗?种植之后，你的向日葵每小时会带来4个金币的收益哦~" ,QMessageBox::Yes) ;
    pet->money = pet->money - 8 ;
    //将向日葵移植到草坪上
    labelXiangrikui1 = new QLabel( this ) ;
    labelXiangrikui1->setStyleSheet({"border-image:url(:/new/prefix1/resource/xiangrikui1.png)"});
    labelXiangrikui1->setAutoFillBackground(true);
    labelXiangrikui1->setFixedSize(120,120);
    labelXiangrikui1->move(530,400);
    labelXiangrikui1->show();
    is_xiangrikui1 = true;
     t1= new QTimer( this) ;
    t1->start(800000) ;
    connect( t1, &QTimer::timeout,[=](){
         pet->money = pet->money + 4;

    }) ;






}

void Garden::mantianxing_click(){
    QMessageBox::information( NULL , "提示界面" , "你确定要花费6个金币购买满天星吗?种植之后，你的满天星每小时会带来3个金币的收益哦~" ,QMessageBox::Yes) ;
    //将满天星移植到草坪上
    pet->money = pet->money - 6 ;
    labelMantianxing = new QLabel( this ) ;
    labelMantianxing->setStyleSheet({"border-image:url(:/new/prefix1/resource/mantianxing.png)"});
    labelMantianxing->setAutoFillBackground(true);
    labelMantianxing->setFixedSize(120,120);
    labelMantianxing->move(625,450);
    labelMantianxing->show();
    is_mantianxing = true ;
    t2= new QTimer( this) ;
    t2->start(600000) ;
    connect( t2, &QTimer::timeout,[=](){
         pet->money = pet->money + 3;

    }) ;



}
//判断樱花是否种植
void Garden::yinghua_click(){
QMessageBox::information( NULL , "提示界面" , "你确定要花费4个金币购买樱花吗?种植之后，你的樱花每小时会带来2个金币的收益哦~" ,QMessageBox::Yes) ;
 pet->money = pet->money - 4 ;
//将樱花移植到草坪上
labelYinghua = new QLabel( this ) ;
labelYinghua->setStyleSheet({"border-image:url(:/new/prefix1/resource/yinghua.png)"});
labelYinghua->setAutoFillBackground(true);
labelYinghua->setFixedSize(120,120);
labelYinghua->move(750,480);
labelYinghua->show();
is_yinghua = true;
 t3= new QTimer( this) ;
 t3->start(400000) ;
 connect( t3, &QTimer::timeout,[=](){
     pet->money = pet->money + 2;
}) ;


}

void Garden::back_click(){
//    t1->stop();
//    t2->stop();
//    t3->stop();
    close();
}







