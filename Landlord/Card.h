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
        Diamond=0,	//����
        Club=1,		//÷��
        Heart=2,	//����
        Spade=3,	//����
        King=4,     //��С��
		Suit_End,
	};
	//����

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
        Card_SJ = 16,   // С��
        Card_BJ = 17,	//����
		Card_End,
	};
    Card():m_point(Card_Begin),m_suit(Suit_Begin){}
	~Card(){}

	void setPoint(CardPoint point){ m_point = point; }
	CardPoint getPoint(){ return m_point; }

	void setSuit(CardSuit suit){ m_suit = suit; }
	CardSuit getSuit(){ return m_suit; }

    // ���� operator< �Ա� std::set ���Խ��бȽ�
    bool operator<(const Card& other) const {
        if (m_point != other.m_point) {
            return m_point < other.m_point;
        }
        return m_suit < other.m_suit;
    }
private:
	CardPoint m_point;	//����
	CardSuit m_suit;		//��ɫ
};

