#include "Slider.h"
#include "ui_Slider.h"

Slider::Slider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slider)
{
    ui->setupUi(this);
    ui->horizontalScrollBar->setValue(0);
    ui->progressBar->setValue(0);
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

Slider::~Slider()
{
    delete ui;
}
