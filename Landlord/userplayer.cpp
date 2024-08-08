#include "userplayer.h"

UserPlayer::UserPlayer(QString name, QObject *parent)
    : Player{name,parent}
{
    m_type=Player::User;
}

UserPlayer::UserPlayer( QObject *parent)
    : Player{parent}
{
    m_type=Player::User;
}


void UserPlayer::prepareCallLord()
{

}

void UserPlayer::preparePlayHand()
{

}

void UserPlayer::thinkCallLord()
{

}

void UserPlayer::thinkPlayHand()
{

}
