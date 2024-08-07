#pragma once
/*
* Card.h
* 包含了一些基本的卡牌属性
*/

class Card
{
public:
	//花色
	enum CardSuit{
		Suit_Begin,
        Diamond=0,	//方块
        Club=1,		//梅花
        Heart=2,	//红桃
        Spade=3,	//黑桃
        King=4,     //大小王
		Suit_End,
	};
	//点数

	enum CardPoint {
		Card_Begin,
        Card_3=3,
        Card_4=4,
        Card_5=5,
        Card_6=6,
        Card_7 = 7,
        Card_8 = 8,
        Card_9 = 9,
        Card_10 = 10,
        Card_J = 11,
        Card_Q = 12,
        Card_K = 13,
        Card_A = 14,
        Card_2 = 15,
        Card_SJ = 16,   // 小王
        Card_BJ = 17,	//大王
		Card_End,
	};
    Card():m_point(Card_Begin),m_suit(Suit_Begin){}
	~Card(){}

	void setPoint(CardPoint point){ m_point = point; }
	CardPoint getPoint(){ return m_point; }

	void setSuit(CardSuit suit){ m_suit = suit; }
	CardSuit getSuit(){ return m_suit; }

    // 定义 operator< 以便 std::set 可以进行比较
    bool operator<(const Card& other) const {
        if (m_point != other.m_point) {
            return m_point < other.m_point;
        }
        return m_suit < other.m_suit;
    }
private:
	CardPoint m_point;	//点数
	CardSuit m_suit;		//花色
};

