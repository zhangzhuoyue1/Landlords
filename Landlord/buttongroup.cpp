#include "buttongroup.h"
#include "ui_buttongroup.h"

ButtonGroup::ButtonGroup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ButtonGroup)
{
    ui->setupUi(this);
}

ButtonGroup::~ButtonGroup()
{
    delete ui;
}

void ButtonGroup::initButtons()
{
    //初始化按钮组按钮
    //开始游戏
    ui->start_btn->setImage(":/images/start-1.png",":/images/start-2.png",":/images/start-3.png");
    //出牌
    ui->paly_hand_btn1->setImage(":/images/chupai_btn-1.png",":/images/chupai_btn-2.png",":/images/chupai_btn-3.png");
    ui->play_hand_btn2->setImage(":/images/chupai_btn-1.png",":/images/chupai_btn-2.png",":/images/chupai_btn-3.png");
    //不出
    ui->no_play_hand_btn->setImage(":/images/pass_btn-1.png",":/images/pass_btn-2.png",":/images/pass_btn-3.png");
    //不抢
    ui->score_0_btn->setImage(":/images/buqiang-1.png",":/images/buqiang-2.png",":/images/buqiang-3.png");
    //分数
    ui->score_1_btn->setImage(":/images/1fen-1.png",":/images/1fen-2.png",":/images/1fen-3.png");
    ui->score_2_btn->setImage(":/images/2fen-1.png",":/images/2fen-2.png",":/images/2fen-3.png");
    ui->score_3_btn->setImage(":/images/3fen-1.png",":/images/3fen-2.png",":/images/3fen-3.png");

    //设置按钮组的大小
    QVector<MyButton*> btns;
    btns<<ui->start_btn<<ui->no_play_hand_btn<<ui->play_hand_btn2<<ui->paly_hand_btn1
         <<ui->score_0_btn<<ui->score_1_btn<<ui->score_2_btn<<ui->score_3_btn;
    for(int i=0;i<btns.size();++i){
        btns[i]->setFixedSize(90,45);
    }
}

void ButtonGroup::selectPanel(Panel type)
{
    ui->stackedWidget->setCurrentIndex(type);
}


void ButtonGroup::on_start_btn_clicked()
{
    emit sig_start_game();
}


void ButtonGroup::on_play_hand_btn2_clicked()
{
    emit sig_paly_hand();
}


void ButtonGroup::on_score_2_btn_clicked()
{
    emit sig_betPoint(2);
}


void ButtonGroup::on_paly_hand_btn1_clicked()
{
    emit sig_paly_hand();
}


void ButtonGroup::on_no_play_hand_btn_clicked()
{
    emit sig_pass();
}


void ButtonGroup::on_score_0_btn_clicked()
{
    emit sig_betPoint(0);
}


void ButtonGroup::on_score_1_btn_clicked()
{
    emit sig_betPoint(1);
}


void ButtonGroup::on_score_3_btn_clicked()
{
    emit sig_betPoint(3);
}

