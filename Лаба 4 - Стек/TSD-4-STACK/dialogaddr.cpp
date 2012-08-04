#include "dialogaddr.h"
#include "ui_dialogaddr.h"

DialogAddr::DialogAddr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogAddr)
{
    ui->setupUi(this);
}

void DialogAddr::setText(QString text) {
    ui->textEdit->setText(text);
}

DialogAddr::~DialogAddr()
{
    delete ui;
}
