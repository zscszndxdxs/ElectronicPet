#ifndef CHESS_LOAD_H
#define CHESS_LOAD_H
#include<chess.h>
#include <QMainWindow>
#include<QLabel>
#include<chessform.h>
#include<QMouseEvent>
#include<pet.h>
#include<mywidget.h>
namespace Ui {
class Chess_load;
}

class Chess_load : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chess_load(QWidget *parent = nullptr,Pet* pet = nullptr);
    ~Chess_load();
    void paintEvent(QPaintEvent *e) ;
    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent* event) ;
private slots:
    void on_btPeople_clicked();

    void on_btQ_clicked();

private:
    Ui::Chess_load *ui;
    QLabel* label ;
    chessForm* chess ;
    MyWidget* widget ;
    Pet* pet ;

};

#endif // CHESS_LOAD_H
