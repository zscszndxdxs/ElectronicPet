#include "register.h"
#include "ui_register.h"
#include<QMessageBox>
Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowTitle("快来领养一个宠物吧~");
    setFixedSize(435,551);
   // connect(ui->btOk,SIGNAL(clicked(bool)) , this,SLOT(on_btOk_clicked())) ;
}

Register::~Register()
{
    delete ui;
}



//如果点击了提交按钮
void Register::on_btOk_clicked(bool)
{
    pet = new Pet() ;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("qt");
        db.setUserName("root");
        db.setPassword("ok");
        bool ok = db.open();
        //ODBC查询数据
        QSqlQuery query ;
        QString name = ui->lineEditName->text() ;
        QString account = ui->lineEditAccount->text() ;
        QString password = ui->lineEditPassword->text() ;
        QString mail = ui->lineEditMail->text() ;
        QString t = "60";
        //查询用户名是否存在
        bool success1=false;
        query.exec(QString("select * from %1 where account='%2'").arg("user").arg(account));
        if(query.next())
        {
            QMessageBox::information( NULL , "注册窗口" , "该账号已被注册！" ,QMessageBox::Yes) ;
            qDebug()<<QObject::tr("该账号已被注册 ");
            success1=true;
        }
        else
        {

            qDebug()<<QObject::tr("该账号可以注册");
            query.prepare(QString("insert into user(name,account,password,mail,money,mood,health,hunger,active,state) values(?,?,?,?,?,?,?,?,?,?)") );
            query.bindValue(0,name);
            query.bindValue(1,account);
            query.bindValue(2,password);
            query.bindValue(3,mail);
             //7.22日改进代码开始
            query.bindValue(4,t);
            query.bindValue(5,t);
            query.bindValue(6,t);
            query.bindValue(7,t);
            query.bindValue(8,t);
            query.bindValue(9,"健康");
              //7.22日改进结束



            bool success=query.exec();
            if(!success)
            {
                QMessageBox::information( NULL , "注册窗口" , "注册失败！" ,QMessageBox::Yes) ;
            }
            else{
                QMessageBox::information( NULL , "注册窗口" , "注册成功！" ,QMessageBox::Yes) ;
                qDebug()<<QString(QObject::tr("注册成功"));
            }
               close();




        }




}


//重写绘图事件
void Register::paintEvent(QPaintEvent *ev)
{
        QPainter p(this);
        p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/register1.jpg"));
}







