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
		Diamond,	//方块
		Club,		//梅花
		Heart,		//红桃
		Spade,		//梅花
		Suit_End,
	};
	//点数

	enum CardPoint {
		Card_Begin,
		Card_3,
		Card_4,
		Card_5,
		Card_6,
		Card_7,
		Card_8,
		Card_9,
		Card_10,
		Card_J,
		Card_Q,
		Card_K,
		Card_A,
		Card_2,
		Card_SJ,	//小王
		Card_BJ,	//大王
		Card_End,
	};
	Card(){}
	~Card(){}

	void setPoint(CardPoint point){ m_point = point; }
	CardPoint getPoint(){ return m_point; }

	void setSuit(CardSuit suit){ m_suit = suit; }
	CardSuit getSuit(){ return m_suit; }

private:
	CardPoint m_point;	//点数
	CardSuit m_suit;		//花色

};

