#ifndef EVELUATION_H
#define EVELUATION_H

#define GRID_NUM 15     //每一行（列）的棋盘交点数
#define GRID_COUNT 225  //棋盘上交点总数
#define BLACK 1         //黑棋用1表示
#define WHITE 2         //白棋用2表示
// 这组宏定义了用以代表几种棋型的数字
#define STWO 1  //眠二
#define STHREE 2//眠三
#define SFOUR 3 //冲四
#define TWO 4   //活二
#define THREE 5 //活三
#define FOUR 6  //活四
#define FIVE 7  //五连
#define NOTYPE 11
#define ANALSISEN 255   //已分析过的
#define TOBEANALSIS 0   //已分析过的
extern int PosValue[15][15];    //棋子位置价值表

class MaxValue
{
public:
    MaxValue();
    virtual ~MaxValue();
    /*估值函数 ，对传入的棋盘打分.bIsWhiteTurn标明轮到谁走棋*/
    int CalScore(int position[][GRID_NUM],bool bIsWhiteTurn);
protected:
    /* 分析水平方向上某点及其周边的棋型*/
    int AnalysisHorizon(int position[][GRID_NUM], int i, int j);
    /*分析垂直方向上某点及其周边的棋型*/
    //存放全部结构的数组，三个维度
   int TypeRecord[GRID_NUM][GRID_NUM][4];
   /*存放统记过的分析结果的数组*/
   int TypeCount[3][20];
    int AnalysisVertical(int position[][GRID_NUM], int i, int j);
    /*分析左斜45度方向上某点及其周边的棋型*/
    int AnalysisLeft(int position[][GRID_NUM], int i, int j);
    /*分析右斜45度方向上某点及其周边的棋型*/
    int AnalysisRight(int position[][GRID_NUM], int i, int j);
    /*分析给定行上某点及其周边的棋型*/
    int AnalysisLine(int *position, int GridNum, int StonePos);
    /*存放AnalysisLine分析结果的数组*/
    int m_LineRecord[30];

};

#endif // EVELUATION_H
