#include "CardPanel.h"

#include <QMouseEvent>

CardPanel::CardPanel(QWidget*parent)
	: QWidget(parent)
{}

CardPanel::~CardPanel()
{}

void CardPanel::setImage(QPixmap &front, QPixmap &back)
{
    m_front=front;
    m_back=back;
    setFixedSize(m_front.size());
    update();
}

QPixmap CardPanel::getImage()
{
    return m_front;
}

void CardPanel::setCard(Card card)
{
    m_card=card;
}

Card CardPanel::getCard()
{
    return  m_card;
}

void CardPanel::setOwner(std::unique_ptr<Player> player)
{
    m_player=std::move(player);
}

std::unique_ptr<Player> CardPanel::getPlayer()
{
    return  std::move(m_player);
}

void CardPanel::setFontSide(bool isFont)
{
    m_isFront=isFont;
}

bool CardPanel::getIsFront()
{
    return m_isFront;
}

void CardPanel::setSelected(bool isSelect)
{
    m_isSelected=isSelect;
}

bool CardPanel::getIsSelected()
{
    return m_isSelected;
}


void CardPanel::paintEvent(QPaintEvent *event)
{

}


void CardPanel::mousePressEvent(QMouseEvent *event)
{
    //判断是否为鼠标左键点击
    if(event->button()==Qt::LeftButton){
        qDebug() << "Left mouse button clicked.";
            // 处理左键点击事件

        //发送信号通知窗口被选中
        emit sig_cardSelected();
    }
    return QWidget::mousePressEvent(event);
}
