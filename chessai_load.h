#ifndef CHESSAI_LOAD_H
#define CHESSAI_LOAD_H

#include <QMainWindow>

namespace Ui {
class ChessAI_load;
}

class ChessAI_load : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChessAI_load(QWidget *parent = nullptr);
    ~ChessAI_load();

private:
    Ui::ChessAI_load *ui;
};

#endif // CHESSAI_LOAD_H
