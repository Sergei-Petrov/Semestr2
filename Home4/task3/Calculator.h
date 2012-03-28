#pragma once

#include <QWidget>
#include <QSignalMapper>
#include <QPushButton>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
    QPushButton *digit[10];
    QPushButton *sign[6];
    bool check(QString);

signals:
    void value(QString);

public slots:
    void firstOrSecond(int);
    void oper(QString);
    
private:
    Ui::Calculator *ui;
    QSignalMapper *digMap;
    QSignalMapper *opMap;
    int first;
    QString u_oper;
    QString str;
    int second;
};

