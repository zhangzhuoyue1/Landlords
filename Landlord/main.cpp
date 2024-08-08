#include "mainwindow.h"
#include "Logger.h"
#include <QApplication>
#include "cards.h"
#include <QDebug>

void CardsTest(){
    qDebug()<<"init";
    Cards* cards=new Cards();
    for(int i=0;i<55;i++){
        cards->takeRandomCard();
    }
    qDebug()<<cards->cardCount();
    Card card;
    card.setPoint(Card::Card_10);
    card.setSuit(Card::Heart);
    cards->removeCard(card);
    qDebug()<<cards->minPoint();
    qDebug()<<cards->maxPoint();
    cards->clear();
    qDebug()<<cards->cardCount();
    LOG("This is a test log message.");

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    CardsTest();
    return a.exec();
}
