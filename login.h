#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include<QLabel>
#include<register.h>
#include<playroom.h>
#include<welcome.h>
#include<pet.h>
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    void paintEvent(QPaintEvent *e);

private slots:
    void on_btRegister_clicked();

    void on_btLogin_clicked();

private:
    Ui::Login *ui;
    QLabel *label ;
    //连接到注册界面
    Register* w ;
    //Playroom* p ;
    //连接到欢迎界面
    Welcome* welcome ;
    //Pet* pet;
    QSound *sounds1 ;

};
#endif // LOGIN_H
