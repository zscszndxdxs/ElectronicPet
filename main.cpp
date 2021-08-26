#include "login.h"
#include <QApplication>
#include<playroom.h>
#include<chess.h>
#include<chess_load.h>
#include<window.h>
#include<chessform.h>
#include<welcome.h>
#include<chessai.h>
#include "mywidget.h"
#include <garden.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //以下注释掉的都是测试代码
     Login w;
     w.show();
      // Playroom p;
     //p.show();
     // Chess ch ;
      //ch.show();
    //Chess_load w ;
    //w.show() ;
//    Window w;
//    w.show() ;
  //   chessForm w ;
//     w.show() ;
//      Welcome w ;
//      w.show() ;
     //   MyWidget w ;
       // w.show() ;
       //Garden w ;
       //w.show() ;




    return a.exec();
}
