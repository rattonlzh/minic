/*
 * @Copyright: Copyright (c) 2020 SCNU authors. All right reserved.
 * @FilePath: /minic/minic-editor/editor.h
 * @Description: 编辑器主界面的头文件声明
 * @Version: 1.0
 * @Author: Liang Zehao, Zhang Yongbiao
 * @Date: 2020-05-08 11:47:38
 * @LastEditTime: 2020-06-19 00:39:56
 * @LastEditors: Liang Zehao
 */ 


#ifndef EDITOR_H
#define EDITOR_H

#include "common.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; }
QT_END_NAMESPACE

/**
 * @brief Editor类，可以新建，打开，保存文件，调用命令行程序
 */
class Editor : public QMainWindow
{
    Q_OBJECT
public:
    Editor(QWidget *parent = nullptr);
    ~Editor();
    /**
     * @brief 自动保存到当前目录下，文件名由Editor::filename决定
     */
    void save();
    /**
     * @brief call调用bin命令， 自动传入参数Editor::filename
     * @param bin 命令行程序的名称，必须与gui程序在同级目录下
     */
    void  call(QString bin);
    /**
     * @brief cmdpath持有各个可执行程序的路径
     */
    CmdPath cmdpath;
    /**
     * @brief open打开文件，加载文本文件到代码编辑区
     */
    void open();
    /**
     * @brief 结果保存到path中
     */
    void saveOutput();
    
public slots:
    void on_scannerBtn_clicked();

    void on_action_Preference_triggered();

    void on_genTreeBtn_clicked();

    void on_action_Save_triggered();
    void saveAs();
    void warn(const char * msg, const char *title= "minic编辑器");
    void on_actionSave_As_triggered();
    
    void on_actionClose_triggered();
    
    void on_action_Open_triggered();
    
    void on_action_New_triggered();

    void on_semanticAnalysisBtn_clicked();
    void on_genMachineCodeBtn_clicked();
    void on_runMachineCodeBtn_clicked();
    void on_clearBtn_clicked();
    
private:
    /**
     * @brief 在此定义界面无关的初始化逻辑
     */
    void init();
    /**
     * @brief fileName 代码编辑区文本要保存的路径
     */
    QString fileName;
    /**
     * @brief 封装了自定义界面的类的一个实例。用户在editor.ui文件设计界面，编译后自动生成
     * Ui::Editor类
     */
    Ui::Editor *ui;
};
#endif // EDITOR_H
