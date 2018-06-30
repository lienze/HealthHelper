#include "mainwidget.h"
#include "ui_mainwidget.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    mSysTrayIcon = NULL;

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_pushButton_cancle_clicked()
{
    this->close();
}

void MainWidget::on_pushButton_confirm_clicked()
{
    //TODO:写入配置文件

    //隐藏程序主窗口
    this->hide();
    //初始化QSystemTrayIcon对象
    if(mSysTrayIcon==NULL)
    {
        mSysTrayIcon = new QSystemTrayIcon(this);
        //新建托盘要显示的icon
        QIcon icon = QIcon(":/images/desktop_icon.png");
        //将icon设到QSystemTrayIcon对象中
        mSysTrayIcon->setIcon(icon);
        //当鼠标移动到托盘上的图标时，会显示此处设置的内容
        mSysTrayIcon->setToolTip("HealthHelper");
        //给QSystemTrayIcon添加槽函数
        connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

        //建立托盘操作的菜单
        createActions();
        createMenu();
    }
    //在系统托盘显示此对象
    mSysTrayIcon->show();
}

void MainWidget::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
        //显示消息球，1s后自动消失
        //第一个参数是标题
        //第二个参数是消息内容
        //第三个参数图标
        //第四个参数是超时毫秒数
        mSysTrayIcon->showMessage(tr("Message Title"),
                                  tr("欢迎使用此程序"),
                                  QSystemTrayIcon::Information,
                                  1000);
        break;
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        //双击后显示主程序窗口
        this->show();
        break;
    default:
        break;
    }
}

void MainWidget::createActions()
{
    mShowMainAction = new QAction(tr("显示主界面"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(tr("退出"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));

}

void MainWidget::createMenu()
{
    mMenu = new QMenu(this);
    mMenu->addAction(mShowMainAction);

    mMenu->addSeparator();

    mMenu->addAction(mExitAppAction);

    mSysTrayIcon->setContextMenu(mMenu);
}

void MainWidget::on_showMainAction()
{
    this->show();
}

void MainWidget::on_exitAppAction()
{
    exit(0);
}
