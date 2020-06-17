/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *action_Preference;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionSelect_All;
    QAction *actionOpen_Folder;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QLabel *label_3;
    QTextEdit *codeArea;
    QVBoxLayout *verticalLayout;
    QPushButton *scannerBtn;
    QPushButton *genTreeBtn;
    QPushButton *semanticAnalysisBtn;
    QPushButton *genMachineCodeBtn;
    QPushButton *runMachineCodeBtn;
    QPushButton *clearBtn;
    QSplitter *splitter_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *saveCheckBox;
    QLineEdit *savePathEdit;
    QTextBrowser *outputArea;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->resize(965, 451);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Editor->sizePolicy().hasHeightForWidth());
        Editor->setSizePolicy(sizePolicy);
        action_New = new QAction(Editor);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        action_Open = new QAction(Editor);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_Save = new QAction(Editor);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        actionSave_As = new QAction(Editor);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionClose = new QAction(Editor);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        action_Preference = new QAction(Editor);
        action_Preference->setObjectName(QString::fromUtf8("action_Preference"));
        actionUndo = new QAction(Editor);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(Editor);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionCopy = new QAction(Editor);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionCut = new QAction(Editor);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionPaste = new QAction(Editor);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionSelect_All = new QAction(Editor);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        actionOpen_Folder = new QAction(Editor);
        actionOpen_Folder->setObjectName(QString::fromUtf8("actionOpen_Folder"));
        centralwidget = new QWidget(Editor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        splitter->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        splitter->addWidget(label_3);
        codeArea = new QTextEdit(splitter);
        codeArea->setObjectName(QString::fromUtf8("codeArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(codeArea->sizePolicy().hasHeightForWidth());
        codeArea->setSizePolicy(sizePolicy4);
        codeArea->setFocusPolicy(Qt::StrongFocus);
        codeArea->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        codeArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        splitter->addWidget(codeArea);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        scannerBtn = new QPushButton(centralwidget);
        scannerBtn->setObjectName(QString::fromUtf8("scannerBtn"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scannerBtn->sizePolicy().hasHeightForWidth());
        scannerBtn->setSizePolicy(sizePolicy5);
        scannerBtn->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(scannerBtn);

        genTreeBtn = new QPushButton(centralwidget);
        genTreeBtn->setObjectName(QString::fromUtf8("genTreeBtn"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(genTreeBtn->sizePolicy().hasHeightForWidth());
        genTreeBtn->setSizePolicy(sizePolicy6);
        genTreeBtn->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(genTreeBtn);

        semanticAnalysisBtn = new QPushButton(centralwidget);
        semanticAnalysisBtn->setObjectName(QString::fromUtf8("semanticAnalysisBtn"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(semanticAnalysisBtn->sizePolicy().hasHeightForWidth());
        semanticAnalysisBtn->setSizePolicy(sizePolicy7);
        semanticAnalysisBtn->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(semanticAnalysisBtn);

        genMachineCodeBtn = new QPushButton(centralwidget);
        genMachineCodeBtn->setObjectName(QString::fromUtf8("genMachineCodeBtn"));
        sizePolicy7.setHeightForWidth(genMachineCodeBtn->sizePolicy().hasHeightForWidth());
        genMachineCodeBtn->setSizePolicy(sizePolicy7);
        genMachineCodeBtn->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(genMachineCodeBtn);

        runMachineCodeBtn = new QPushButton(centralwidget);
        runMachineCodeBtn->setObjectName(QString::fromUtf8("runMachineCodeBtn"));
        sizePolicy7.setHeightForWidth(runMachineCodeBtn->sizePolicy().hasHeightForWidth());
        runMachineCodeBtn->setSizePolicy(sizePolicy7);
        runMachineCodeBtn->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(runMachineCodeBtn);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        sizePolicy7.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy7);
        clearBtn->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout->addWidget(clearBtn);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(2);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy8);
        splitter_2->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        horizontalLayout->addWidget(label);

        saveCheckBox = new QCheckBox(widget);
        saveCheckBox->setObjectName(QString::fromUtf8("saveCheckBox"));
        saveCheckBox->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        horizontalLayout->addWidget(saveCheckBox);

        savePathEdit = new QLineEdit(widget);
        savePathEdit->setObjectName(QString::fromUtf8("savePathEdit"));

        horizontalLayout->addWidget(savePathEdit);

        splitter_2->addWidget(widget);
        outputArea = new QTextBrowser(splitter_2);
        outputArea->setObjectName(QString::fromUtf8("outputArea"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(2);
        sizePolicy9.setVerticalStretch(1);
        sizePolicy9.setHeightForWidth(outputArea->sizePolicy().hasHeightForWidth());
        outputArea->setSizePolicy(sizePolicy9);
        splitter_2->addWidget(outputArea);

        gridLayout->addWidget(splitter_2, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy10);
        label_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        verticalLayout_2->addWidget(label_2);

        listWidget = new QListWidget(centralwidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy11(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(1);
        sizePolicy11.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy11);
        listWidget->setBaseSize(QSize(0, 0));

        verticalLayout_2->addWidget(listWidget);


        gridLayout->addLayout(verticalLayout_2, 0, 3, 1, 1);

        Editor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Editor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 965, 26));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        Editor->setMenuBar(menubar);
        statusbar = new QStatusBar(Editor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Editor->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menu_File->addAction(action_New);
        menu_File->addSeparator();
        menu_File->addAction(action_Open);
        menu_File->addAction(actionOpen_Folder);
        menu_File->addSeparator();
        menu_File->addAction(action_Save);
        menu_File->addAction(actionSave_As);
        menu_File->addSeparator();
        menu_File->addAction(action_Preference);
        menu_File->addSeparator();
        menu_File->addAction(actionClose);
        menu_Edit->addAction(actionUndo);
        menu_Edit->addAction(actionRedo);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionCut);
        menu_Edit->addAction(actionCopy);
        menu_Edit->addAction(actionPaste);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionSelect_All);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Editor)
    {
        Editor->setWindowTitle(QCoreApplication::translate("Editor", "Editor", nullptr));
        action_New->setText(QCoreApplication::translate("Editor", "&New", nullptr));
#if QT_CONFIG(shortcut)
        action_New->setShortcut(QCoreApplication::translate("Editor", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Open->setText(QCoreApplication::translate("Editor", "&Open", nullptr));
#if QT_CONFIG(shortcut)
        action_Open->setShortcut(QCoreApplication::translate("Editor", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save->setText(QCoreApplication::translate("Editor", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        action_Save->setShortcut(QCoreApplication::translate("Editor", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("Editor", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("Editor", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("Editor", "Close", nullptr));
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("Editor", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Preference->setText(QCoreApplication::translate("Editor", "&Preference", nullptr));
#if QT_CONFIG(shortcut)
        action_Preference->setShortcut(QCoreApplication::translate("Editor", "Ctrl+,", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("Editor", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("Editor", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("Editor", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("Editor", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("Editor", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("Editor", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("Editor", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("Editor", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("Editor", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("Editor", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_All->setText(QCoreApplication::translate("Editor", "Select All", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_All->setShortcut(QCoreApplication::translate("Editor", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Folder->setText(QCoreApplication::translate("Editor", "Open Folder", nullptr));
        label_3->setText(QCoreApplication::translate("Editor", "\350\276\223\345\205\245", nullptr));
        codeArea->setHtml(QCoreApplication::translate("Editor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p></body></html>", nullptr));
        scannerBtn->setText(QCoreApplication::translate("Editor", "\350\257\215\346\263\225\346\211\253\346\217\217", nullptr));
        genTreeBtn->setText(QCoreApplication::translate("Editor", "\350\257\255\346\263\225\346\240\221\347\224\237\346\210\220", nullptr));
        semanticAnalysisBtn->setText(QCoreApplication::translate("Editor", "\347\261\273\345\236\213\346\243\200\346\237\245", nullptr));
        genMachineCodeBtn->setText(QCoreApplication::translate("Editor", "\344\270\255\351\227\264\344\273\243\347\240\201", nullptr));
        runMachineCodeBtn->setText(QCoreApplication::translate("Editor", "\350\277\220\350\241\214\344\270\255\351\227\264\344\273\243\347\240\201", nullptr));
        clearBtn->setText(QCoreApplication::translate("Editor", "\347\274\226\350\257\221\350\277\220\350\241\214", nullptr));
        label->setText(QCoreApplication::translate("Editor", "\350\276\223\345\207\272", nullptr));
        saveCheckBox->setText(QCoreApplication::translate("Editor", "\344\277\235\345\255\230\344\270\272", nullptr));
        label_2->setText(QCoreApplication::translate("Editor", "\346\226\207\344\273\266\345\244\271", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Editor", "test1.mc", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Editor", "test2.mc", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Editor", "testParser1.mc", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        menu_File->setTitle(QCoreApplication::translate("Editor", "&File", nullptr));
        menu_Edit->setTitle(QCoreApplication::translate("Editor", "&Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
