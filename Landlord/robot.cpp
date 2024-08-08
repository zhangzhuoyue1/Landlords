#include "robot.h"

Robot::Robot(QObject *parent)
    : Player{parent}
{
    m_type=Player::Robot;
}

Robot::Robot(QString name, QObject *parent)
    :Player(name,parent)
{

}

void Robot::prepareCallLord()
{

}

void Robot::preparePlayHand()
{

}

void Robot::thinkCallLord()
{

}

void Robot::thinkPlayHand()
{

}
