#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.show();
    //全屏显示
    w.showFullScreen();
    return a.exec();
}
