#ifndef STEP_H
#define STEP_H

#include <QObject>

class Postion : public QObject
{
public:
    Postion(QObject *parent = 0);
    ~Postion();
    int _rowTo;
    int _colTo;
};

#endif // STEP_H
