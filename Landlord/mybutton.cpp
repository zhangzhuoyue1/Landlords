#include "mybutton.h"

#include <QPainter>
#include <qevent.h>


MyButton::MyButton(QWidget *parent)
    :QPushButton(parent)
{

}

void MyButton::setImage(QString normal, QString hover, QString pressed)
{
    m_normal=normal;
    m_hover=hover;
    m_pressed=pressed;

    m_pixmap.load(m_normal);
}


void MyButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        //切换图片
        m_pixmap.load(m_pressed);
        update();
    }
    return QPushButton::mousePressEvent(event);
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        //切换图片
        m_pixmap.load(m_normal);
        update();
    }
    return QPushButton::mouseReleaseEvent(event);
}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect(),m_pixmap);

    return QPushButton::paintEvent(event);
}

void MyButton::enterEvent(QEnterEvent *event)
{
    m_pixmap.load(m_hover);
    update();
    return QPushButton::enterEvent(event);
}

void MyButton::leaveEvent(QEvent *event)
{

}



