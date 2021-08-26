#include "login.h"
#include "ui_login.h"
#include<QPainter>
#include<pet.h>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    //添加音乐
    sounds1 = new QSound(":/new/prefix2/music/qq5.wav") ;
    sounds1->play() ;


    ui->setupUi(this);
    //设置窗口为无边框形状
   // this->setWindowFlag(Qt::FramelessWindowHint);
    setWindowTitle("欢迎来到我的宠物");
    setFixedSize(550,600);
    //添加窗口图片
    label = new QLabel( this ) ;
    //主题样式
    label->setStyleSheet({"border-image:url(:/new/prefix1/resource/qqPet.png)"});
    label->setAutoFillBackground(true);
    label->setFixedSize(100,100);
    label->move(450,500);
    label->show();
    //连接注册界面
   // connect(ui->btRegister,SIGNAL(clicked()) , this,SLOT(on_btRegister_clicked())) ;
    //连接主卧室
    //connect(ui->btLogin,SIGNAL(clicked(bool)) , this,SLOT(on_btLogin_clicked())) ;

}
//设置登录界面背景颜色
//设置登录界面颜色
void Login::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/Login1.jpg"));
}


Login::~Login()
{
    delete ui;
}
//点击注册按钮，实现注册
void Login::on_btRegister_clicked()
{
    w = new Register(this) ;
    w->show() ;
}
//登录请求
void Login::on_btLogin_clicked()
{
        sounds1->stop() ;
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("qt");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        //ODBC查询数据
        QSqlQuery query ;
        QString account = ui->lineEditAccount->text() ;
        QString password = ui->lineEditPassword->text() ;

        //查询密码是否正确
        bool success = false ;
        query.exec(QString("select* from %1 where account = '%2' AND password = '%3'").arg("user").arg(account).arg(password)) ;
        if( query.next()){
            qDebug()<<"登录成功";
            success = true ;
        }
        else {
            qDebug() << "密码错误" ;
        }
        if( success){
            QMessageBox::information( NULL , "登录状态" , "登录成功！" ,QMessageBox::Yes) ;
            welcome = new Welcome(NULL) ;
            welcome->show() ;
            hide() ;
        }else{
            QMessageBox::information( NULL , "登录状态" , "密码错误！" ,QMessageBox::Yes) ;
        }
        //pet->user1 = account;
}

