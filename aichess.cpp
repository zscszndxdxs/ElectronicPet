#include "aichess.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QMovie>
#include <QTimer>
AiChess::AiChess(QWidget *parent) :
    QWidget(parent)
{
    //qDebug()<< pet->money ;
    this->setWindowTitle("人机大战");
    this->_r = 20;
    setFixedSize(1000,800);
    back = new QPushButton("", this);
    //返回到主界面
    //设置按钮格式
    back->move(900,720);
    back->setStyleSheet({"border-image:url(:/new/prefix1/resource/back.png)"});
    back->setAutoFillBackground(true);
    back->setFixedSize(60,60);
    back->show() ;
    connect(back, &QPushButton::clicked, this, &AiChess::InvertRenjiBoard);
    connect(back, &QPushButton::clicked, this, &AiChess::sendSlot);
    //将宠物绘制到棋盘上
    la=new QLabel(this);
    QMovie* moive1=new QMovie(":/new/prefix1/resource/qq.gif");
    la->setMovie(moive1);
    moive1->start();
    la->setScaledContents(true);
    la->setFixedSize(100,100);
    la->move(800,110);
    //初始化棋盘
    for(int row=0; row<GRID_NUM; row++)
    {
        for(int col=0; col<GRID_NUM;col++)
        {
            m_RenjiBoard[row][col] = 0; //初始化棋盘
        }
    }

}

void AiChess::InvertRenjiBoard()
{//重绘棋盘
    for(int row=0; row<GRID_NUM; row++)
    {
        for(int col=0; col<GRID_NUM;col++)
        {
            m_RenjiBoard[row][col] = 0;
        }
    }
    update();
}

void AiChess::sendSlot()
{
    emit from_board_to_mywidgetSignal();    //将棋盘收到的信号发送给选择窗口处理
}

void AiChess::paintEvent(QPaintEvent *)
{



    //将图片渲染到桌面上
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/chessBoard.jpg"));

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    int d = 50 ;
    for(int i=1; i<16; i++)
    {
        painter.drawLine(QPoint(d, i*d), QPoint(15*d, i*d));
        painter.drawLine(QPoint(i*d, d), QPoint(i*d, 15*d));
    }
    painter.save();
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    for(int row=0; row<GRID_NUM; row++)
    {
        for(int col=0; col<GRID_NUM; col++)
        {
            if(m_RenjiBoard[row][col] == 1)
            {
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(center(row, col), _r-2, _r-2);
            }
            else if(m_RenjiBoard[row][col] == 2)
            {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(center(row, col), _r-2, _r-2);
            }

        }
    }
    painter.restore();
    update();
}

QPoint AiChess::center(int row, int col)
{//返回棋盘行列对应的像素坐标
    QPoint ret;
    ret.rx() = (col+1)* _r*2.5;
    ret.ry() = (row+1)* _r*2.5;
    return ret;
}

bool AiChess::getRowCol(QPoint pt, int &row, int &col)
{//得到此时对应棋盘的行和列
    for(row=0; row<16; row++)
    {
        for(col=0; col<16; col++)
        {
            QPoint distance = center(row, col) - pt;
            if(distance.x() * distance.x() + distance.y() * distance.y() < _r * _r)
                return true;
        }
    }
    return false;
}

void AiChess::click(int row, int col)
{
    if(m_RenjiBoard[row][col] == 0)
    {//防止重复落子
        m_RenjiBoard[row][col] = BLACK;
        _bBlackTurn = !_bBlackTurn;
    }
}

void AiChess::click(QPoint pt)
{

    int row = 0;
    int col = 0;
    bool bRet = getRowCol(pt, row, col);
    if(bRet == false)
    {
        //如果点落到棋盘外，就退出
        return;
    }
    click(row, col);
}

void AiChess::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() != Qt::LeftButton)
    {
        return;
    }
    click(ev->pos());
}

