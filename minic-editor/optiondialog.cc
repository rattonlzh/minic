/**
 * @file optiondialog.cc
 * @author Liang Zehao
 * @brief 偏好设置对话框的类定义文件
 * 
 * @version 0.1
 * @date 2020-05-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "optiondialog.h"
#include "ui_optiondialog.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
}

OptionDialog::OptionDialog(CmdPath* cpaths, QWidget *parent):QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    paths = cpaths;
    ui->scanPathEdit->setText(paths->scanPath);
    ui->genTreePathEdit->setText(paths->genTreePath);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_chooseScanBtn_clicked()
{
    qDebug() << "打开文件对话框选择词法扫描器路径" << endl;
    QString fn = QFileDialog::getOpenFileName(this, tr("选择词法扫描器程序路径"), 
        paths->scanPath, 
        tr("所有文件(*);;exe,out或app可执行程序(*.exe *.out *.app)"));
    if (fn.isEmpty()) {
        QMessageBox::warning(this,"minic", "未选择文件");
        return;
    }
    ui->scanPathEdit->setText(fn);
}

void OptionDialog::on_chooseGenTreeBtn_clicked()
{
    qDebug() << "打开文件对话框选择语法生成器路径" << endl;
    QString fn = QFileDialog::getOpenFileName(this, tr("选择语法树生成器路径"), 
       paths->scanPath, 
       tr("所有文件(*);;exe,out或app可执行程序(*.exe *.out *.app)"));

    if (fn.isEmpty()) {
        QMessageBox::warning(this,"minic", "未选择文件");
        return;
    }
    ui->genTreePathEdit->setText(fn);
}

void OptionDialog::on_buttonBox_accepted()
{
    qDebug() << "应用所作更改" << endl;
    paths->scanPath=ui->scanPathEdit->text();
    paths->genTreePath=ui->genTreePathEdit->text();
}
