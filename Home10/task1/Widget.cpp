#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
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
            ch.addX(i);
            if (ch.check(i))
            {
                end();
                return;
            }
            if (ch.count == 9)
            {
                end();
                ui->label->setText("Draw!!!");
            }
        }
        buttons[i]->blockSignals(true);
    }
    else
    {
        buttons[i]->setText("O");
        if (!buttons[i]->signalsBlocked())
        {
            ch.addO(i);
            if (ch.check(i))
            {
                end();
                return;
            }
        }
        buttons[i]->blockSignals(true);
    }
    current = !current;
}

void Widget::restart()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[i]->setEnabled(true);
        buttons[i]->blockSignals(false);
        buttons[i]->setText("");
    }
    ui->label->setText("");
    current = true;
    ch.restart();
}



void Widget::end()
{
    if (!current)
        ui->label->setText("Circle won!!!");
    else
        ui->label->setText("Crosses won!!!");
     for (int i = 0; i < 9; i++)
         buttons[i]->setEnabled(false);
}
