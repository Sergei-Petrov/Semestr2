#include "Calculator.h"
#include "ui_Calculator.h"
#include "iostream"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator), u_first(0), u_second(0), u_oper("+")
{
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("/");
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            this, SLOT(first(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            this, SLOT(second(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(oper(QString)));
    connect(this, SIGNAL(value(QString)), ui->lineEdit, SLOT(setText(QString)));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::first(int x)
{
    u_first = x;
    act();
}

void Calculator::second(int x)
{
    u_second = x;
    act();
}

void Calculator::oper(QString x)
{
    u_oper = x;
    act();
}

void Calculator::act()
{
    int tmp = Action::operate(u_first, u_second, u_oper);
    emit value(QString::number(tmp));
}
