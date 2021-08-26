#ifndef PLAYROOM_H
#define PLAYROOM_H
#include "pet.h"
#include <QWidget>
#include<QLabel>
#include<QTimer>
#include<QLineEdit>
#include<QPushButton>
#include<QPainter>
#include "Windows.h"
#include<window.h>
#include<QMainWindow>
#include<chess.h>
#include<chess_load.h>
#include<QPoint>
#include<QMouseEvent>
#include<QSound>
#include<QTimerEvent>
#include<QMessageBox>
#include<garden.h>
class Playroom : public QMainWindow
{
    Q_OBJECT
public:
    explicit Playroom(QWidget *parent = nullptr);
    void setClock(int time);  //更新时间
    void paintEvent(QPaintEvent*);
    //void keyPressEvent(QKeyEvent*);
    //void keyReleaseEvent(QKeyEvent*);
   // void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent*e);
    //void mouseMoveEvent( QMouseEvent* event ) ;
    //void mouseReleaseEvent(QMouseEvent* event ) ;
    void timerEvent(QTimerEvent* e) ;

signals:
    void backToBegin();
    void restart();


private:
    //显示宠物的数值状态
    QLabel *healthLabel,*hungerLabel ;

    //宠物信息
    QLabel *nameLabel,*stateLabel;
    //界面操作
    QPushButton *eatBt,*cureBt;
    //死亡后，重新开始按钮
    QPushButton* restartBt;
    Pet* pet ;
    QLabel *label ;
    QLabel *labelPet ;
    QLabel *labelCat ;
    QPushButton* _chess ;
    QLabel *zs ;
    QLabel *zs0 ;
    //重写动图事件
    QLabel *label1 ;
    QLabel *label2 ;
    //跳转到加载界面
    Chess_load* chessload ;
    //显示时钟标签
    QLabel* labelTime ;
    //设计播放器
    QSound *sounds ;
    int id_1 ;//定时器1
    int id_2;//定时器2
    int id_3 ;//定时器3
    int id_4 ;//定时器4
    int id_5 ;//定时器5，用来刷新界面，更新宠物的金币，元气值与心情值
    QLabel *moneyLabel ;
    QLabel* moodLabel , *activeLabel ;
    QPushButton* exitBt ;

public slots:
    void _chess_click() ;
    void _play_click() ;
    void _ga_click();
    void _exit_click() ;
};

#endif // PLAYROOM_H
