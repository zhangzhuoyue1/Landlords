#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QPixmap>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent = nullptr);
    void setImage(QString normal,QString hover,QString pressed);

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void enterEvent(QEnterEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
private:
    QString m_normal;
    QString m_hover;
    QString m_pressed;
    QPixmap m_pixmap;
};

#endif // MYBUTTON_H
