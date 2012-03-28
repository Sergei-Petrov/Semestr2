#include "Calculator.h"
#include "ui_Calculator.h"
#include "Action.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator), digMap(new QSignalMapper), opMap(new QSignalMapper),
    first(0), u_oper(" "), str(""), second(0)
{
    ui->setupUi(this);
    for(int i = 0; i < 10; ++i)
    {
        digit[i] = new QPushButton(QString::number(i), this);
        digMap->setMapping(digit[i], i);
        connect(digit[i], SIGNAL(clicked()), digMap, SLOT(map()));
    }

    sign[0] = new QPushButton("+", this);
    opMap->setMapping(sign[0], "+");
    sign[1] = new QPushButton("-", this);
    opMap->setMapping(sign[1], "-");
    sign[2] = new QPushButton("*", this);
    opMap->setMapping(sign[2], "*");
    sign[3] = new QPushButton("/", this);
    opMap->setMapping(sign[3], "/");
    sign[4] = new QPushButton("=", this);
    opMap->setMapping(sign[4], "=");
    sign[5] = new QPushButton("C", this);
    opMap->setMapping(sign[5], "C");
    for(int i = 0; i < 6; i++)
    {
        connect(sign[i], SIGNAL(clicked()), opMap, SLOT(map()));
    }

    connect(digMap, SIGNAL(mapped(int)), this, SLOT(firstOrSecond(int)));
    connect(opMap, SIGNAL(mapped(QString)), this, SLOT(oper(QString)));
    connect(this, SIGNAL(value(QString)), ui->lineEdit, SLOT(setText(QString)));

    for(int i = 0; i < 9; ++i)
        ui->gridLayout->addWidget(digit[i + 1], i / 3, i % 3);
    for(int i = 0; i < 4; i++)
        ui->gridLayout->addWidget(sign[i], i, 3);
    ui->gridLayout->addWidget(sign[4], 3, 2);
    ui->gridLayout->addWidget(sign[5], 3, 1);
    ui->gridLayout->addWidget(digit[0], 3, 0);
}

Calculator::~Calculator()
{
    for(int i = 0; i < 10; i++)
        delete digit[i];
    for(int i = 0; i < 6; i++)
        delete sign[i];
    delete ui;
    delete digMap;
    delete opMap;
}

void Calculator::firstOrSecond(int x)
{
    if (u_oper == " " )
    {
        first = first * 10 + x;
        str.push_back(QString::number(x));
        emit value(str);
    }
    else
    {
        second = second * 10 + x;
        str.push_back(QString::number(x));
        emit value(str);
    }
}

void Calculator::oper(QString s)
{
    if (s == "C")
    {
        u_oper = ' ';
        first = 0;
        second = 0;
        str = "";
        emit (value("0"));
        return;
    }

    first = Action::operate(first, second, u_oper);
    second = 0;

    if (s == "=")
    {
        u_oper = " ";
        str.push_back(s);
        str.push_back(QString::number(first));
        emit value(str);
        str = "";
        first = 0;
    }
    else
    {
        if ((s == "*" || s == "/") && check(str))
        {
            str.push_back(")");
            str.push_front("(");
        }
        u_oper = s;
        str.push_back(s);
        emit value(str);
    }
}

bool Calculator::check(QString str)
{
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '+' || str[i] == '-')
            return true;
    return false;
}
