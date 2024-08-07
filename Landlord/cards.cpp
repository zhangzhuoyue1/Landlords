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
    qDebug()<<"开始发牌";
    if (m_cards.size() == 54) { // Assuming a standard deck size
        qDebug() << "所有的牌都已经发出，牌库中已经没有牌";
        return Card();
    }
    Card card;
    while(true){
        Card tmp_card;

        int point=QRandomGenerator::global()->bounded(3,18);
        if (point == 16) {
            // 小王只有一张
            tmp_card.setPoint(Card::Card_SJ);
            tmp_card.setSuit(Card::King);
        } else if (point == 17) {
            // 大王只有一张
            tmp_card.setPoint(Card::Card_BJ);
            tmp_card.setSuit(Card::King);
        } else {
            int suit = QRandomGenerator::global()->bounded(0, 4);
            tmp_card.setPoint(static_cast<Card::CardPoint>(point));
            tmp_card.setSuit(static_cast<Card::CardSuit>(suit));
        }

        if (!isExistCard(tmp_card)) {
            m_cards.insert(tmp_card);
            card = tmp_card;
            qDebug() << "发出一张牌 point:" << point << " suit:" << card.getSuit();
            break;
        }
    }

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
