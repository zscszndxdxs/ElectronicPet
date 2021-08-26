#include "playroom.h"
#include<QMovie>
#include<QVBoxLayout>
#include<QDebug>
#include<QTime>
#include<QSqlQuery>
Playroom::Playroom(QWidget *parent) :QMainWindow(parent)

{
     pet = new Pet() ;

     //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("qt");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    //申请按钮
    exitBt =new QPushButton(this) ;
    cureBt=new QPushButton(this);
    eatBt = new QPushButton(this) ;
    //设计宠物治疗按钮样式
    cureBt->move(233,185);
    cureBt->setStyleSheet({"border-image:url(:/new/prefix1/resource/dazhen1.png)"});
    cureBt->setAutoFillBackground(true);
    cureBt->setFixedSize(85,85);
    cureBt->show() ;
    //设计宠物喂食按钮样式
    eatBt->move(238,240);
    eatBt->setStyleSheet({"border-image:url(:/new/prefix1/resource/chifan1.png)"});
    eatBt->setAutoFillBackground(true);
    eatBt->setFixedSize(80,80);
    eatBt->show() ;
     //设计退出按钮格式
    exitBt->move(1100,560);
    exitBt->setStyleSheet({"border-image:url(:/new/prefix1/resource/back.png)"});
    exitBt->setAutoFillBackground(true);
    exitBt->setFixedSize(80,80);
    exitBt->show() ;
        connect(exitBt,SIGNAL(clicked()) , this,SLOT( _exit_click() )) ;
    //获取当前系统的时间
    QTime curTime=QTime::currentTime();
    //实现播放音乐
     sounds = new QSound(":/new/prefix2/music/q.wav") ;
     sounds->play() ;
     pet = new Pet() ;
     setWindowTitle("主卧室");
     setFixedSize(1200,650);
     labelTime= new QLabel(this) ;
     labelTime->setStyleSheet( {"border-image:url(:/new/prefix1/resource/timer1.png)  ;font-weight:bold"} );
     labelTime->setAutoFillBackground(true);
     labelTime->setFixedSize(120,120);
     labelTime->move(250, 40);
     labelTime->setText( ("   " + (curTime.toString()))  ) ;
     labelTime->show();
     //设计定时器，每1秒刷新一次
     startTimer(1000) ;

     //设置装饰物品
     zs = new QLabel( this ) ;
     //主题样式
     zs->setStyleSheet({"border-image:url(:/new/prefix1/resource/zs.png)"});
     zs->setAutoFillBackground(true);
     zs->setFixedSize(110,110);
     zs->move(300,450);
     zs->show();
     //添加窗口图片
     label = new QLabel( this ) ;
     //主题样式
     label->setStyleSheet({"border-image:url(:/new/prefix1/resource/qqPet.png)"});
     label->setAutoFillBackground(true);
     label->setFixedSize(110,110);
     label->move(95,450);
     label->show();
     //添加宠物
     labelCat= new QLabel(this) ;
     labelCat->setStyleSheet({"border-image:url(:/new/prefix1/resource/ok1.png)"});
     labelCat->setAutoFillBackground(true);
     labelCat->setFixedSize(130,130);
     labelCat->move(520, 120);
     labelCat->show();
     //我的gif图片
     label1=new QLabel(this);
     QMovie* moive1=new QMovie(":/new/prefix1/resource/qq.gif");
     label1->setMovie(moive1);
     moive1->start();
     label1->setScaledContents(true);
     label1->setFixedSize(110,110);
     label1->move(300,400);
    //我的第二张gif图片
     label2=new QLabel(this);
     QMovie* moive2=new QMovie(":/new/prefix1/resource/qq5.gif");
     label2->setMovie(moive2);
     moive2->start();
     label2->setScaledContents(true);
     label2->setFixedSize(100,100);
     label2->move(1034,300);
     //自定义控件类型
    _chess = new QPushButton("",this) ;
    //设置按钮格式
    _chess->move(760,490);
    _chess->setStyleSheet({"border-image:url(:/new/prefix1/resource/wuziqi.png)"});
    _chess->setAutoFillBackground(true);
    _chess->setFixedSize(150,150);
    _chess->show() ;
    //连接到下棋界面
    connect(_chess,SIGNAL(clicked()) , this,SLOT( _chess_click() )) ;
    //定义一个到户外散步的按钮
    QPushButton* bt = new QPushButton("",this) ;
    //设置按钮格式
    bt->move(30,50);
    bt->setStyleSheet({"border-image:url(:/new/prefix1/resource/playtowindow.png)"});
    bt->setAutoFillBackground(true);
    bt->setFixedSize(130,120);
    bt->show() ;
    connect(bt,SIGNAL(clicked()),this,SLOT(_play_click()));

    //定义一个花园按钮
    QPushButton* ga = new QPushButton("",this) ;
    //设置按钮格式
    ga->setStyleSheet({"border-image:url(:/new/prefix1/resource/zs2.png)"});
    ga->setAutoFillBackground(true);
    ga->setFixedSize(160,140);
    ga->move(124,295);
    ga->show();
    connect(ga,SIGNAL(clicked()),this,SLOT(_ga_click()));

    //跳转到桌面


    //以下是对宠物信息进行显示
    //显示宠物的数值状态
    moodLabel=new QLabel("",this);
    healthLabel=new QLabel("",this);
    hungerLabel=new QLabel("",this);
    activeLabel=new QLabel("",this);
    moneyLabel = new QLabel("" ,this );

    //查询数据库中的信息，将其从数据库转出
    QSqlQuery query1 ;
    bool success = query1.exec(QString("select* from user where account = '%1'").arg("CSU") );
    if(success){
        qDebug()<< "ok";
    }

    query1.first() ;

    qDebug()<< query1.value(7).toInt() ;



    pet->money = query1.value(5).toInt() ;
    pet->setMood( query1.value(6).toInt() ) ;
    pet->setHealth( query1.value(7).toInt() ) ;
    pet->setActive(query1.value(8).toInt() ) ;
    pet->setHunger( query1.value(9).toInt() ) ;
    pet->setState( query1.value(10).toString() ) ;

   qDebug() << pet->money;

    //设置金钱数量
    moneyLabel->setStyleSheet({"border-image:url(:/new/prefix1/resource/shuxing.png);font: 20px/1.5 '华文彩云';color:rgb(57,61,73);font-weight:bold"});
    moneyLabel->setAutoFillBackground(true);
    moneyLabel->setFixedSize(125,125);
    moneyLabel->move(70,520);
    int m2 = pet->money ;
    qDebug() << m2;
    QString s8 = QString::number( m2 );
    moneyLabel->setText("  金币: " + s8 ) ;
    moneyLabel->show();
    //设置心情指标
    moodLabel->setStyleSheet({"border-image:url(:/new/prefix1/resource/shuxing.png);font: 20px/1.5 '华文彩云';color:rgb(57,61,73);font-weight:bold"});
    moodLabel->setAutoFillBackground(true);
    moodLabel->setFixedSize(125,90);
    moodLabel->move(870, 1);
    int a = pet->getMood() ;
    QString s = QString::number(a);
    moodLabel->setText("  心情: " + s ) ;
    moodLabel->show();
    //设置健康指标
    healthLabel->setStyleSheet({"border-image:url(:/new/prefix1/resource/shuxing.png);font: 20px/1.5 '华文彩云';color:rgb(57,61,73);font-weight:bold"});
    healthLabel->setAutoFillBackground(true);
    healthLabel->setFixedSize(125,90);
    healthLabel->move(870, 40);
    int b = pet->getHealth() ;
    QString s1 = QString::number(b);
    healthLabel->setText("  健康: " + s1 ) ;
    healthLabel->show();
    //设置能量指标
    hungerLabel->setStyleSheet({"border-image:url(:/new/prefix1/resource/shuxing.png);font: 20px/1.5 '华文彩云';color:rgb(57,61,73);font-weight:bold"});
    hungerLabel->setAutoFillBackground(true);
    hungerLabel->setFixedSize(125,90);
    hungerLabel->move(870, 80);
    int c = pet->getHunger() ;
    QString s2 = QString::number(c);
    hungerLabel->setText("  能量: " + s2 ) ;
    hungerLabel->show();
    //设置元气指标
    activeLabel->setStyleSheet({"border-image:url(:/new/prefix1/resource/shuxing.png);font: 20px/1.5 '华文彩云';color:rgb(57,61,73);font-weight:bold"});
    activeLabel->setAutoFillBackground(true);
    activeLabel->setFixedSize(125,90);
    activeLabel->move(870, 120);
    int d = pet->getActive() ;
    QString s3 = QString::number(d);
    activeLabel->setText("  元气: " + s3 ) ;
    activeLabel->show();
      //显示宠物昵称
     nameLabel= new QLabel(this) ;
     nameLabel->setStyleSheet( {"border-image:url(:/new/prefix1/resource/name1.png)  ;font: 20px/1.5 '华文彩云';font-weight:bold"} );
     nameLabel->setAutoFillBackground(true);
     nameLabel->setFixedSize(125,100);
     nameLabel->move(525, 460);
     nameLabel->setText( ("   " + ( pet->getName()  )) ) ;
     nameLabel->show();
     //显示宠物状态
     stateLabel = new QLabel(this) ;
     stateLabel->setStyleSheet({"border-image:url(:/new/prefix1/resource/shuxing.png);font: 20px/1.5 '华文彩云';color:#D24D57;font-weight:bold"});
     stateLabel->setAutoFillBackground(true);
     stateLabel->setFixedSize(140,125);
     stateLabel->move(513, 512);
     stateLabel->setText("  状态: " + pet->getState() ) ;
     stateLabel->show();
     //点至了治疗按钮的话
     connect(cureBt,&QPushButton::clicked,[=](){
         if(pet->getHealth()){
             QTimer::singleShot(1000,this,[=](){
                 if(pet->getHealth()<5){
                     pet->setHealth(pet->getHealth()+1);
                 }
                  update();
             });
         }
     });
    //宠物能量减少机制
    QTimer * timer3 = new QTimer(this) ;
    timer3->start(200000) ;
    connect( timer3, &QTimer::timeout,[=](){
    int a = pet->getHunger() - 1 ;
    pet->setHunger(a) ;
    int c = pet->getHunger() ;
    QString s2 = QString::number(c);
    hungerLabel->setText("  能量: " + s2 ) ;

    if( (c <= 30)&&pet->getMood() ){
         pet->setState("饥饿") ;
        stateLabel->setText("  状态: " + pet->getState() ) ;
        update() ;
    }
    if( (pet->getHunger() <= 45)&&(pet->getHunger()>= 30 ) ){
           QMessageBox::information( NULL , "提示界面" , "你的宠物太饿了，请给它补充能量吧~" ,QMessageBox::Yes) ;
    }

    }) ;


    //宠物能量增加机制
    connect(eatBt,&QPushButton::clicked,[=](){
        QMessageBox::information( NULL , "提示界面" , "你确定要花费你的一个金币来为Q小鹅补充能量吗?" ,QMessageBox::Yes) ;
        if((pet->getHealth())&&(pet->getHunger()<=100)){
                    int m1 =  pet->getHunger() + 1 ;
                    pet->setHunger( m1 ) ;
                    QString s2 = QString::number( m1 );
                    hungerLabel->setText("  能量: " + s2 ) ;
                    pet->money = pet->money - 1 ;
                    QString s3 = QString::number( pet->money  ) ;
                    moneyLabel->setText("  金币: " + s3);
                    update();
        }
    });

    //宠物健康增加机制
    connect(cureBt,&QPushButton::clicked,[=](){
        QMessageBox::information( NULL , "提示界面" , "你确定要花费你的五个金币来治疗Q小鹅吗?" ,QMessageBox::Yes) ;
                    int m22 =  pet->getHealth() + 5 ;
                    pet->setHealth( m22 ) ;
                    QString s66 = QString::number( m22 ) ;
                    healthLabel->setText("  健康: " + s66 ) ;
                    pet->money = pet->money - 5 ;
                    QString s99 = QString::number( pet->money  ) ;
                    moneyLabel->setText("  金币: " + s99);
                    update();
    });
//    //宠物心情降低机制,设置为timer5主要是可以控制其开始与结束
    QTimer * timer5 = new QTimer(this) ;
    timer5->start(80000) ;
    connect( timer5, &QTimer::timeout,[=](){
    int a1 = pet->getMood() - 1 ;
    pet->setMood(a1) ;
    int c1 = pet->getMood() ;
    QString s10 = QString::number(c1);
    moodLabel->setText("  心情: " + s10 ) ;

    if(c1 <= 30 ){
         pet->setState("低落") ;
        stateLabel->setText("  状态: " + pet->getState() ) ;
        update() ;
    }
    if( pet->getMood()<=30 ){
           QMessageBox::information( NULL , "提示界面" , "你的宠物心情有点低落哦，快带Q小鹅去外面玩会吧~" ,QMessageBox::Yes) ;
    }

    }) ;
    //设置宠物心情减少和元气减少的定时器定义为十分钟减少一次
    id_1  = startTimer( 100000 ) ;//实际为600000
    //设置宠物健康减少的定时器,定义为每25分钟减少1
    id_2 = startTimer( 100000 ) ;//实际为1500000
    //设置宠物能量减少的定时器，定义为每60分钟减少10
    id_5 = startTimer( 1000) ;

}




