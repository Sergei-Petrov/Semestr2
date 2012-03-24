#pragma once

#include <QWidget>
#include "Action.h"

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

signals:
    void value(QString);

public slots:
    void first(int);
    void second(int);
    void oper(QString);
    void act();

private:
    int u_first;
    int u_second;
    QString u_oper;
    Ui::Calculator *ui;
};

