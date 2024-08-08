#ifndef GAMECONTROL_H
#define GAMECONTROL_H

/******************************************************************************
 *
 * @file       gamecontrol.h
 * @brief      游戏控制类
 *
 * @author     我好想睡觉
 * @date       2024/08/08
 * @history
 *****************************************************************************/

#include <QObject>
#include "cards.h"
#include "robot.h"
#include "userplayer.h"
#include "Logger.h"



class BetRecord{
public:
    Player* player;
    int bet;
    int times;

    void reset(Player);
};

class GameControl:public QObject
{
    Q_OBJECT
public:
    GameControl(QObject *parent = nullptr);

    enum GameStatus{
        DispatchCard,       //发牌状态
        CallingLord,        //叫地主
        PalyingHand,        //出牌阶段
    };

    enum PlayerStatus{
        ThinkingForCallLord,    //考虑叫地主
        ThinkingForPlayHand,    //考虑玩家
        winning,                //获胜阶段
    };


    Card takeOneCard();         // 每次发一张牌
    Cards getSurplusCards();    // 得到剩余的牌
    void initAllCards();        //初始化所有的牌信息到容器中
    void initPlayer();          //初始化玩家
    Player* getLeftRobot();      //获取玩家实例
    Player* getRightRobot();
    Player* getUserPlayer();
    Player* getPendPlayer();
    Cards getPendCards();       //获取玩家刚打出的牌
    void setCurPlayer(Player* cur_player);
    Player* getCurPlayer();
    void clearPlayerScore();    //清空所有玩家得分
    void resetCardData();       //重置卡片
    void startLordCard();       //开始叫地主
    void becomeLord(Player* player);    //成为地主
private:
    Cards m_allCards;           //存储整幅扑克牌
    int m_currBet;              //当前局赌注的底分
    Robot* m_leftRobot;         //左侧机器人
    Robot* m_RightRobot;        //右侧机器人
    UserPlayer* m_userPlayer;   //玩家自己
    BetRecord* m_betRecord;     //记录叫地主信息
    Player* m_pendPlayer;       //出牌的玩家
    Player* m_curPlayer;        //当前玩家
    Cards m_pendCards;          //出牌玩家打出的牌
};

#endif // GAMECONTROL_H
