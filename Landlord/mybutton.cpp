#include "mybutton.h"
#include "Logger.h"
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
    update();
}


void MyButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        //切换图片
        if(!m_pixmap.load(m_pressed))
            Log("Failed to load pressed");
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
    Q_UNUSED(event);
    QPainter p(this);
    p.drawPixmap(rect(),m_pixmap);

}

void MyButton::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    m_pixmap.load(m_hover);
    update();
}

void MyButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_pixmap.load(m_normal);
    update();
}



