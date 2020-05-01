#ifndef DIALOGPREFERENCE_H
#define DIALOGPREFERENCE_H

#include <QDialog>

namespace Ui {
class DialogPreference;
}

class DialogPreference : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPreference(QWidget *parent = nullptr);
    ~DialogPreference();

private:
    Ui::DialogPreference *ui;
};

#endif // DIALOGPREFERENCE_H
