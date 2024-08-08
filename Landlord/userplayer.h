#ifndef USERPLAYER_H
#define USERPLAYER_H

/******************************************************************************
 *
 * @file       userplayer.h
 * @brief      用户玩家类
 *
 * @author     我好想睡觉
 * @date       2024/08/08
 * @history
 *****************************************************************************/


#include <QObject>
#include "player.h"

class UserPlayer : public Player
{
    Q_OBJECT
public:
    explicit UserPlayer(QObject *parent = nullptr);
    explicit UserPlayer(QString name,QObject *parent = nullptr);
    void prepareCallLord() override;
    void preparePlayHand() override;
    virtual void thinkCallLord()override;           //考虑叫地主
    virtual void thinkPlayHand()override;           //考虑出牌

signals:
    void sig_startCountDown();
};


#endif // USERPLAYER_H
