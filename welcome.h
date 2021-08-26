#ifndef WELCOME_H
#define WELCOME_H
#include<QPushButton>
#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>
#include<QLabel>
#include<QMovie>
#include<playroom.h>
#include<pet.h>
namespace Ui {
class Welcome;
}

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();
    void paintEvent(QPaintEvent *e) ;
    Playroom* p ;

private:
    Ui::Welcome *ui;
    QPushButton* begin ;
    QLabel *labelQ ;

    Pet* pet ;

public slots:
    void begin_click() ;






};

#endif // WELCOME_H
