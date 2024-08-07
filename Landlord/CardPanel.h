#pragma once

#include <QWidget>
#include <QPixmap>
#include "Card.h"
#include "player.h"
/*
 * 卡牌窗口类
*/

class CardPanel  : public QWidget
{
	Q_OBJECT

public:
	explicit CardPanel(QWidget* parent = nullptr);
	~CardPanel();
	
	//设置获取图片窗口函数
	void setImage(QPixmap &front,QPixmap &back);
	QPixmap getImage();

    //设置牌的属性
    void setCard(Card card);
    Card getCard();

    //设置牌的所有者
    void setOwner(std::unique_ptr<Player> player);
    std::unique_ptr<Player> getPlayer();

    //设置牌的正反面
    void setFontSide(bool isFont);
    bool getIsFront();

    //设置牌选中
    void setSelected(bool isSelect);
    bool getIsSelected();
private:
    QPixmap m_front;     //正面图片
    QPixmap m_back;     //背面图片
    bool m_isFront;     //记录当前是否为正面
    bool m_isSelected;    //是否被选中
    Card m_card;        //牌的属性信息
    std::unique_ptr<Player> m_player;   //当前牌的所有者
signals:
    emit void sig_cardSelected(); //通知窗口被选中

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
};
