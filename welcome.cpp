#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::Welcome)
{
    //this->pet = pet ;
    ui->setupUi(this);
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);

    ui->textEdit->setReadOnly(true) ;
    ui->textEdit->setTextBackgroundColor(Qt::white) ;
    ui->textEdit->setTextColor(Qt::white) ;
    setWindowTitle("快来领养宠物吧~");
    setFixedSize(500,500);
    begin = new QPushButton("",this) ;
    //设置按钮格式
    begin->move(260,230);
    begin->setStyleSheet({"border-image:url(:/new/prefix1/resource/begin1.png)"});
    begin->setAutoFillBackground(true);
    begin->setFixedSize(200,200);
    begin->show() ;

    //添加宠物动态图片
    labelQ=new QLabel(this);
    QMovie* moive1=new QMovie(":/new/prefix1/resource/qq.gif");
    labelQ->setMovie(moive1);
    moive1->start();
    labelQ->setScaledContents(true);
    labelQ->setFixedSize(110,110);
    labelQ->move(300,180);
    //定义连接槽,连接到主卧室
    connect(begin,SIGNAL(clicked()) , this,SLOT( begin_click() )) ;

}

Welcome::~Welcome()
{
    delete ui;
}
void Welcome::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/welcome1.jpg"));
}

void Welcome::begin_click(){
//点击开始，跳转到主卧室中去
p = new Playroom(NULL) ;
p->show() ;
hide() ;

}






