#ifndef CARDS_H
#define CARDS_H
#include "Card.h"
#include <set>


/******************************************************************************
 *
 * @file       cards.h
 * @brief      对多张卡牌进行处理
 *
 * @author     我好想睡觉
 * @date       2024/03/07
 * @history
 *****************************************************************************/

class Cards
{
public:
    Cards();

    void addCard(const Card& card);             //添加卡牌
    void addCards(const Cards& cards);          //添加卡牌
    Cards& operator <<(const Card& card);       //一次性插入多个数据
    Cards &operator <<(const Cards &cards);
    void removeCard(const Card& card);          //删除卡牌
    void removeCards(const Cards& cards);
    bool isEmpty();                             //判断是否为空
    int cardCount();                           //获取数量
    bool isExistCard(const Card& card);         //判断是否存在
    bool isExistCards(const Cards& cards);
    Card takeRandomCard();                      //随机发一张牌
    void clear();                               //清空手里的牌
    int pointCount(int point);                  //计算指定点数扑克牌的张数
    int minPoint();                             //得到牌的最小点数
    int maxPoint();                             //得到牌的最大点数
    void displayCards();                        //打印牌堆
private:
    std::set<Card> m_cards;
};


#endif // CARDS_H
