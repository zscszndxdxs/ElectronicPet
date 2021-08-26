#ifndef WINDOW_H
#define WINDOW_H
#include<QDialog>
#include<pet.h>
#include<QMouseEvent>
#include<QTimer>
#include<QPoint>
#include<QTimer>
#include<QTimerEvent>
#include<playroom.h>
#include<QSound>
class Window : public QDialog
{
    Q_OBJECT
public:
    //实现宠物移动
    Window(Pet* pet=nullptr);
    QTimer *timer ;
    void mousePressEvent(QMouseEvent* e );
    void mouseMoveEvent( QMouseEvent* e ) ;
    //void timerEvent( QTimerEvent* e) ;
signals:
    void back() ;
private:
    QPoint point ;
    Pet* pet ;//设置宠物
   // int id_6 ;
    QTimer * timer9 ;
    QSound *sounds2;

};

#endif // WINDOW_H
