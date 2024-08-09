#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QWidget>

/******************************************************************************
 *
 * @file       buttongroup.h
 * @brief      按钮组
 *
 * @author     我好想睡觉
 * @date       2024/08/09
 * @history
 *****************************************************************************/


namespace Ui {
class ButtonGroup;
}

class ButtonGroup : public QWidget
{
    Q_OBJECT

public:
    enum Panel{Start,Play,PassorPlay,CallLord,Empty};
    explicit ButtonGroup(QWidget *parent = nullptr);
    ~ButtonGroup();
    void initButtons();                 //初始化按钮组
    void selectPanel(Panel type);        //选择显示的按钮组

private:
    Ui::ButtonGroup *ui;
signals:
    void sig_start_game();
    void sig_pass();
    void sig_paly_hand();
    void sig_betPoint(int);
private slots:
    void on_start_btn_clicked();
    void on_play_hand_btn2_clicked();
    void on_score_2_btn_clicked();
    void on_paly_hand_btn1_clicked();
    void on_no_play_hand_btn_clicked();
    void on_score_0_btn_clicked();
    void on_score_1_btn_clicked();
    void on_score_3_btn_clicked();
};

#endif // BUTTONGROUP_H
