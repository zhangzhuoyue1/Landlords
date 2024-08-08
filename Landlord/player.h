#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include "cards.h"

/******************************************************************************
 *
 * @file       player.h
 * @brief      玩家类基类
 *
 * @author     我好想睡觉
 * @date       2024/08/08
 * @history
 *****************************************************************************/

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name, QObject *parent = nullptr);
    //玩家角色
    enum Role{
        Lord,   //地主
        Farmer, //农民
    };

    //玩家类型
    enum Type{
        User,   //用户
        Robot,  //机器人
    };

    //性别
    enum Sex{
        Man,
        Woman,
    };

    //头像位置
    enum Direction{
        Left,
        Right,
    };

    void setName(const QString name);
    void setType(const Type type);
    void setRole(const Role role);
    void setScore(int score);
    void setPrePlayer(Player* player);
    void setNextPlayer(Player* player);
    void setDirection(Direction direct);

    QString getName();
    Type getType();
    Role getRole();
    int getScore();
    Player* getPrePlayer();
    Player* getNextPlayer();
    Direction getDirection();
    Cards getCards();                       //得到玩家手里的牌
    Sex getSex();
    Player* getPendPlayer();

    void clearCards();                      //清空手牌
    Cards getPendCards();                    //得到玩家刚打出的牌
    bool siWin();                           //判断玩家是否胜利
    void playHand(Cards& cards);              //出牌
    void getPandingInfo(Player* player,const Cards& cards); //记录某个玩家刚打出的牌
    void storeDispatchCard(const Card& card);// 存储扑克牌(发牌的时候得到的)
    void storeDispatchCard(const Cards& cards);
    void grabLordBet(int point);                // 叫地主/抢地主

    virtual void prepareCallLord()=0;         //准备叫地主
    virtual void preparePlayHand()=0;         //准备出牌
    virtual void thinkCallLord()=0;           //考虑叫地主
    virtual void thinkPlayHand()=0;             //考虑出牌

protected:
    QString m_name;         //当前玩家的姓名
    Player* m_prevPlayer;   //上一个玩家
    Player* m_nextPlayer;   //下一个玩家
    Player* m_pendPlayer;   //刚出完牌的用户
    Cards m_pendCards;      //用户刚打出的牌
    int m_score;            //玩家的得分
    Cards m_cards;          //玩家手里的牌
    Type m_type;            //玩家的类型
    Sex m_sex;              //玩家的性别
    Direction   m_direct;    //人物头像显示的位置
    Role m_role;            //玩家角色
    bool m_isWin;           //当前玩家是否获得胜利

signals:
    // 通知已经叫地主下注
    void sig_grabLordBet(Player* player, int bet);
    // 通知已经出牌
    void sig_playHand(Player* player, Cards& card);
    // 通知已经发牌了
    void sig_pickCards(Player* player, const Cards& cards);
};

#endif // PLAYER_H
