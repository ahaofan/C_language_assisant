#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //定义题库
    QString question;
    //定义答案数组最大数量五百个
    int ans[1000];
    //文本指针位置，找到答案个数
    int pos=0,sum=0;
    QLabel *msgLabel;
    QString hello="\
C语言小助手2.0\n \
更新说明\n\
1.整个项目使用Qt重做，纯C++编写。\n\
2.源代码完全开放，可在github下载源代码，禁止任何商业化使用。\n\
3.以后不再更新，你可根据源代码自行修改。\n\
\n\
软件特性\n\
1.程序启动任务栏无图标，无托盘图标。\n\
2.程序窗口以悬浮窗的形式显示，窗口大小可拖动调节，窗口始终置顶。\n\
3.窗口透明度可通过滑块条调节，快捷键修改为Alt+Q/E。\n\
\n\
源代码下载github地址: https://github.com/ahaofan/C_language_assisant\
                  ";

private:
    Ui::MainWindow *ui;
public slots:
    void lower();
    void uper();


private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();


};

#endif // MAINWINDOW_H
