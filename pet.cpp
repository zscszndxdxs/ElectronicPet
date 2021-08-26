#include "pet.h"

Pet::Pet()
{

}

void Pet::setName(QString name){
    this->name=name;
}

void Pet::setState(QString state){
     this->state=state;
}



void Pet::setMood(int mood){
    this->mood=mood;
}

void Pet::setHealth(int health){
    this->health=health;
}

void Pet::setHunger(int hunger){
    this->hunger=hunger;
}

void Pet::setActive(int active){
    this->active=active;
}


QString Pet::getName(){
    return name;
}

QString Pet::getState(){
    return state;
}


int Pet::getMood(){
    return mood;
}

int Pet::getHealth(){
    return health;
}

int Pet::getHunger(){
    return hunger;
}

int Pet::getActive(){
    return active;
}

