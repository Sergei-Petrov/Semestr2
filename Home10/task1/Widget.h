#pragma once
#include <QtGui>
#include "CheckWin.h"

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
    CheckWin ch;
    
private:
    Ui::Widget *ui;

    void end();

public slots:
    void click(int i);
    void restart();
};
