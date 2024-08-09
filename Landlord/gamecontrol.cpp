#include "gamecontrol.h"

#include <QRandomGenerator>

GameControl::GameControl(QObject *parent)
    :QObject{parent}
{

}

Card GameControl::takeOneCard()
{
    return m_allCards.takeRandomCard();
}

Cards GameControl::getSurplusCards()
{
    return m_allCards;
}

void GameControl::initAllCards()
{
    //清空存储的数据
    if(!m_allCards.isEmpty()){
        m_allCards.clear();
    }
    for(int p=Card::Card_Begin+1;p<Card::Card_SJ;++p)
    {
        for(int s=Card::Suit_Begin;s<Card::King;++s){
            Card c;
            c.setSuit(static_cast<Card::CardSuit>(s));
            c.setPoint(static_cast<Card::CardPoint>(p));
            m_allCards.addCard(c);
        }
    }
    m_allCards.addCard(Card(Card::Card_SJ,Card::King));
    m_allCards.addCard(Card(Card::Card_BJ, Card::King));
}

void GameControl::initPlayer()
{
    //实例化玩家
    m_leftRobot=new Robot("机器人A",this);
    m_RightRobot=new Robot("机器人B",this);
    m_userPlayer=new UserPlayer("玩家",this);

    //头像显示
    m_leftRobot->setDirection(Player::Left);
    m_RightRobot->setDirection(Player::Right);
    m_userPlayer->setDirection(Player::Right);

    //性别
    Player::Sex sex;
    sex=static_cast<Player::Sex>(QRandomGenerator::global()->bounded(2));
    m_leftRobot->setSex(sex);
    sex=static_cast<Player::Sex>(QRandomGenerator::global()->bounded(2));
    m_RightRobot->setSex(sex);
    sex=static_cast<Player::Sex>(QRandomGenerator::global()->bounded(2));
    m_userPlayer->setSex(sex);

    //出牌顺寻
    m_userPlayer->setPrePlayer(m_leftRobot);
    m_userPlayer->setNextPlayer(m_RightRobot);

    // left robot
    m_leftRobot->setPrePlayer(m_RightRobot);
    m_leftRobot->setNextPlayer(m_userPlayer);

    // right robot
    m_RightRobot->setPrePlayer(m_userPlayer);
    m_RightRobot->setNextPlayer(m_leftRobot);

    //指定当前玩家;
    setCurPlayer(m_userPlayer);

}

Robot *GameControl::getLeftRobot()
{
    return m_leftRobot;
}

Robot *GameControl::getRightRobot()
{
    return m_RightRobot;
}

UserPlayer *GameControl::getUserPlayer()
{
    return m_userPlayer;
}

Player *GameControl::getPendPlayer()
{
    return m_pendPlayer;
}

Cards GameControl::getPendCards()
{
    return m_pendCards;
}

void GameControl::setCurPlayer(Player *cur_player)
{
    m_curPlayer=cur_player;
}


Player *GameControl::getCurPlayer()
{
    return m_curPlayer;
}

void GameControl::clearPlayerScore()
{
    m_leftRobot->setScore(0);
    m_RightRobot->setScore(0);
    m_userPlayer->setScore(0);
}

void GameControl::resetCardData()
{
    //洗牌
    initAllCards();
    //清空所有的牌
    m_RightRobot->clearCards();
    m_leftRobot->clearCards();
    m_userPlayer->clearCards();
    //初始化
    m_pendCards.clear();
    m_pendPlayer=nullptr;

}

void GameControl::startLordCard()
{
    m_curPlayer->prepareCallLord();
}

void GameControl::becomeLord(Player *player)
{
    player->setRole(Player::Lord);
    player->getPrePlayer()->setRole(Player::Farmer);
    player->getNextPlayer()->setRole(Player::Farmer);

    //设置为地主，获取最后三张牌
    m_curPlayer=player;
    player->storeDispatchCard(m_allCards);

    //准备出牌
    m_curPlayer->preparePlayHand();


}
