#pragma once
#include <QtGui>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *buttons[9];
    QSignalMapper *Map;
    bool current;
    short count;
    short table[3][3];
    
private:
    Ui::Widget *ui;
    void checkWin(int i);
    bool horizont(int tmp);
    bool vertical(int tmp);
    bool diagonals();
    void end();

public slots:
    void click(int i);
    void restart();
};
