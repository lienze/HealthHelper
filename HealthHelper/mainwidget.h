#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    QSystemTrayIcon *mSysTrayIcon;
    void createActions();
    void createMenu();
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;

private slots:
    void on_pushButton_cancle_clicked();
    void on_pushButton_confirm_clicked();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

    void on_showMainAction();
    void on_exitAppAction();
private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
