#include "judge.h"
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>
#include<QWidget>

Judge::Judge(AiChess* parent , Pet * pet ):
    AiChess (parent)

{
    this->pet=  pet ;
    //测试是否可以准确输出得到的宠物信息
    qDebug()<<pet->money;
    qDebug()<<pet->money;
    qDebug()<<pet->money;
    qDebug()<<pet->money;
    qDebug()<<pet->money;

}





void Judge::click(int row, int col)
{
    if(m_RenjiBoard[row][col] == 0 && _bBlackTurn)
    {
        AiChess::click(row, col);
        if(isWin(row, col))
        {
            pet->money = pet->money + 10  ;
            QMessageBox::information(this, "主人获胜", "恭喜你赢了,你将获得十个金币！", QMessageBox::Ok);
            for(int row=0; row<GRID_NUM; row++)
            {
                for(int col=0; col<GRID_NUM;col++)
                {
                    m_RenjiBoard[row][col] = 0;
                }
            }
            update();
        }
    }
    if(!_bBlackTurn)
    {
        QTimer::singleShot(10, this, SLOT(computerMove()));
    }
}


void Judge::saveStep(int row, int col, QVector<Postion*>& steps)
{
    Postion* step = new Postion;
    step->_colTo = col;
    step->_rowTo = row;
    steps.append(step);
}

void Judge::getAllPossibleMove(QVector<Postion *> &steps)
{
    for(int row=0; row<GRID_NUM; row++)
    {
        for(int col=0; col<GRID_NUM; col++)
        {
            if(m_RenjiBoard[row][col] != 0)
            {
                continue;
            }
            saveStep(row, col, steps);

        }
    }
}

void Judge::fakeMove(Postion* step)
{
    if(_bBlackTurn)
    {
        m_RenjiBoard[step->_rowTo][step->_colTo] = BLACK;
    }
    else
    {
        m_RenjiBoard[step->_rowTo][step->_colTo] = WHITE;
    }
    _bBlackTurn = !_bBlackTurn;
}
void Judge::unfakeMove(Postion* step)
{
    m_RenjiBoard[step->_rowTo][step->_colTo] = 0;
    _bBlackTurn = !_bBlackTurn;
}

