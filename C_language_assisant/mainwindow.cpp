/**
    项目:C语言小助手2.0
    作者:郝凡
    日期:2017年9月1日
    版权:版权所有 ©2017  郝凡
    说明:这一程序是自由软件，你可以遵照自由软件基金会出版的GNU通用公共许可证条款来修改和重新发布这一程序。禁止用于商业化。
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QString>

#define SHOWLENGTH  2000
//#include<string.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //隐藏任务栏图标&窗体置顶
    setWindowFlags( Qt::Tool | Qt::X11BypassWindowManagerHint| Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_QuitOnClose);
    ui->setupUi(this);
    ui->textEdit->setText(hello);
    //状态栏初始化

    msgLabel = new QLabel;
   // msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignRight);

    msgLabel->setMaximumWidth(this->width()/2);
    msgLabel->setText(" 版权所有 ©2017  郝凡 ");
    statusBar()->addPermanentWidget(msgLabel,100);
    //加载题库
    question="";
    memset(ans,-1,sizeof(ans));
    QFile file(":/text/question_bank.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::about(0,"错误","题库加载失败");
        return ;
    }
    question= file.readAll();


}

MainWindow::~MainWindow()
{
    delete ui;


}
//增强透明度
void MainWindow::lower()
{
    int n=0;
    double_t Opacity=1.0;
    n=ui->horizontalSlider->value();
    n-=10;
    ui->horizontalSlider->setValue(n);
    if(n<0)
    {
        n=0;
    }

    Opacity=double_t(n)/100;
    setWindowOpacity(Opacity);
    //QMessageBox::about(0,"title","hello lower");
}
//降低透明度
void MainWindow::uper()
{
    int n=0;
    double_t Opacity=1.0;
    n=ui->horizontalSlider->value();
    n+=10;
    ui->horizontalSlider->setValue(n);
    if(n>100)
    {
        n=100;
    }
    Opacity=double_t(n)/100;
    setWindowOpacity(Opacity);
    //QMessageBox::about(0,"title","hello uper");
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    setWindowOpacity(double_t(value)/100);
}

/*查找按钮点击响应事件*/
void MainWindow::on_pushButton_clicked()
{
    QString key;
    key=ui->lineEdit->text();
    if(key.isEmpty())
    {
        QMessageBox::about(this,"提示","搜索内容不能为空");
        return ;
    }
    pos=0;
    sum=0;
    int i=0,n=0;
    memset(ans,-1,sizeof(ans));
    for(i=0;i<sizeof(ans)/sizeof(ans[0]);i++)
    {
        n=question.indexOf(key,pos);
        if(n==-1)
        {
            break;
        }
        else
        {
            ans[i]=n;
            sum=i;
        }
        pos=n+100;
    }
   // QMessageBox::about(this,"t",QString::number(sum));
    pos=0;
    if(sum==0)
    {
        QMessageBox::about(this,"未找到","修改关键字后重试!");
        return;
    }
    if(pos<=sum&&pos>=0)
    {
        QString showAns=question.mid(ans[pos],SHOWLENGTH);
        ui->textEdit->setText(showAns);
    }
    msgLabel->setText(QString::number(pos)+"/"+QString::number(sum));

}
/*按钮上一个被点击响应事件*/
void MainWindow::on_pushButton_2_clicked()
{
    pos-=1;
    if(pos<0)
    {
        QMessageBox::about(this,"未找到","已经显示第一个！");
        pos++;
        return ;
    }
    if(pos<=sum&&pos>=0)
    {
        QString showAns=question.mid(ans[pos],SHOWLENGTH);
        ui->textEdit->setText(showAns);
    }
    msgLabel->setText(QString::number(pos)+"/"+QString::number(sum));

}
/*按钮下一个被点击响应事件*/
void MainWindow::on_pushButton_3_clicked()
{
    pos+=1;
    if(pos>sum)
    {
        QMessageBox::about(this,"未找到","已经显示最后一个！");
        pos--;
        return ;
    }
    if(pos<=sum&&pos>=0)
    {
        QString showAns=question.mid(ans[pos],SHOWLENGTH);
        ui->textEdit->setText(showAns);
    }
    msgLabel->setText(QString::number(pos)+"/"+QString::number(sum));
}
/*按钮清屏被点击响应事件*/
void MainWindow::on_pushButton_4_clicked()
{
    //清空,初始化
    ui->lineEdit->clear();
    ui->textEdit->clear();
    ui->textEdit->setText(hello);
    msgLabel->clear();
    memset(ans,-1,sizeof(ans));
    sum=0;
    pos=0;
}

