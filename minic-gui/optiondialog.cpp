/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic/minic-editor/optiondialog.cc
 * @Description: 设置界面类
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-05-08 11:47:38
 * @LastEditTime: 2020-06-19 08:41:50
 * @LastEditors: Liang Zehao
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

OptionDialog::OptionDialog(CmdPath* cpaths, QWidget* parent) :QDialog(parent),
ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    paths = cpaths;
    ui->scanPathEdit->setText(paths->minicPath);
    ui->genTreePathEdit->setText(paths->tmPath);
}
OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_chooseScanBtn_clicked()
{
    qDebug() << "打开文件对话框选择minic编译器程序路径" << endl;
    QString fn = QFileDialog::getOpenFileName(this, tr("选择minic编译器程序路径"), 
        paths->minicPath, 
        tr("所有文件(*);;exe,out或app可执行程序(*.exe *.out *.app)"));
    if (fn.isEmpty()) {
        QMessageBox::warning(this,"minic", "未选择文件");
        return;
    }
    ui->scanPathEdit->setText(fn);
}

void OptionDialog::on_chooseGenTreeBtn_clicked()
{
    qDebug() << "打开文件对话框选择tiny虚拟机程序路径" << endl;
    QString fn = QFileDialog::getOpenFileName(this, tr("选择tiny虚拟机程序路径"), 
       paths->minicPath, 
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
    paths->minicPath=ui->scanPathEdit->text();
    paths->tmPath=ui->genTreePathEdit->text();
}
