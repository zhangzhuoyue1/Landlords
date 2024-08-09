#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "gamecontrol.h"
#include "player.h"
#include "CardPanel.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initPlayer();          //初始化玩家
    void updateScore();         //更新分数
    void initCard();            //初始化扑克牌数据
    void cropImage();           //裁剪图片
private:
    Ui::MainWindow *ui;
    QPixmap m_bkimage;
    GameControl* m_gameControl;
    QVector<Player*> m_playList;
    std::map<Card,CardPanel>   m_cardMap;
    QSize m_size;
    QPixmap m_bkCard;                  //背景图
    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};
#endif // MAINWINDOW_H
