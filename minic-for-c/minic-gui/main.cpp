#include "editor.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Editor w;
    w.show();
    return a.exec();
}
