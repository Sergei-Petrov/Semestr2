#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    count = 0;
    current = true;

    ui->cmd->setText("New Game");
    connect(ui->cmd, SIGNAL(clicked()), this, SLOT(restart()));

    QSignalMapper *Map = new QSignalMapper(this);
    connect(Map, SIGNAL(mapped(int)), this, SLOT(click(int)));
    for (int i = 0; i < 9; i++)
    {
        buttons[i] = new QPushButton("", this);
        Map->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), Map, SLOT(map()));
    }

    for (int i = 0; i < 9; i++)
        ui->gridLayout->addWidget(buttons[i], i / 3, i % 3);
}

Widget::~Widget()
{
    delete ui;
    for (int i = 0; i < 9; ++i)
        delete buttons[i];
    delete Map;
}

void Widget::click(int i)
{
    if (current)
    {
        buttons[i]->setText("X");
        if (!buttons[i]->signalsBlocked())
        {
            table[i / 3][i % 3] = 1;
            checkWin(i);
        }
        //buttons[i]->setEnabled(false);
        buttons[i]->blockSignals(true);
    }
    else
    {
        buttons[i]->setText("O");
        if (!buttons[i]->signalsBlocked())
        {
            table[i / 3][i % 3] = 0;
            checkWin(i);
        }
        //buttons[i]->setEnabled(false);
        buttons[i]->blockSignals(true);
    }
    current = !current;
}

void Widget::restart()
{
    for (int i = 0; i < 9; i++)
    {
        table[i / 3][i % 3] = -1;
        buttons[i]->setEnabled(true);
        buttons[i]->blockSignals(false);
        buttons[i]->setText("");
    }
    ui->label->setText("");
    count = 0;
    current = true;
}

void Widget::checkWin(int i)
{
    count++;
    if (horizont(i % 3) || vertical(i / 3) || diagonals())
    {
        if (table[i / 3][i % 3] == 0)
            ui->label->setText("Circle won!!!");
        else
            ui->label->setText("Crosses won!!!");
        end();
        return;
    }
    if (count == 9)
        ui->label->setText("Draw!!!");
}

bool Widget::horizont(int tmp)
{
    if (table[0][tmp] == -1)
        return false;
    for (int i = 1; i < 3; i++)
        if (table[i][tmp] != table[0][tmp])
            return false;
    return true;
}

bool Widget::vertical(int tmp)
{
    if (table[tmp][0] == -1)
        return false;
    for (int i = 1; i < 3; i++)
        if (table[tmp][i] != table[tmp][0])
            return false;
    return true;
}

bool Widget::diagonals()
{
    if (table[1][1] == -1)
        return false;
    int tmp = table[1][1];
    if (table[0][0] == tmp && table[2][2] == tmp)
        return true;
    if (table[0][2] == tmp && table[2][0] == tmp)
        return true;
    return false;
}

void Widget::end()
{
     for (int i = 0; i < 9; i++)
         buttons[i]->setEnabled(false);
}
