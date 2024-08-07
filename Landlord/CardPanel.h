#pragma once

#include <QWidget>
#include <QPixmap>
#include "Card.h"

/*
 * ���ƴ�����
*/

class CardPanel  : public QWidget
{
	Q_OBJECT

public:
	explicit CardPanel(QWidget* parent = nullptr);
	~CardPanel();
	
	//���û�ȡͼƬ���ں���
	void setImage(QPixmap &front,QPixmap &back);
	QPixmap getImage();

    //�����Ƶ�����
    void setCard(Card::CardPoint point,Card::CardSuit suit);
    Card getCard();

    //�����Ƶ�������
    void setFontSide(bool isFont);
    bool getIsFront();

    //������ѡ��
    void setSelected(bool isSelect);
    bool getIsSelected();
private:
    QPixmap m_front;     //����ͼƬ
    QPixmap m_back;     //����ͼƬ
    bool m_isFront;     //��¼��ǰ�Ƿ�Ϊ����
    bool m_isSelected;    //�Ƿ�ѡ��
    Card m_card;        //�Ƶ�������Ϣ
signals:
    emit void sig_cardSelected(); //֪ͨ���ڱ�ѡ��

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
};
