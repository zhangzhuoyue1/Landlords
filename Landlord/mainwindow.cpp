#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QRandomGenerator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化按钮组
    ui->button_group->initButtons();
    ui->button_group->selectPanel(ButtonGroup::Start);

    //背景图
    int num=QRandomGenerator::global()->bounded(10);
    QString path=QString(":/images/background-%1.png").arg(num+1);
    m_bkimage.load(path);
    //update();

    //窗口标题大小
    this->setWindowTitle("欢乐斗地主");
    this->setMinimumSize(1000,650);
    this->setWindowIcon(QIcon(":/images/logo.ico"));

    //得到三个玩家的实例
    initPlayer();
    //玩家得分
    updateScore();
    //切割图片
    initCard();
    //初始化按钮

    //初始化玩家在窗口中的上下文环境


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPlayer()
{
    //实例化游戏控制类
    m_gameControl=new GameControl(this);
    m_gameControl->initPlayer();
    Robot* leftRobot=m_gameControl->getLeftRobot();
    Robot* rightRobot=m_gameControl->getRightRobot();
    UserPlayer* userPlayer=m_gameControl->getUserPlayer();
    m_playList<<leftRobot<<rightRobot<<userPlayer;
}

void MainWindow::updateScore()
{
    ui->score_panel->setScore(m_playList[0]->getScore(),m_playList[1]->getScore(),m_playList[2]->getScore());
}

void MainWindow::initCard()
{
    //加载大图
    QPixmap allCard(":/images/card.png");

    //裁剪得小图
    int w=allCard.width()/13;
    int h=allCard.height()/5;
    m_size.setHeight(h);
    m_size.setWidth(w);

    //背景图
    m_bkCard=allCard.copy(2*w,4*h,
                            w,h);

    //正常花色
    for(int i=0,suit=Card::Suit_Begin+1;suit<Card::King;++suit,++i ){
        for(int j=0,pt=Card::Card_Begin+1;pt<Card::Card_SJ;++pt,++j){
            Card card(static_cast<Card::CardPoint>(pt),static_cast<Card::CardSuit>(suit));
            cropImage(allCard,j*w,i*h,card);
        }
    }
    //大小王
    Card c;
    c.setPoint(Card::Card_SJ);
    c.setSuit(Card::King);
    cropImage(allCard,0,4*h,c);

    c.setPoint(Card::Card_BJ);
    c.setSuit(Card::King);
    cropImage(allCard,w,4*h,c);
}

void MainWindow::cropImage(QPixmap &pix, int x, int y, Card& c)
{
    QPixmap sub=pix.copy(x,y,m_size.width(),m_size.width());
    CardPanel* panel=new CardPanel(this);
    panel->setImage(sub,m_bkCard);
    panel->setCard(c);
    panel->hide();
    m_cardMap[c]=panel;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.drawPixmap(rect(),m_bkimage);
}
