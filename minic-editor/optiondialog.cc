#include "optiondialog.h"
#include "ui_optiondialog.h"
#include <QDebug>
OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_chooseScanBtn_clicked()
{
    qDebug() << "打开文件对话框选择词法扫描器路径" << endl;
}

void OptionDialog::on_chooseGenTreeBtn_clicked()
{
    qDebug() << "打开文件对话框选择语法生成器路径" << endl;
}

void OptionDialog::on_buttonBox_accepted()
{
    qDebug() << "应用所作更改" << endl;
}
