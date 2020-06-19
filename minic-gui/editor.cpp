/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic/minic-gui/editor.cpp
 * @Description: minic 编辑器的主界面
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-05-08 11:47:38
 * @LastEditTime: 2020-06-19 09:31:15
 * @LastEditors: Liang Zehao
 */ 

 
#include "editor.h"
#include "ui_editor.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include "optiondialog.h"
#include <QSettings>


Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Editor) {
    ui->setupUi(this);
    init();
}


void Editor::init() {
    QPalette palette;
    QPixmap pixmap("bg.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
fileName = QCoreApplication::applicationDirPath()+"/autosaved.mc";
    //Qt中使用QSettings类读写ini文件   
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省   
    QSettings config("minic.ini", QSettings::IniFormat);  
    cmdpath.minicPath = config.value("minic", 
                                    QCoreApplication::applicationDirPath()
                                    +"/minic.exe").toString();
    cmdpath.tmPath = config.value("tm", 
                                       QCoreApplication::applicationDirPath()
                                       +"/tm.exe").toString();
}

Editor::~Editor() {
    QSettings config("minic.ini", QSettings::IniFormat);  
    config.setValue("minic", cmdpath.minicPath);
    config.setValue("tm", cmdpath.tmPath);
    config.sync();
    delete ui;
}


void Editor::on_scannerBtn_clicked() {
    save();
    call(tr("scan"));
    qDebug() << "词法扫描按钮被点击" << endl;

}
void Editor::call(QString bin) {
    QProcess p(0);
//    根据bin的值调用相应的命令
    if (bin == tr("scan")) {
        p.start(cmdpath.minicPath, QStringList() 
                << fileName << "-s");
    }else if (bin == tr("parse")) {
        p.start(cmdpath.minicPath, QStringList() 
                << fileName << "-p");
    }
    else if (bin == tr("analyze")) {
        p.start(cmdpath.minicPath, QStringList()
            << fileName << "-a");
    }
    else if (bin == tr("genCode")) {
        p.start(cmdpath.minicPath, QStringList()
            << fileName << "-g");
    }
    else if (bin == tr("run")) {
        this->ui->outputArea->setText(QString::fromLocal8Bit("本程序暂时不支持从gui上运行虚拟机，请使用命令行操作"));
        return;
    }
//   开始执行
    p.waitForStarted();
    p.waitForFinished();
//    如果命令行程序抛出异常，则屏幕显示错误信息
    QString err = QString::fromLocal8Bit(p.readAllStandardError());
    if (!err.isEmpty()) {
        ui->outputArea->setText(err);
        return;
    }
//    屏幕显示命令行程序的输出
    QString output=QString::fromUtf8(p.readAllStandardOutput());
    ui->outputArea->setText(output);
    if (ui->saveCheckBox->isChecked() && !ui->savePathEdit->text().isEmpty()) {
        QFile f(ui->savePathEdit->text());
        if (f.open(QIODevice::Text|QIODevice::ReadWrite)) {
            f.resize(0);
            QTextStream out(&f);
            out << ui->outputArea->toPlainText() << endl;
            f.close();
        }else {
            ui->statusbar->showMessage("输出结果保存失败");
        }
    }

    // 执行完毕后检查是否结果另存为文件，如果是打勾且文件名输入框不为空，则保存结果文件
    if (ui->saveCheckBox->isChecked() && !ui->savePathEdit->text().isEmpty()) {
        saveOutput();
    }
}

void Editor::open()
{
    QString fn = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开文件"), fileName, QString::fromLocal8Bit("minic源文件(*.mc *.tm);;所有文件(*.*)"));// 选择打开文件路径
    if (fn.isEmpty()) {
        warn("未选择文件");
        return;
    }
    QFile f(fn);
    if (!f.open(QFile::ReadOnly|QFile::Text)) {
        warn("不是文本文件或被其他程序打开");
        return;
    }
    fileName = fn;// 更新文件名
//    加载文本
    QTextStream in(&f);
    ui->codeArea->clear();
    ui->codeArea->setPlainText(in.readAll());
    f.close();
}

void Editor::saveOutput()
{
    QString path(ui->savePathEdit->text());
    QFile file(path);
    // 打开文件，必须是文本文件，并且可读可写，打开失败时弹出警告框
//    如果不设置可读，则其他程序将无法读入此文件
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        warn("此路径不是文本文件或者已被其他程序打开");
        return;
    }
    file.resize(0);// 清空文件内容
    QTextStream out(&file);// 输出流用于写入文件
    QApplication::setOverrideCursor(Qt::WaitCursor); // 保存过程中，光标设置被等待状态
    out << ui->outputArea->toPlainText();
    QApplication::restoreOverrideCursor();// 保存完毕，光标回复原状态
    file.close();
}

void Editor::save() {
    QFile file(fileName);
    // 打开文件，必须是文本文件，并且可读可写，打开失败时弹出警告框
//    如果不设置可读，则其他程序将无法读入此文件
    if (!file.open(QFile::ReadWrite|QFile::Text)) {
        warn("此路径不是文本文件或者已被其他程序打开");
        return;
    }
    file.resize(0);// 清空文件内容
    QTextStream out(&file);// 输出流用于写入文件
    QApplication::setOverrideCursor(Qt::WaitCursor); // 保存过程中，光标设置被等待状态
    out << ui->codeArea->toPlainText();
    QApplication::restoreOverrideCursor();// 保存完毕，光标回复原状态
    file.close();
}

void Editor::on_action_Preference_triggered() {
    qDebug() << "偏好设置按钮被点击" << endl;
    OptionDialog* od = new OptionDialog(&cmdpath, this);
    od->show();
}

void Editor::on_genTreeBtn_clicked() {
    qDebug() << "语法树生成按钮被点击" << endl;    
    save();
    call("parse");
}

void Editor::on_action_Save_triggered()
{
    save();
}

void Editor::saveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("另存为"), fileName, QString::fromLocal8Bit("minic源文件(*.mc *.txt);;所有文件(*.*)"));// 打开另存为对话框选择保存路径
    if (fn.isEmpty()) {
        warn("未选择文件");
        return;
    }
    fileName = fn;
    save();
    
}

void Editor::warn(const char* msg, const char* title)
{
    QMessageBox::warning(this, QString::fromLocal8Bit(title), QString::fromLocal8Bit(msg));
}

void Editor::on_actionSave_As_triggered()
{
    saveAs();
}

void Editor::on_actionClose_triggered()
{
    this->close();
}

void Editor::on_action_Open_triggered()
{
    open();
}

void Editor::on_action_New_triggered()
{
    Editor* newEditor = new Editor();
    newEditor->show();
}

void Editor::on_semanticAnalysisBtn_clicked()
{
    call(tr("analyze"));
}

void Editor::on_genMachineCodeBtn_clicked()
{
    call(tr("genCode"));
}

void Editor::on_runMachineCodeBtn_clicked()
{
    call(tr("run"));
}

void Editor::on_clearBtn_clicked()
{
    this->ui->outputArea->clear();
}
