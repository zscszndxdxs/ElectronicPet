#ifndef REGISTER_H
#define REGISTER_H
#include <QMainWindow>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QTextCodec>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlDatabase>
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>
#include<QCoreApplication>
#include<pet.h>
#include<QPainter>
namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void paintEvent(QPaintEvent* ev);

private slots:
    void on_btOk_clicked(bool);

private:
    Ui::Register *ui;

    Pet *pet ;
};

#endif // REGISTER_H
