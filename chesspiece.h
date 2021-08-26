#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include<QPoint>

class Chesspiece
{
public:
    Chesspiece();
    Chesspiece( QPoint p , bool isBlack) ;

    bool operator==(const Chesspiece&t ) const
    {
        return ( (p == t.p)&&( color == t.color)   ) ;
    }

    QPoint p ;//点的位置
    //颜色是否是黑色的
    bool color ;

};

#endif // CHESSPIECE_H










