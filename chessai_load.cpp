#include "chessai_load.h"
#include "ui_chessai_load.h"

ChessAI_load::ChessAI_load(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessAI_load)
{
    ui->setupUi(this);
}

ChessAI_load::~ChessAI_load()
{
    delete ui;
}
