#include "chess_load.h"
#include "ui_chess_load.h"
#include<QDebug>
Chess_load::Chess_load(QWidget *parent,Pet * pet) :
    QMainWindow(parent),
    ui(new Ui::Chess_load)
{
    ui->setupUi(this);
    this->pet = pet ;

    qDebug()<< pet->money ;

    setWindowTitle("选择对战模式");
    setFixedSize(550,600);
    //添加窗口图片
    label = new QLabel( this ) ;
    //主题样式
    label->setStyleSheet({"border-image:url(:/new/prefix1/resource/qqPet.png)"});
    label->setAutoFillBackground(true);
    label->setFixedSize(100,100);
    label->move(225,245);
    label->show();
}

Chess_load::~Chess_load()
{
    delete ui;
}

void Chess_load::on_btPeople_clicked()
{
    chess = new chessForm() ;
    chess->show() ;
    hide() ;
}
//设置背景
void Chess_load::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/mywindow.jpg"));
}
//设置鼠标的形状
void Chess_load::mouseMoveEvent(QMouseEvent* event)
{
    QPoint mousepos = event->pos();
    //当鼠标在整个界面上的时候，改变鼠标的形状
    if(mousepos.x() > 0 && mousepos.x() < width() && mousepos.y() > 0 && mousepos.y() < height())
    {
        QCursor *myCursor=new QCursor(QPixmap(":/new/prefix1/resource/mouse.png"),0,0);
        this->setCursor(*myCursor);
    }
    else
    {
        this->setCursor(Qt::ArrowCursor);      //在范围之外变回原来形状
    }
}


//选择人机对战
void Chess_load::on_btQ_clicked()
{
    widget = new MyWidget(NULL,pet) ;
    widget->show() ;
    hide() ;
}
