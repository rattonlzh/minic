#include "dialogpreference.h"
#include "editor.h"
#include "ui_editor.h"

#include <QProcess>
#include <qmessagebox.h>

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}


void Editor::on_scannerBtn_clicked()
{
    QProcess p(0);
    p.setWorkingDirectory("/home/hadoop/Documents/repos/mini-c-compiler/app");//切换工作目录
    p.start("bin/scanner", QStringList() << "test/in/test1.mc");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    p.start("ls");
    p.waitForStarted();
    p.waitForFinished();
    strTemp+=QString::fromLocal8Bit(p.readAllStandardOutput());
    QMessageBox testMassage;
    testMassage.setText(strTemp);
    testMassage.exec();

}

void Editor::on_action_Preference_triggered()
{
    DialogPreference preference;
    preference.exec();
}

void Editor::on_genTreeBtn_clicked()
{
    QProcess p(0);
    p.setWorkingDirectory("/home/hadoop/Documents/repos/mini-c-compiler/app");//切换工作目录
    p.start("bin/genTree", QStringList() << "test/in/testParser4.mc");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    ui->outputArea->setText(strTemp);
}
