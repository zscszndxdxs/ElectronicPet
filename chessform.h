#ifndef CHESSFORM_H
#define CHESSFORM_H
#include<QLabel>
#include <QWidget>
#include<chess.h>
#include<QGridLayout>
#include<QPushButton>
namespace Ui {
class chessForm;
}

class chessForm : public QWidget
{
    Q_OBJECT

public:
    explicit chessForm(QWidget *parent = nullptr);
    void Init() ;
    ~chessForm();
    void paintEvent( QPaintEvent* ev) ;


private:
    Ui::chessForm *ui;
    Chess* chess1 ;

    QLabel *label1 ;
    QLabel *label2 ;
    //返回到主界面
    QPushButton* back ;
public slots:
    void backToRoom() ;


};

#endif // CHESSFORM_H
