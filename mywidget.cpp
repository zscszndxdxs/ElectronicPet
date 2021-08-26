#include "mywidget.h"
#include "ui_Mywidget.h"
#include<QDebug>
MyWidget::MyWidget(QWidget *parent, Pet* pet) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    this->pet = pet ;
    b = new Judge(nullptr,pet) ;
    qDebug()<< pet->money ;
    ui->setupUi(this);
    setFixedSize(500,600);
    setWindowTitle("介绍界面") ;
    //消息处理
    connect(b, &Judge::from_board_to_mywidgetSignal, this, &MyWidget::val);
    //信号连接
    connect(ui->OKButton, &QPushButton::released, this, &MyWidget::kaishi);
    pic = new QLabel(this) ;
    pic->setStyleSheet({"border-image:url(:/new/prefix1/resource/qqq1.png)"});
    pic->setAutoFillBackground(true);
    pic->setFixedSize(160,160);
    pic->move(300,400);
    pic->show();
    ui->OKButton->setStyleSheet({"border-image:url(:/new/prefix1/resource/play3.png)"});
    ui->OKButton->setAutoFillBackground(true);
    ui->OKButton->setFixedSize(200,120);
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);
    ui->textEdit->setReadOnly(true);
    //添加人工智能科技感图片
    label = new QLabel( this ) ;
    //主题样式
    label->setStyleSheet({"border-image:url(:/new/prefix1/resource/ai1.png)"});
    label->setAutoFillBackground(true);
    label->setFixedSize(320,200);
    label->move(1,276);
    label->show();

}

//重写perintEvent为窗口添加背景图片
//设置登录界面颜色
void MyWidget::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/welcome.png"));
}




void MyWidget::kaishi()
{
    this->hide();

    b->show();
}


void MyWidget::val()
{
    this->show();
    b->hide();
}

MyWidget::~MyWidget()
{
    delete ui;
}


