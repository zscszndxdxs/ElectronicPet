#include "chessform.h"
#include "ui_chessform.h"

chessForm::chessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chessForm)
{
    ui->setupUi(this);
     chess1 = new Chess() ;

    //将棋盘加入到里面去
      ui->gridLayout->addWidget(chess1) ;
       setWindowTitle("人人对战");
        setFixedSize(1200,920);

         //我的gif图片
         label1=new QLabel(this);
         QMovie* moive1=new QMovie(":/new/prefix1/resource/qq.gif");
         label1->setMovie(moive1);
         moive1->start();
         label1->setScaledContents(true);
         label1->setFixedSize(100,100);
         label1->move(60,460);
         //我的第二张gif图片
         label2=new QLabel(this);
         QMovie* moive2=new QMovie(":/new/prefix1/resource/qq5.gif");
         label2->setMovie(moive2);
         moive2->start();
         label2->setScaledContents(true);
         label2->setFixedSize(110,110);
         label2->move(1030,450);
         //返回到主界面
         back = new QPushButton("" ,this ) ;
         //设置按钮格式
         back->move(1100,840);
         back->setStyleSheet({"border-image:url(:/new/prefix1/resource/back.png)"});
         back->setAutoFillBackground(true);
         back->setFixedSize(60,60);
         back->show() ;

         //返回到主卧室界面
         connect(back,SIGNAL(clicked()) , this,SLOT( backToRoom() )) ;



}

chessForm::~chessForm()
{
    delete ui;
}

void chessForm::Init(){

}

void chessForm::paintEvent(QPaintEvent *ev) {

    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/login.jpg"));


}

//返回到主卧室界面
void chessForm::backToRoom(){
      this->close() ;
}
//重写鼠标移动事件




