//评价局面分数
int Judge::calcScore()
{
    int blackTotalScore = 0;
    int whiteTotalScore = 0;
    static int PosValue[GRID_NUM][GRID_NUM]=
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
        {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
        {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
        {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
        {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
        {0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
        {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
        {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
        {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
        {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
        {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };

    for(int row=0; row<GRID_NUM; row++)
    {
        for(int col=0; col<GRID_NUM; col++)
        {
            if(m_RenjiBoard[row][col] == BLACK)
            {
                blackTotalScore += PosValue[row][col];
            }
            else if(m_RenjiBoard[row][col] == WHITE)
            {
                whiteTotalScore += PosValue[row][col];
            }
        }
    }
    return whiteTotalScore - blackTotalScore;
}

int Judge::getMaxScore(int level, int curMinScore)
{
    if(level == 0)
    {
        return m_pEvel->CalScore(m_RenjiBoard,!_bBlackTurn);
    }
    //看看棋盘上哪些地方是空余的
    QVector<Postion*> steps;
    getAllPossibleMove(steps);
    int maxScore = -100000;
    while(steps.count())
    {
        Postion* step = steps.back();
        steps.removeLast();
        fakeMove(step);
        int score = getMinScore(level-1, maxScore);
        unfakeMove(step);
        delete step;

        if(score >= curMinScore)
        {
            while(steps.count())
            {
                Postion* step = steps.back();
                steps.removeLast();
                delete step;
            }
            return score;
        }
        if(score > maxScore)
        {
            maxScore = score;
        }
    }
    return maxScore;
}

int Judge::getMinScore(int level, int curMaxScore)
{
    if(level == 0)
    {
        return m_pEvel->CalScore(m_RenjiBoard,!_bBlackTurn);
    }
    QVector<Postion*> steps;
    getAllPossibleMove(steps);
    int minScore = 100000;
    while(steps.count())
    {
        Postion* step = steps.back();
        steps.removeLast();
        fakeMove(step);
        int score = getMaxScore(level-1, minScore);
        unfakeMove(step);
        delete step;
        if(score <= curMaxScore)
        {
            //剪枝
            while(steps.count())
            {
                Postion* step = steps.back();
                steps.removeLast();
                delete step;
            }
            return score;
        }

        if(score < minScore)
        {
            minScore = score;
            //ret = step;
        }

    }
    return minScore;
}

Postion* Judge::getBestMove()
{
    QVector<Postion*> steps;
    getAllPossibleMove(steps);  //看看有哪些步骤可以走

    //尝试走这条路径
    int maxScore = -1000000;
    Postion* ret = NULL;
    while(steps.count())
    {
        Postion* step = steps.back();
        steps.removeLast();
        fakeMove(step);
        qDebug() << m_nSelectedPly << endl;
        int score = getMinScore(m_nSelectedPly-1, maxScore);
        //qDebug() << m_nSelectedPly << endl;
        unfakeMove(step);
        if(score > maxScore)
        {
            maxScore = score;
            if(ret)
            {
                delete ret;
            }
            ret = step;
        }
        else
        {
            delete step;
        }
    }
    //我们获得最好的情况，加到棋盘上去
    return ret;
}

void Judge::computerMove()
{
    Postion* step = getBestMove();
    m_RenjiBoard[step->_rowTo][step->_colTo] = WHITE;
    if(isWin(step->_rowTo, step->_colTo))
    {
        pet->money = pet->money - 3 ;
        QMessageBox::information(this, "宠物获胜", "对不起，你输了，你将减少3个金币", QMessageBox::Ok);
        for(int row=0; row<GRID_NUM; row++)
        {
            for(int col=0; col<GRID_NUM;col++)
            {
                m_RenjiBoard[row][col] = 0;
            }
        }
        update();
    }
    _bBlackTurn = !_bBlackTurn;
    delete step;
    update();
}

bool Judge::isWin(int row, int col)
{
     return JudgeVertical(row, col) || JudgeHorizon(row, col) || JudgeLeft(row, col) || JudgeRight(row ,col);
}



//判断垂直方向上是否有五连子
bool Judge::JudgeVertical(int row, int col)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(col - i >= 0 && col + 4 - i <= GRID_NUM &&
           m_RenjiBoard[row][col - i] == m_RenjiBoard[row][col + 1 - i] &&
           m_RenjiBoard[row][col - i] == m_RenjiBoard[row][col + 2 - i] &&
           m_RenjiBoard[row][col - i] == m_RenjiBoard[row][col + 3 - i] &&
           m_RenjiBoard[row][col - i] == m_RenjiBoard[row][col + 4 - i])
        {
            return true;
        }
    }
    return false;
}


//判断右斜方向上是否有五连子
bool Judge::JudgeRight(int row, int col)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(row + i <= GRID_NUM && col - i >= 0 &&
           row - 4 + i >= 0 && col + 4 - i <= GRID_NUM &&
           m_RenjiBoard[row + i][col - i] == m_RenjiBoard[row - 1 + i][col + 1 - i] &&
           m_RenjiBoard[row + i][col - i] == m_RenjiBoard[row - 2 + i][col + 2 - i] &&
           m_RenjiBoard[row + i][col - i] == m_RenjiBoard[row - 3 + i][col + 3 - i] &&
           m_RenjiBoard[row + i][col - i] == m_RenjiBoard[row - 4 + i][col + 4 - i])
           return true;
    }
    return false;
}



//判断水平方向上是否有五连子
bool Judge::JudgeHorizon(int row, int col)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(row - i >= 0 && row + 4 - i <= GRID_NUM &&
           m_RenjiBoard[row - i][col] == m_RenjiBoard[row + 1 - i][col] &&
           m_RenjiBoard[row - i][col] == m_RenjiBoard[row + 2 - i][col] &&
           m_RenjiBoard[row - i][col] == m_RenjiBoard[row + 3 - i][col] &&
           m_RenjiBoard[row - i][col] == m_RenjiBoard[row + 4 - i][col])
           return true;
    }
    return false;
}
//判断左斜方向上是否有五连子
bool Judge::JudgeLeft(int row, int col)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(row - i >= 0 &&
           col - i >= 0 &&
           row + 4 - i <= 0xF &&
           col + 4 - i <= 0xF &&
           m_RenjiBoard[row - i][col - i] == m_RenjiBoard[row + 1 - i][col + 1 - i] &&
           m_RenjiBoard[row - i][col - i] == m_RenjiBoard[row + 2 - i][col + 2 - i] &&
           m_RenjiBoard[row - i][col - i] == m_RenjiBoard[row + 3 - i][col + 3 - i] &&
           m_RenjiBoard[row - i][col - i] == m_RenjiBoard[row + 4 - i][col + 4 - i])
           return true;
    }
    return false;
}