void Playroom::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/resource/bedroom.png"));

}

void Playroom::_chess_click()
{
//    chess = new Chess() ;
//    chess->show() ;
//  //  close() ;
    QMessageBox::information( NULL , "提示界面" , "你想要去和Q小鹅PK棋艺吗?    " ,QMessageBox::Yes) ;
    chessload = new Chess_load( this , pet );
    chessload->show() ;
    //关闭音乐
    sounds->stop() ;
    //sounds4->play() ;
}

void Playroom::mousePressEvent(QMouseEvent *e){

        //当鼠标左键点击时.
        if (e->button() == Qt::RightButton)
        {
            QMovie* moive3=new QMovie(":/new/prefix1/resource/qq5.gif");
            label2->setMovie(moive3);
            moive3->start();
            label2->setScaledContents(true);
            label2->setFixedSize(100,100);
            label2->move(e->pos().x() - 30,e->pos().y() - 30);

        }
}

void Playroom::_play_click()
{
    QMessageBox::information( NULL , "提示界面" , "每玩耍10分钟，Q小鹅的元气值就会加5哦~" ,QMessageBox::Yes) ;
   Window* w = new Window(pet) ;
   sounds->stop() ;
   w->show() ;
}
void Playroom::_ga_click()
{
    QMessageBox::information( NULL , "提示界面" , "你想要去Q小鹅的后花园吗?" ,QMessageBox::Yes) ;
    Garden* w = new Garden(NULL ,pet );
    w->show() ;
}






