/**
 * @file editor.cc
 * @author Liang Zehao
 * @brief minic编辑器的主界面
 * 
 * @version 0.1
 * @date 2020-05-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "editor.h"
#include "ui_editor.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <optiondialog.h>
#include <QSettings>


Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Editor) {
    ui->setupUi(this);
    init();
}


void Editor::init() {
fileName = QCoreApplication::applicationDirPath()+"/autosaved.mc";
    //Qt中使用QSettings类读写ini文件   
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省   
    QSettings config("minic.ini", QSettings::IniFormat);  
    cmdpath.scanPath = config.value("scan", 
                                    QCoreApplication::applicationDirPath()
                                    +"/scan").toString();
    cmdpath.genTreePath = config.value("genTree", 
                                       QCoreApplication::applicationDirPath()
                                       +"/genTree").toString();
}

Editor::~Editor() {
    QSettings config("minic.ini", QSettings::IniFormat);  
    config.setValue("scan", cmdpath.scanPath);
    config.setValue("genTree", cmdpath.genTreePath);
    config.sync();
    delete ui;
}


void Editor::on_scannerBtn_clicked() {
    save();
    call("scan");
    qDebug() << "词法扫描按钮被点击" << endl;

}
void Editor::call(QString bin) {
    QProcess p(0);
//    根据bin的值调用相应的命令
    if (bin == tr("scan")) {
        p.start(cmdpath.scanPath, QStringList() 
                << fileName);
    }else if (bin == tr("genTree")) {
        p.start(cmdpath.genTreePath, QStringList() 
                << fileName);
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
    QString output=QString::fromLocal8Bit(p.readAllStandardOutput());
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
}

void Editor::open()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("打开文件"), fileName, tr("minic源文件(*.mc *.txt);;所有文件(*.*)"));// 选择打开文件路径
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
    call("genTree");
}

void Editor::on_action_Save_triggered()
{
    save();
}

void Editor::saveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("另存为"), fileName, tr("minic源文件(*.mc *.txt);;所有文件(*.*)"));// 打开另存为对话框选择保存路径
    if (fn.isEmpty()) {
        warn("未选择文件");
        return;
    }
    fileName = fn;
    save();
    
}

void Editor::warn(QString msg, QString title)
{
    QMessageBox::warning(this, title, msg);
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
