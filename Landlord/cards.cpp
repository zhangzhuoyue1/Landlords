#include "cards.h"
#include <QRandomGenerator>
#include <QDebug>
Cards::Cards() {
    qDebug()<<"create Cards";
}

void Cards::addCard(const Card &card)
{
    m_cards.insert(card);
}

void Cards::addCards(const Cards &cards)
{
    m_cards.insert(cards.m_cards.begin(),cards.m_cards.end());
}

Cards &Cards::operator <<(const Card &card)
{
    this->addCard(card);
    return *this;
}
Cards &Cards::operator << (const Cards &cards)
{
    this->addCards(cards);
    return *this;
}

void Cards::removeCard(const Card &card)
{
    m_cards.erase(card);
}

void Cards::removeCards(const Cards &cards)
{
    m_cards.erase(cards.m_cards.begin(),cards.m_cards.cend());
}

bool Cards::isEmpty()
{
    return m_cards.empty();
}

int Cards::cardCount()
{
    qDebug()<<m_cards.size();
    return m_cards.size();
}

bool Cards::isExistCard(const Card &card)
{
    return m_cards.count(card)==1;
}

bool Cards::isExistCards(const Cards &cards)
{
    for(auto it=cards.m_cards.begin();it!=cards.m_cards.end();it++){
        if(m_cards.count(*it)==0)
        {
            return false;
        }
    }
    return true;
}

Card Cards::takeRandomCard()
{
    // 生成一个随机数
    int num = QRandomGenerator::global()->bounded(m_cards.size());
    auto it = m_cards.begin();
    for(int i=0; i<num; ++i, ++it);
    Card card = *it;
    m_cards.erase(*it);
    return card;
}

void Cards::clear()
{
    m_cards.clear();
}

int Cards::pointCount(int point)
{
    int count=0;
    for(auto it=m_cards.begin();it!=m_cards.end();it++){
        Card card=*it;
        if(card.getPoint()==point)
            count++;
    }
    return count;
}

int Cards::minPoint()
{
    if (m_cards.empty()) return -1;
    auto it= m_cards.begin();
    Card card=*it;
    return card.getPoint();
}

int Cards::maxPoint()
{
    if (m_cards.empty()) return -1;
    auto it=m_cards.end();
    --it;
    Card card=*it;
    return card.getPoint();
}

void Cards::displayCards()
{
    int i=1;
    for(auto it=m_cards.begin();it!=m_cards.end();it++){
        Card card=*it;
        qDebug()<<i<<" point :"<<card.getPoint()<<" suit: "<<card.getSuit();
    }
}
