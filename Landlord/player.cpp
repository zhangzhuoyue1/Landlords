#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent},
    m_prevPlayer(nullptr),m_nextPlayer(nullptr),m_pendPlayer(nullptr),m_score(0),m_isWin(false)
{}

Player::Player(QString name, QObject *parent):Player(parent)
    // :QObject{parent},
    // m_name(name),m_prevPlayer(nullptr),m_nextPlayer(nullptr),m_pendPlayer(nullptr),m_score(0),m_isWin(false)
{
    m_name=name;
}

void Player::setName(const QString name)
{
    m_name=name;
}

void Player::setType(const Type type)
{
    m_type=type;
}

void Player::setRole(const Role role)
{
    m_role=role;
}

void Player::setScore(int score)
{
    m_score=score;
}

void Player::setPrePlayer(Player *player)
{
    m_prevPlayer=player;
}

void Player::setNextPlayer(Player *player)
{
    m_nextPlayer=player ;
}

void Player::setDirection(Direction direct)
{
    m_direct=direct;
}

QString Player::getName()
{
    return m_name;
}

Player::Type Player::getType()
{
    return m_type;
}

Player::Role Player::getRole()
{
    return m_role;
}

int Player::getScore()
{
    return m_score;
}

Player *Player::getPrePlayer()
{
    return m_prevPlayer;
}

Player *Player::getNextPlayer()
{
    return m_nextPlayer;
}

Player::Direction Player::getDirection()
{
    return m_direct;
}

Cards Player::getCards()
{
    return m_cards;
}

Player::Sex Player::getSex()
{
    return m_sex;
}

Player *Player::getPendPlayer()
{
    return m_pendPlayer;
}

void Player::clearCards()
{
    m_cards.clear();
}

Cards Player::getPendCards()
{
    return m_pendCards;
}

bool Player::siWin()
{
    return m_isWin;
}

void Player::playHand(Cards &cards)
{
    m_cards.removeCards(cards);
    emit sig_playHand(this, cards);
}

void Player::getPandingInfo(Player *player, const Cards &cards)
{
    m_pendCards=cards;
    m_pendPlayer=player;
}

void Player::storeDispatchCard(const Card &card)
{
    m_cards.addCard(card);
    Cards cs;
    cs.addCard(card);
    emit sig_pickCards(this, cs);
}

void Player::storeDispatchCard(const Cards &cards)
{
    m_cards.addCards(cards);
    emit sig_pickCards(this, cards);
}

void Player::grabLordBet(int point)
{
    emit sig_grabLordBet(this,point);
}

