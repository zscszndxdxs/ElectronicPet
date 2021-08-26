#include "window.h"
#include<QLabel>
#include "Windows.h"
#include<QMovie>
#include<QDebug>
Window::Window(Pet* pet)

{

    //添加音乐
    sounds2 = new QSound(":/new/prefix2/music/qq3.wav") ;
    sounds2->play() ;


    //定义当前宠物对象
    this->pet = pet ;
    //宠物图像
    QLabel* label=new QLabel(this);
    QMovie* movie=new QMovie(":/new/prefix1/resource/qq5.gif") ;
    //我把窗口设置为透明
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setAttribute(Qt::WA_TranslucentBackground);
    //宠物Label
    label->setMovie(movie);
    label->setFixedSize(150,150);
    label->move(25,25);
    label->setScaledContents(true);
    movie->start();
    //id_6 = startTimer( 4000 ) ;
    //宠物元气值增加机制
     timer9 = new QTimer(this) ;
     timer9->start(2000) ;
     connect( timer9, &QTimer::timeout,[=](){
     pet->setMood( pet->getMood() + 1) ;
     if( pet->getMood() >= 100 ){

       QMessageBox::information( NULL , "提示界面" , "Q小鹅的活力满满，请带它回去吧~" ,QMessageBox::Yes) ;
       timer9->stop() ;
     }

     }) ;


}
//将宠物显示到桌面上
void Window::mousePressEvent(QMouseEvent *e){
    if(e->button()==Qt::RightButton){
        //如果是右键，关闭窗口
        timer9->stop() ;
         close() ;

    }else if(e->button()==Qt::LeftButton){

    }
}

//鼠标左键长按拖动宠物位置
void Window::mouseMoveEvent(QMouseEvent* e){
     if(e->buttons() & Qt::LeftButton){
         move(e->globalPos().x()-point.x() - 95  , e->globalPos().y()-point.y() - 95 );
     }
}



