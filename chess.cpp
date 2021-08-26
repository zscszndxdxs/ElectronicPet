#include "chess.h"
#include<QDebug>
#include<QMessageBox>



Chess::Chess(QWidget *parent) : QMainWindow(parent)
{

    setWindowTitle("人人对战");
    setFixedSize(800,800);
    is_black = true ;
    //播放音乐
    sounds4 = new QSound(":/new/prefix2/music/qq4.wav") ;
    sounds4->play();

}
//棋盘析构函数
Chess::~Chess()
{


}

//重写绘图事件
void Chess::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/chessBoard.jpg"));
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine) ;
    pen.setWidth( 2 ) ;
    p.setPen( pen ) ;
    //画矩形
    for( int i = 0 ; i <= 14 ; i ++){
        for( int j = 0 ; j < 15 ; j ++ ){
            //四个参数分别是左上角位置，长宽
           p.drawRect(  ( i +0.5  )*50, (j + 0.5 )*50,50,50 ) ;

        }


    }



//     for( int i =0 ; i <= 14 ; i ++ ){
//        p.drawLine( x ,y+i*height ,x+ 14*width ,y+ i*height ) ;
//        p.drawLine(x+ i*width ,y , x+i*width ,y+ 14*height ) ;

//      }
     //设置棋子颜色
      drawMouseChess() ;
      drawChess() ;
      update() ;





}
void Chess::drawChess()
{
    QPainter p(this);
   //遍历棋子容器
    for( int i = 0 ; i < chess.size(); i ++ )
    {
        Chesspiece chess1 = chess[ i ] ; //第i个棋子
        //如果是黑色
        if(chess1.color){
            p.setBrush(Qt::black) ;

        }else {
            p.setBrush(Qt::white) ;
    }
    //获取棋子位置
    QPoint ptCenter((chess1.p.x() + 0.5 )*50 ,(chess1.p.y() +0.5 )*50 ) ;
    p.drawEllipse(ptCenter, 20 ,20 ) ;
    }
}
void Chess::drawMouseChess()
{
QPainter p( this ) ;
if( is_black )
{
    p.setBrush(Qt::black) ;
}
else {
    p.setBrush(Qt::white) ;
}
//设置棋子形状
p.drawEllipse(mapFromGlobal(QCursor::pos()), 20 ,20 ) ;
}


void Chess::mousePressEvent(QMouseEvent*e)
{
   qDebug() << e->pos() << endl ;
   QPoint pt ;
   pt.setX((e->pos().x())/50 ) ;
   pt.setY( (e->pos().y())/50 ) ;
   //判断位置是否有棋子
   for( int i = 0  ; i < chess.size() ;i ++ )
   {
       //本棋子
       Chesspiece ch = chess[ i ] ;
       if( ch.p == pt ){
           return ;
       }

   }
//如果不存在，规则判断并绘图
    Chesspiece item( pt , is_black ) ;
    chess.append( item ) ;//将棋子追加到容器后
//判断五子棋是否连接，达成规则

int  nLeft = CountNear(item , QPoint(-1,0));
int nLeftUp  = CountNear(item , QPoint(-1,-1));
int nUp  = CountNear(item , QPoint(0,-1));
int nLeftDown  = CountNear(item , QPoint(-1,1));
int nRight = CountNear(item , QPoint(1,0)) ;
int nRightUp = CountNear(item , QPoint(1,-1));
int nRightDown = CountNear(item , QPoint(1,1));
int nDown =CountNear(item , QPoint(0,1)) ;

if(( nLeft + nRight )>= 4||(nLeftUp + nRightDown )>=4||(nUp + nDown )>= 4|| (nRightUp+nLeftDown >= 4 ))
{
    QString str = is_black?"黑棋获胜":"白棋获胜" ;
    QMessageBox::information( NULL , "游戏结束" , str ,QMessageBox::Yes) ;
    chess.clear() ;
    return ;
}
//切换棋子
if( is_black ){
    is_black = false ;
}else {
    is_black = true;
}
}

int Chess::CountNear(Chesspiece item, QPoint pt){

    int nCount = 0 ;
    item.p += pt ;
    while (chess.contains(item)) {
        nCount ++ ;
        item.p+= pt ;

    }
    return nCount ;

}

//在整个棋盘上改变鼠标形状
//设置鼠标的形状
void Chess::mouseMoveEvent(QMouseEvent* event)
{
        QPoint mousepos = event->pos();
        //当鼠标在整个界面上的时候，改变鼠标的形状
        QCursor *myCursor=new QCursor(QPixmap(":/new/prefix1/resource/mouse.png"),0,0);
        this->setCursor(*myCursor);
}
