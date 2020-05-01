#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; }
QT_END_NAMESPACE

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    ~Editor();

private slots:
    void on_scannerBtn_clicked();

    void on_action_Preference_triggered();

    void on_genTreeBtn_clicked();

private:
    Ui::Editor *ui;
};
#endif // EDITOR_H