//重写时间获取事件,动态实时地获取当前时间，并不断刷新
void Playroom::timerEvent(QTimerEvent* e){
    QTime curTime=QTime::currentTime();
    labelTime->setText( ("   " + (curTime.toString()))  )  ;
    if(e->timerId() == id_1){

        //设置元气减少机制
        int a2 = pet->getActive() - 1 ;
        pet->setActive( a2 ) ;
        int c22 = pet->getActive() ;
        QString s11 = QString::number( c22 ) ;
        activeLabel ->setText("  元气: " + s11 ) ;
    }
    //设置宠物健康减少机制，对元气，活力，能量做一个加权处理
     if(e->timerId() == id_2){
          int a3 = pet->getHealth() - 1 ;
          pet->setHealth( a3 ) ;
          healthLabel->setText("  健康: " + QString::number( pet->getHealth() ) ) ;
          if( (pet->getHealth() <=30)&&(pet->getHealth() > 0 ) ){
              pet->setState("生病") ;
             stateLabel->setText("  状态: " + pet->getState() ) ;
             QMessageBox::information( NULL , "提示界面" , "你的宠物生病了，快去治疗它吧~" ,QMessageBox::Yes) ;
          }
          if( pet->getHealth() == 0 ){
              QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "警告！", "你的宠物已经死亡，是否马上复活",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                     pet->setMood( 60 );
                     pet->setState("健康") ;
                     pet->setActive( 60 );
                     pet->setHealth( 60 ) ;
                     pet->setHunger( 60 );
                     pet->money = 60;

                  qDebug() << "Yes was clicked";
                } else {
                  qDebug() << "Yes was *not* clicked";
                }






          }




    }
     if( e->timerId() == id_5 ){
       activeLabel ->setText("  元气: " + QString::number( pet->getActive() ) ) ;
          moodLabel->setText("  心情: " + QString::number( pet->getMood() ) ) ;
             moneyLabel->setText("  金币: " + QString::number( pet->money ) ) ;
             update() ;
             //7.22日更新内容


























     }
}



//退出按钮
void Playroom::_exit_click(){
    //将宠物信息存入数据库
    QSqlQuery query ;
    query.prepare(QString("update user set mood=? ,health = ?,hunger = ?,active = ?,money = ?,state = ? where account='%1'").arg("CSU"));

            query.bindValue(0,QString::number(pet->getMood()));
            query.bindValue(1,QString::number(pet->getHealth()));
            query.bindValue(2,QString::number(pet->getHunger()));
            query.bindValue(3,QString::number(pet->getActive()));
            query.bindValue(4,QString::number(pet->money));
            query.bindValue(5,pet->getState());
            if( query.exec()){
                qDebug()<< "success" ;
            }
            else{
                qDebug() <<"fali";
            }
    close() ;
}






