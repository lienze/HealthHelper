#include "widget.h"
#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //首先显示主界面，进行相关设置
    MainWidget mainWidget;
    mainWidget.show();

    //Widget w;
    //w.show();
    //全屏显示
    //w.showFullScreen();
    return a.exec();
}
