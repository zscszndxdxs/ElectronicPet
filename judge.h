#ifndef SINGLEGAME_H
#define SINGLEGAME_H
#include "aichess.h"
#include "maxvalue.h"
#include<pet.h>
class Judge : public AiChess
{
    Q_OBJECT
public:
    Judge(AiChess *parent = 0 , Pet* pet = 0 );
    virtual void click(int row, int col);
    Postion* getBestMove();
    void getAllPossibleMove(QVector<Postion*>& steps);
    void fakeMove(Postion* step);
    int m_nSelectedPly = 1;
    bool isWin(int row, int col);
    bool JudgeVertical(int row, int col);
    bool JudgeHorizon(int row, int col);
    bool JudgeLeft(int row, int col);
     int getMaxScore(int level, int curMinScore);
    bool JudgeRight(int row, int col);
    void unfakeMove(Postion* step);
    int calcScore();
    void saveStep(int row, int col, QVector<Postion*>& steps);
    int m_nUserStoneColor = BLACK;//记住用户棋子的颜色
    int getMinScore(int level, int curMaxScore);


public slots:
    void computerMove();
protected:
    MaxValue *m_pEvel = new MaxValue;    //估分指针
    Pet* pet ;
};

#endif // SINGLEGAME_H
