#ifndef ROBOT_H
#define ROBOT_H

#include "player.h"
/******************************************************************************
 *
 * @file       robot.h
 * @brief      机器人玩家类
 *
 * @author     我好想睡觉
 * @date       2024/08/08
 * @history
 *****************************************************************************/


class Robot : public Player
{
    Q_OBJECT
public:
    explicit Robot(QObject *parent = nullptr);

    void prepareCallLord() override;
    void preparePlayHand() override;

    // 考虑叫地主
    void thinkCallLord() override;
    void thinkPlayHand() override;
};

#endif // ROBOT_H
