/**
    项目:C语言小助手2.0
    作者:郝凡
    日期:2017年9月1日
    版权:版权所有 ©2017  郝凡
    说明:这一程序是自由软件，你可以遵照自由软件基金会出版的GNU通用公共许可证条款来修改和重新发布这一程序。禁止用于商业化。
*/

#include "mainwindow.h"
#include <QApplication>

#include"MyGlobalShortCut/MyGlobalShortCut.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //注册快捷键,为了使用方便且无冲突，无任何字面意义
    MyGlobalShortCut *low = new MyGlobalShortCut("Alt+Q",&w);
    MyGlobalShortCut *up = new MyGlobalShortCut("Alt+E",&w);
    //绑定响应热键的slot
    QObject::connect(low,SIGNAL(activated()),&w,SLOT(lower()));
    QObject::connect(up,SIGNAL(activated()),&w,SLOT(uper()));


    a.connect( &a,SIGNAL(lastWindowClosed()),&a,SLOT(quit()));
    w.show();

    return a.exec();
}
