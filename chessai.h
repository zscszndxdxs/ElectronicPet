#ifndef CHESSAI_H
#define CHESSAI_H
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
#include<QDebug>
#include<QMessageBox>
class ChessAI : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChessAI(QWidget *parent = nullptr);
    ~ChessAI() ;
    void paintEvent( QPaintEvent* ev) ;
    QPen pen ;
    //void resizeEvent( QResizeEvent* ev) ;
    void mousePressEvent(QMouseEvent* ev ) ;
    void mouseMoveEvent(QMouseEvent* event) ;
    private:
    int width ;
    int height;
    int x ,y ;
    void drawMouseChess() ; //画鼠标上的棋子
    bool is_black ;
    //在棋子的状态函数中画出棋子的颜色和位置
    void drawPoint(QPainter &painter ,QPoint &point ) ;
    //定义棋子的个数
    QVector<Chesspiece> chess ;
    void drawChess() ;//画出棋盘上的棋子状态
    //判断五子棋周围
    int CountNear(Chesspiece item , QPoint pt) ;
signals:

public slots:
};

#endif // CHESSAI_H
