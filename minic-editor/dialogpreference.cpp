#include "dialogpreference.h"
#include "ui_dialogpreference.h"

DialogPreference::DialogPreference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPreference)
{
    ui->setupUi(this);
}

DialogPreference::~DialogPreference()
{
    delete ui;
}
