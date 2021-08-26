#ifndef MYWIDGET_H
#define MYWIDGET_H
#include<pet.h>
#include <QWidget>
#include "judge.h"
#include <QPushButton>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#define GRID_NUM 15     //每一行（列）的棋盘交点数
#define GRID_COUNT 225  //棋盘上交点总数
#define BLACK 1         //黑棋用1表示
#define WHITE 2         //白棋用2表示


namespace Ui {


class MyWidget;

             }

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0, Pet* pet=  0 );
    ~MyWidget();
    void kaishi();
    void val();
    void  paintEvent(QPaintEvent *e) ;
protected:

    int m_nStoneColor = BLACK;  //定义用户的棋子颜色为黑色
private slots:

private:
    Ui::MyWidget *ui;
    Judge* b;
    //添加宠物图片
    QLabel *pic ;
    QLabel* label;
    Pet* pet ;
};

#endif // MYWIDGET_H
