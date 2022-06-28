#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <cmath>

#include "ex.h"

Ex::Ex(){

    TBmute.loadFromFile("asset/sonsok.png");
    Bmute.setTexture(TBmute);
    Bmute.setOrigin(TBmute.getSize().x*0.5,TBmute.getSize().y*0.5);

    TBquit.loadFromFile("asset/Exit.png");
    Bquit.setTexture(TBquit);
    Bquit.setOrigin(TBquit.getSize().x*0.5,TBquit.getSize().y*0.5);

        TBsolo.loadFromFile("asset/Bsolo.png");
    Bsolo.setTexture(TBsolo);
    Bsolo.setOrigin(TBsolo.getSize().x*0.5,TBsolo.getSize().y*0.5);

            TBmultil.loadFromFile("asset/Bmultilocal.png");
    Bmultil.setTexture(TBmultil);
    Bmultil.setOrigin(TBmultil.getSize().x*0.5,TBmultil.getSize().y*0.5);

            TBmultir.loadFromFile("asset/BmultiLAN.png");
    Bmultir.setTexture(TBmultir);
    Bmultir.setOrigin(TBmultir.getSize().x*0.5,TBmultir.getSize().y*0.5);

        TBreturn.loadFromFile("asset/back.png");
    Breturn.setTexture(TBreturn);
    Breturn.setOrigin(TBreturn.getSize().x*0.5,TBreturn.getSize().y*0.5);

        TfondP.loadFromFile("asset/fond.png");
    TfondP.setSmooth(true);
    fondP.setTexture(TfondP);

        TfondS.loadFromFile("asset/fond_solo.png");
    TfondS.setSmooth(true);
    fondS.setTexture(TfondS);

        font.loadFromFile("asset/font.ttf");

        TBjoin.loadFromFile("asset/join.png");
    Bjoin.setTexture(TBjoin);
    Bjoin.setOrigin(TBjoin.getSize().x*0.5,TBjoin.getSize().y*0.5);

        TBcreate.loadFromFile("asset/create.png");
    Bcreate.setTexture(TBcreate);
    Bcreate.setOrigin(TBcreate.getSize().x*0.5,TBcreate.getSize().y*0.5);

    IPH=sf::IpAddress::getLocalAddress();

    SBbounces.loadFromFile("asset/bouces.wav");
    SBfinish.loadFromFile("asset/finish.wav");

    bouces.setBuffer(SBbounces);
    finish.setBuffer(SBfinish);

    music.openFromFile("asset/music.wav");
    music.setLoop(true);

    icon.loadFromFile("asset/ico.png");
        }
void Ex::pos(){
        Bmute.setPosition(0.25*widht,0.66*height);
        Bquit.setPosition(0.75*widht,0.66*height);
        Breturn.setPosition(0.25*widht,0.16*height);

        Bsolo.setPosition(0.5*widht,0.25*height);
        Bmultil.setPosition(0.5*widht,0.5*height);
        Bmultir.setPosition(0.5*widht,0.75*height);
        Bjoin.setPosition(0.5*widht,0.33*height);
        Bcreate.setPosition(0.5*widht,0.66*height);



        fondP.setScale((widht/330+0.82),(height/247.5));
        fondS.setScale((widht/330+0.82),(height/247.5));



        ball.setRadius((0.08-(0.08-0.02))*widht);
        ball.setOutlineThickness((0.08*0.02)*widht);
        ball.setOutlineColor(sf::Color::White);
        ball.setFillColor(sf::Color::Green);
        ball.setOrigin(ball.getRadius()/2,ball.getRadius()/2);
        ball.setPosition(widht/2,height/2);

}
void Ex::moveBall(){
    ball.move(std::cos(ballAngle) * ballSpeed, std::sin(ballAngle) * ballSpeed);
}
void Ex::volume(){
    if (sons==100){
        sons=0;
        TBmute.loadFromFile("asset/mute.png");
        Bmute.setTexture(TBmute);
        }
    else{
        sons=100;
        TBmute.loadFromFile("asset/sonsok.png");
        Bmute.setTexture(TBmute);
    }
        finish.setVolume(sons);
        bouces.setVolume(sons);
        music.setVolume(sons);
}
