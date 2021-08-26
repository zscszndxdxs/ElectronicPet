#ifndef CHESS_H
#define CHESS_H
#include<QPainter>
#include <QWidget>
#include<QPen>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QVector>
#include<QPoint>
#include<chesspiece.h>
#include<QPushButton>
#include<QLabel>
#include<QMovie>
#include<QMainWindow>
#include<QMouseEvent>
#include<QSound>
class Chess : public QMainWindow
{
    Q_OBJECT
public:
    explicit Chess(QWidget *parent = nullptr);
    ~Chess() ;
    void paintEvent( QPaintEvent* ev) ;
    QPen pen ;
    //void resizeEvent( QResizeEvent* ev) ;
    void mousePressEvent(QMouseEvent* ev ) ;
    void mouseMoveEvent(QMouseEvent* event) ;
private:
    int width ;
    int height;
    int x ,y ;
       bool is_black ;
    void drawMouseChess() ; //画鼠标上的棋子

    //在棋子的状态函数中画出棋子的颜色和位置
    void drawPoint(QPainter &painter ,QPoint &point ) ;
    //定义棋子的个数
    QVector<Chesspiece> chess ;
    void drawChess() ;//画出棋盘上的棋子状态
    //判断五子棋周围
    int CountNear(Chesspiece item , QPoint pt) ;
    //退出按钮
    QPushButton *button1 ;

QLabel *label1 ;
QLabel *label2 ;
QSound *sounds4;

signals:
void backToRoom() ;


public slots:



};

#endif // CHESS_H
