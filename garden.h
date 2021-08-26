#ifndef GARDEN_H
#define GARDEN_H

#include <QMainWindow>
#include <pet.h>
#include <QPaintEvent>
#include<QLabel>
#include<QMouseEvent>
#include<QMovie>
#include<QVBoxLayout>
#include<QDebug>
#include<QTime>
#include <QMessageBox>
#include<QTimer>
#include <QPushButton>
namespace Ui {
class Garden;
}

class Garden : public QMainWindow
{
    Q_OBJECT

public:
    explicit Garden(QWidget *parent = nullptr,Pet* pet = nullptr);
    ~Garden();
    void paintEvent(QPaintEvent *e) ;
     void mousePressEvent(QMouseEvent *e) ;
private:
    QLabel *label8 ;
    QLabel *label9 ;
    //植物选择按钮，一共有三个
    QPushButton* xiangrikui1 ;
    QPushButton* mantianxing ;
    QPushButton* yinghua ;
    //种植植物
    QLabel *labelXiangrikui1 ;
    QLabel *labelMantianxing ;
    QLabel *labelYinghua;
    Pet* pet ;

    //判断植物是否种植
    bool is_xiangrikui1 = false;
    bool is_mantianxing = false;
    bool is_yinghua = false;
    QTimer *t1;
    QTimer *t2 ;
    QTimer *t3;
    QPushButton* back ;


public slots:
       void xiangrikui1_click() ;
       void mantianxing_click() ;
       void yinghua_click();
       void back_click() ;

};

#endif // GARDEN_H
