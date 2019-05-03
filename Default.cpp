#include "Default.h"
#include "ui_Default.h"

Default::Default(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Default)
{
    ui->setupUi(this);
}

Default::~Default()
{
    delete ui;
}
