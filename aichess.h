#ifndef BOARD_H
#define BOARD_H
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QPoint>
#include <QPointer>
#include "position.h"
#include <pet.h>
#define GRID_NUM 15     //每一行（列）的棋盘交点数
#define GRID_COUNT 225  //棋盘上交点总数
#define BLACK 1         //黑棋用1表示
#define WHITE 2         //白棋用2表示
class AiChess : public QWidget
{
    Q_OBJECT
public:
    explicit AiChess(QWidget *parent = 0);
    void sendSlot();
    void InvertRenjiBoard();//重绘棋盘

    int m_RenjiBoard[GRID_NUM][GRID_NUM];   //棋盘数组，用于显示棋盘
    bool _bBlackTurn = 1;   //黑棋先走

    int _r = 20;//棋子的半径

    void paintEvent(QPaintEvent *);//绘制棋盘
    void mouseReleaseEvent(QMouseEvent *);

    QPoint center(int row, int col);//返回棋盘行列对应的像素坐标
    bool getRowCol(QPoint pt, int &row, int &col);//得到此时对应棋盘的行和列
    void click(QPoint pt);
  virtual  void click(int row, int col);
protected:
      Pet* pet ;

signals:
    void from_board_to_mywidgetSignal();

public slots:
private:
    QPushButton *back;

    int m_nUserStoneColor = BLACK;
    QLabel * la ;//用户棋子的颜色

};

#endif // BOARD_H
