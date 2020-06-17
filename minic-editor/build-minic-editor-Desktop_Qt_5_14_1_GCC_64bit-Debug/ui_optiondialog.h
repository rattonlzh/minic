/********************************************************************************
** Form generated from reading UI file 'optiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *genTreePathEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *scanPathEdit;
    QPushButton *chooseScanBtn;
    QPushButton *chooseGenTreeBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QString::fromUtf8("OptionDialog"));
        OptionDialog->resize(519, 261);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OptionDialog->sizePolicy().hasHeightForWidth());
        OptionDialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(OptionDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        genTreePathEdit = new QLineEdit(OptionDialog);
        genTreePathEdit->setObjectName(QString::fromUtf8("genTreePathEdit"));

        gridLayout->addWidget(genTreePathEdit, 1, 1, 1, 1);

        label = new QLabel(OptionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(OptionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        scanPathEdit = new QLineEdit(OptionDialog);
        scanPathEdit->setObjectName(QString::fromUtf8("scanPathEdit"));

        gridLayout->addWidget(scanPathEdit, 0, 1, 1, 1);

        chooseScanBtn = new QPushButton(OptionDialog);
        chooseScanBtn->setObjectName(QString::fromUtf8("chooseScanBtn"));

        gridLayout->addWidget(chooseScanBtn, 0, 2, 1, 1);

        chooseGenTreeBtn = new QPushButton(OptionDialog);
        chooseGenTreeBtn->setObjectName(QString::fromUtf8("chooseGenTreeBtn"));

        gridLayout->addWidget(chooseGenTreeBtn, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QCoreApplication::translate("OptionDialog", "Dialog", nullptr));
        genTreePathEdit->setText(QString());
        label->setText(QCoreApplication::translate("OptionDialog", "\346\211\253\346\217\217\345\231\250\347\250\213\345\272\217\350\267\257\345\276\204", nullptr));
        label_2->setText(QCoreApplication::translate("OptionDialog", "\350\257\255\346\263\225\346\240\221\347\224\237\346\210\220\345\231\250\347\250\213\345\272\217\350\267\257\345\276\204", nullptr));
        scanPathEdit->setText(QString());
        chooseScanBtn->setText(QCoreApplication::translate("OptionDialog", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        chooseGenTreeBtn->setText(QCoreApplication::translate("OptionDialog", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
