#include "scorepanel.h"
#include "ui_scorepanel.h"

ScorePanel::ScorePanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScorePanel)
{
    ui->setupUi(this);
}

ScorePanel::~ScorePanel()
{
    delete ui;
}

void ScorePanel::setScore(int left, int right, int user)
{
    ui->left_score->setText(QString::number(left));
    ui->right_socre->setText(QString::number(right));
    ui->user_socre->setText(QString::number(user));
}


