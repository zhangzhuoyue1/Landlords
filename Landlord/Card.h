#pragma once
/*
* Card.h
* ������һЩ�����Ŀ�������
*/

class Card
{
public:
	//��ɫ
	enum CardSuit{
		Suit_Begin,
		Diamond,	//����
		Club,		//÷��
		Heart,		//����
		Spade,		//÷��
		Suit_End,
	};
	//����

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
		Card_SJ,	//С��
		Card_BJ,	//����
		Card_End,
	};
	Card(){}
	~Card(){}

	void setPoint(CardPoint point){ m_point = point; }
	CardPoint getPoint(){ return m_point; }

	void setSuit(CardSuit suit){ m_suit = suit; }
	CardSuit getSuit(){ return m_suit; }

private:
	CardPoint m_point;	//����
	CardSuit m_suit;		//��ɫ

};

