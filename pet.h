#ifndef PET_H
#define PET_H
#include<QString>

class Pet
{
public:
    Pet();
    void setName(QString name);
    void setState(QString state);
    void setMood(int mood);
    void setHealth(int health);
    void setHunger(int hunger);
    void setActive(int active);
    QString getName();
    QString getState();
    int getMood();
    int getHealth();
    int getHunger();
    int getActive();
    int money = 60 ; //设置为共有对象
    QString user1 =  "CSU";
private:

    QString name="Q小鹅";  //昵称
    QString state="健康";   //状态
    int  weight= 8;     //体重
    int  mood = 60 ;       //心情
    int health= 60;      //健康
    int hunger= 60 ;    //饥饿度
    int active= 60 ;      //元气值

};

#endif // PET_H
