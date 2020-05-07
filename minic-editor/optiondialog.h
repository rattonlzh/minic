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
        explicit OptionDialog(QWidget *parent = nullptr);
        OptionDialog(CmdPath* cpaths, QWidget *parent = nullptr);
        ~OptionDialog();
        
    private slots:
        void on_chooseScanBtn_clicked();
        
        void on_chooseGenTreeBtn_clicked();
        
        void on_buttonBox_accepted();
        
    private:
        CmdPath* paths;
        Ui::OptionDialog *ui;
};

#endif // OPTIONDIALOG_H
