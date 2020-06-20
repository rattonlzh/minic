/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic/minic-editor/optiondialog.h
 * @Description: 设置界面类的声明
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-05-08 11:47:38
 * @LastEditTime: 2020-06-19 08:41:57
 * @LastEditors: Liang Zehao
 */

#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include "common.h"

#include <QDialog>

namespace Ui {
    class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(QWidget* parent = nullptr);
    OptionDialog(CmdPath* cpaths, QWidget* parent = nullptr);
    ~OptionDialog();

private slots:
    void on_chooseScanBtn_clicked();

    void on_chooseGenTreeBtn_clicked();

    void on_buttonBox_accepted();

private:
    CmdPath* paths;
    Ui::OptionDialog* ui;
};

#endif // OPTIONDIALOG_H
