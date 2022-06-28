#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ex.h"

    sf::RenderWindow window;

void setup();


void soloS();
void solo();

void multiLS();
void multiL();


void multiRS();

void multiRHS();
void multiRH();

void multiRCS();
void multiRC();

FILE* highScore;
Ex Ex;
int pi=3.14159;
        sf::Text scoreT;
        sf::Text Highscore;
        sf::Text start;
        sf::Text nHS;
        std::string scoreM;
        std::string score="Score: ";
        sf::Text scoreB;
        sf::Text scoreR;


int main(){
    sf::Event event;
    highScore=fopen("asset/HighScore.HS","wb ");
    fclose(highScore);
    setup();
    Ex.pos();
       sf::Clock clock;
    clock.restart().asMilliseconds();
         while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed||(Ex.Bquit.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                    window.close();
                }}
             if (clock.getElapsedTime().asMilliseconds() >= 150){
                if (Ex.Bmute.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    Ex.volume();
                        clock.restart().asMilliseconds();
                            }}

                if (Ex.Bsolo.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    soloS();
                if (Ex.Bmultil.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    multiLS();
                if (Ex.Bmultir.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    multiRS();
            window.clear(sf::Color::Black);

                window.draw(Ex.fondP);
                window.draw(Ex.Bmute);
                window.draw(Ex.Bquit);
                window.draw(Ex.Bsolo);
                window.draw(Ex.Bmultil);
                window.draw(Ex.Bmultir);

            window.display();
            fclose(highScore);
         }

    return 0;
}
void setup(){



    window.create(sf::VideoMode(),"Pong",sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    window.setIcon(32,32,Ex.icon.getPixelsPtr());
    Ex.height=window.getSize().y;
    Ex.widht=window.getSize().x;

        scoreT.setFont(Ex.font);

        Highscore.setFont(Ex.font);
        Highscore.setCharacterSize(75);
        Highscore.setFillColor(sf::Color::Red);
        Highscore.setPosition(Ex.widht*0.25,Ex.height*0.33);

        start.setFont(Ex.font);
        start.setCharacterSize(100);
        start.setOrigin(375.,50.);
        start.setFillColor(sf::Color::Red);
        start.setString("press enter to start");
        start.setPosition(Ex.widht*0.5,Ex.height*0.5);

        scoreT.setCharacterSize(75);
        scoreT.setFillColor(sf::Color::Red);


        nHS.setFont(Ex.font);
        nHS.setCharacterSize(50);
        nHS.setFillColor(sf::Color::Yellow);
        nHS.setString("New Hight score!!!");
        nHS.setPosition(Ex.widht*0.66,Ex.height*0.25);

        scoreB.setFont(Ex.font);
        scoreB.setCharacterSize(100);
        scoreB.setFillColor(sf::Color::Blue);
        scoreB.setString("0");
        scoreB.setOrigin(scoreB.getGlobalBounds().width,0);
        scoreB.setPosition(Ex.widht*0.49,0);

        scoreR.setFont(Ex.font);
        scoreR.setCharacterSize(100);
        scoreR.setFillColor(sf::Color::Red);
        scoreR.setString("0");
        scoreR.setPosition(Ex.widht*0.51,0);
}

void soloS(){
        sf::Event event;
        char hS[100]="";
        highScore=fopen("asset/HighScore.HS","rb");
        fgets(hS,100,highScore);
        std::string HS="Highscore: ";
        std::string HSM= HS+hS;
        Highscore.setString(HSM);
               sf::Clock clock;
    clock.restart().asMilliseconds();
     while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed||(Ex.Bquit.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                    window.close();
                }}
             if (clock.getElapsedTime().asMilliseconds() >= 150){
                if (Ex.Bmute.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    Ex.volume();
                        clock.restart().asMilliseconds();
                            }}

                if (Ex.Breturn.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    return;
                    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    Highscore.setString(hS);
                    solo();
                    fgets(hS,100,highScore);
                    scoreT.setPosition(Ex.widht*0.5,Ex.height*0.75);
                    std::string HSM= HS+hS;
                    Highscore.setString(HSM);
                }
           scoreT.setString(scoreM);
            window.clear(sf::Color::Black);

                window.draw(Ex.fondS);
                window.draw(Ex.Bmute);
                window.draw(Ex.Bquit);
                window.draw(Ex.Breturn);
                window.draw(Highscore);
                window.draw(start);
                window.draw(scoreT);



             if (Ex.tex>hS){
                    window.draw(nHS);
                    fclose(highScore);
                    highScore=fopen("asset/Highscore.hs","wb+");
                fprintf(highScore,"%d",Ex.retour);
                    fclose(highScore);
                highScore=fopen("asset/Highscore.hs","rb");
                }
        window.display();
    }
}
void solo(){
        sf::Vector2f Vpalet(0,0);
        Vpalet.y=Ex.height/20;
        Vpalet.x=Ex.widht/5;

        sf::RectangleShape palet;
        palet.setSize(Vpalet);
        palet.setOutlineThickness(Vpalet.y/10);
        palet.setOutlineColor(sf::Color::Red);
        palet.setFillColor(sf::Color::Red);
        palet.setOrigin(Vpalet.x/2,Vpalet.y/2);
        palet.setPosition(Ex.widht/2,Ex.height-Ex.height/20);


        sf::Event event;

        scoreT.setPosition(10,10);
        scoreT.setString("0");
        Ex.retour=0;
        Ex.ballSpeed=5;
        Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
        do
            {
            Ex.ballAngle = (std::rand() % 360) * 2 * pi / 360;
            }while (std::abs(std::cos(Ex.ballAngle)) > 0.7f);

            while (window.isOpen()){
                while (window.pollEvent(event)){
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
            window.clear(sf::Color::Black);
                window.draw(Ex.fondS);
                window.draw(Ex.ball);
                window.draw(palet);
                window.draw(scoreT);
                Ex.moveBall();

        window.display();
        Ex.tex= std::to_string(Ex.retour);
        std::string scorN= std::to_string(Ex.retour);
        scoreM=score+scorN;
        scoreT.setString(scoreM);

        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::Q))&&(palet.getPosition().x-(Vpalet.x/2)>=0))
                palet.move(-20,0);
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D))&& (palet.getPosition().x+(Vpalet.x/2)<=Ex.widht))
            palet.move(20,0);

        if((Ex.ball.getPosition().x+Ex.ball.getRadius())>Ex.widht)
                Ex.ballAngle= pi - Ex.ballAngle + (std::rand() % 20) * pi / 180;

        else if((Ex.ball.getPosition().x-Ex.ball.getRadius())<0)
                Ex.ballAngle= pi - Ex.ballAngle + (std::rand() % 20) * pi / 180;

        else if((Ex.ball.getPosition().y-Ex.ball.getRadius())<0){
                Ex.ballAngle= -Ex.ballAngle;
                Ex.ball.move(0,3);
                }
        if(Ex.ball.getGlobalBounds().intersects(palet.getGlobalBounds())){
            Ex.ballAngle= -Ex.ballAngle;
            Ex.retour++;
            Ex.ballSpeed+=1.5;
            Ex.ball.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255,255));
            Ex.bouces.play();
        }
        if (Ex.ball.getPosition().y+Ex.ball.getRadius()>=Ex.height){
            Ex.finish.play();
            return;
        }}
}

void multiLS(){
     sf::Event event;
            sf::Clock clock;
    clock.restart().asMilliseconds();
        while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                    start.setFillColor(sf::Color::Red);
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed||(Ex.Bquit.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                    window.close();
                }}
             if (clock.getElapsedTime().asMilliseconds() >= 150){
                if (Ex.Bmute.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    Ex.volume();
                        clock.restart().asMilliseconds();
                            }}

                if (Ex.Breturn.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                        multiL();
                window.clear(sf::Color::Black);
                window.draw(Ex.fondP);
                window.draw(Ex.Bmute);
                window.draw(Ex.Bquit);
                window.draw(Ex.Breturn);
                window.draw(start);

        window.display();
    }
}
void multiL(){
    short PointB=0;
    short PointR=0;
    std::string Bpoint="0";
    std::string Rpoint="0";
    sf::Vector2f Dpalet(Ex.widht/30,Ex.height/5);
    sf::RectangleShape Bpalet;
    sf::RectangleShape Rpalet;

    Bpalet.setSize(Dpalet);
    Bpalet.setFillColor(sf::Color::Blue);
    Bpalet.setOrigin(0,Dpalet.y/2);
    Bpalet.setPosition(Ex.widht/50,Ex.height/2);

    Rpalet.setSize(Dpalet);
    Rpalet.setFillColor(sf::Color::Red);
    Rpalet.setOrigin(Dpalet.x,Dpalet.y/2);
    Rpalet.setPosition(Ex.widht-Ex.widht/50,Ex.height/2);

    sf::Event event;

    scoreB.setString("0");
    scoreR.setString("0");

    Ex.ballSpeed=3;
    Ex.ball.setPosition(Ex.widht/2,Ex.height/2);

        while (window.isOpen()){
                  while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }}
                if((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))&& Bpalet.getPosition().y-Bpalet.getSize().y/2>0)
                    Bpalet.move(0,-10);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& Bpalet.getPosition().y+Bpalet.getSize().y/2<Ex.height)
                    Bpalet.move(0,10);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& Rpalet.getPosition().y-Rpalet.getSize().y/2>0)
                    Rpalet.move(0,-10);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&( Rpalet.getPosition().y+Rpalet.getSize().y/2<Ex.height)){
                    Rpalet.move(0,10);}

                    scoreB.setString(Bpoint);
                    scoreR.setString(Rpoint);
                    Ex.ballSpeed*=1.0001;
            window.clear(sf::Color::Black);
                Ex.moveBall();
                window.draw(Ex.fondP);
                window.draw(scoreB);
                window.draw(scoreR);
                window.draw(Bpalet);
                window.draw(Rpalet);
                window.draw(Ex.ball);
            window.display();

            if(Ex.ball.getPosition().y-Ex.ball.getRadius()-Ex.ball.getOutlineThickness()<0||Ex.ball.getPosition().y+Ex.ball.getRadius()+Ex.ball.getOutlineThickness()>Ex.height)
                Ex.ballAngle= -Ex.ballAngle;

            if(Ex.ball.getGlobalBounds().intersects(Rpalet.getGlobalBounds())||Ex.ball.getGlobalBounds().intersects(Bpalet.getGlobalBounds())){
                Ex.ballAngle= pi - Ex.ballAngle + (std::rand() % 20) * pi / 180;
                Ex.ballSpeed+=1.5;
                Ex.ball.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255,255));
                Ex.bouces.play();
            }
            if (Ex.ball.getPosition().x<0){
                Ex.ballSpeed=5;
                Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
                PointR++;
                Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
                Rpoint= std::to_string(PointR);
                Ex.ballAngle=rand()%360;
            }
            if (Ex.ball.getPosition().x>Ex.widht){
                Ex.ballSpeed=5;
                Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
                PointB++;
                Bpoint= std::to_string(PointB);
                Ex.ballAngle=rand()%360;

            }
            if(PointB>=10){
                sf::Text Bwin;
                Bwin.setFont(Ex.font);
                Bwin.setCharacterSize(100);
                Bwin.setString("The player Blue win !!!\n press space to continue");
                Bwin.setOrigin(Bwin.getGlobalBounds().width/2,Bwin.getGlobalBounds().height/2);
                Bwin.setPosition(Ex.widht/2,Ex.height/2);
                Bwin.setFillColor(sf::Color::Blue);
                Ex.finish.play();
                do{
                    window.draw(Bwin);
                    window.display();
                }while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==false);
                return;
            }
            if(PointR>=10){
                sf::Text Rwin;
                Rwin.setFont(Ex.font);
                Rwin.setCharacterSize(100);
                Rwin.setString("The player Red win !!!\n press space to continue");
                Rwin.setOrigin(Rwin.getGlobalBounds().width/2,Rwin.getGlobalBounds().height/2);
                Rwin.setPosition(Ex.widht/2,Ex.height/2);
                Rwin.setFillColor(sf::Color::Red);
                Ex.finish.play();
                do{
                    window.draw(Rwin);
                    window.display();
                }while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==false);
                return;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                return;
    }
    return;
}

void multiRS(){
           sf::Clock clock;
    clock.restart().asMilliseconds();
    sf::Event event;
        while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed||(Ex.Bquit.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                    window.close();
                }}
             if (clock.getElapsedTime().asMilliseconds() >= 150){
                if (Ex.Bmute.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    Ex.volume();
                        clock.restart().asMilliseconds();
                            }}

                if (Ex.Breturn.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return;
                if (Ex.Bjoin.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    multiRCS();
                if (Ex.Bcreate.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    multiRHS();
            window.clear(sf::Color::Black);
                window.draw(Ex.fondP);
                window.draw(Ex.Bmute);
                window.draw(Ex.Bquit);
                window.draw(Ex.Breturn);
                window.draw(Ex.Bcreate);
                window.draw(Ex.Bjoin);
            window.display();
    }
}
void multiRCS(){
           sf::Clock clock;
    sf::Text Vip;
    clock.restart().asMilliseconds();
    Vip.setCharacterSize(75);
    Vip.setFont(Ex.font);
    Vip.setString("wait");
    Vip.setOrigin(Vip.getGlobalBounds().width/2,Vip.getGlobalBounds().top/2);
    Vip.setPosition(Ex.widht/2,Ex.height*0.75);

    sf::Text ipT;
    sf::String IPS("IP: ");
    char ip;
    bool Vvip=false;
    ipT.setCharacterSize(75);
    ipT.setFont(Ex.font);
    ipT.setString(IPS);
    sf::Event event;
    std::string iph;

    //reseaux
        sf::UdpSocket socket;
        sf::IpAddress sender;
        unsigned short port;
        int data[4];

            sf::Packet send;
        socket.bind(54000);
       socket.setBlocking(false);

        while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed||(Ex.Bquit.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                    window.close();
                }
             if (clock.getElapsedTime().asMilliseconds() >= 150){
                if (Ex.Bmute.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    Ex.volume();
                        clock.restart().asMilliseconds();
                            }}

                if (Ex.Breturn.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return;

        if (clock.getElapsedTime().asMilliseconds() >= 150)
                {
                if (event.type == sf::Event::TextEntered)
                            { if((event.text.unicode > 30 && (event.text.unicode < 128 || event.text.unicode > 159)))
                                {
                                    ip = (event.text.unicode);
                                                    IPS+=ip;
                                                iph+=ip;
                                    }
                                    clock.restart().asMilliseconds();
                            }}
            ipT.setString(IPS);
            ipT.setOrigin(ipT.getGlobalBounds().width/2,ipT.getGlobalBounds().top/2);
            ipT.setPosition(Ex.widht/2,Ex.height/2);
            window.clear(sf::Color::Black);

                window.draw(Ex.fondP);
                window.draw(Ex.Bmute);
                window.draw(Ex.Bquit);
                window.draw(Ex.Breturn);
                window.draw(ipT);
                if(Vvip==true)
                    window.draw(Vip);
            window.display();

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    data[0]=1;
                        Ex.IPH=iph;
                        send << data[0]<< data[1]<< data[2]<< data[3];
                        if(socket.send(send,Ex.IPH,54000)==sf::Socket::Done)
                            Vvip=true;

                        }
             if(socket.receive(send,Ex.IPH,port)==sf::Socket::Done){
                send >> data[0]>> data[1]>> data[2]>> data[3];
                if(data[0]==1){
                    Vip.setString("ready to start");
                    Vip.setFillColor(sf::Color::Red);
                    Vip.setOrigin(Vip.getGlobalBounds().width/2,Vip.getGlobalBounds().top/2);
                    Vip.setPosition(Ex.widht/2,Ex.height*0.75);
                }
                if(data[0]==2){
                    multiRC();
                }}
             }
}

void multiRHS(){
       sf::Clock clock;
    clock.restart().asMilliseconds();
    sf::String IPS("IP:");
    sf::Text ipT;
    ipT.setCharacterSize(75);
    ipT.setFont(Ex.font);
    Ex.IPH=sf::IpAddress::getLocalAddress();

    bool ready=false;
    IPS+=Ex.IPH.toString();
    ipT.setString(IPS);
     sf::Event event;
     //reseaux

        sf::UdpSocket socket;
        unsigned short port;
        int data[4];
            sf::Packet send;
        socket.bind(54000);
        sf::IpAddress sender;
        socket.setBlocking(false);

        while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed||(Ex.Bquit.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                    window.close();
                }}
             if (clock.getElapsedTime().asMilliseconds() >= 150){
                if (Ex.Bmute.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    Ex.volume();
                        clock.restart().asMilliseconds();
                            }}

                if (Ex.Breturn.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return;

                        ipT.setOrigin(ipT.getGlobalBounds().width/2,ipT.getGlobalBounds().top/2);
            ipT.setPosition(Ex.widht/2,Ex.height/2);

            window.clear(sf::Color::Black);

                window.draw(Ex.fondP);
                window.draw(Ex.Bmute);
                window.draw(Ex.Bquit);
                window.draw(Ex.Breturn);
                window.draw(ipT);
                if(ready==true)
                    window.draw(start);

            window.display();

            if(socket.receive(send,sender,port)==sf::Socket::Done){
                    send >> data[0]>> data[1]>> data[2]>> data[3];
                    Ex.IPC=sender;
                    data[1]=2;
                    send <<data[0]<<data[1]<<data[2]<< data[3];

                    if(socket.send(send,Ex.IPC,54000)==sf::Socket::Done)
                            ready=true;
                 }
                if(ready==true){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        data[0]=2;
                        send << data[0];
                        if(socket.send(send,Ex.IPC,54000)==sf::Socket::Done){
                         highScore=fopen("asset/HighScore.HS","wb ");   multiRH();
                            ready=false;
                        }
                    }
                }
        }
}

void multiRC(){
    float data[10];
    sf::UdpSocket socket;
    socket.setBlocking(false);
     socket.bind(54250);
     unsigned short port;
     sf::IpAddress sender;
    std::size_t a;

    sf::Vector2f Dpalet(Ex.widht/30,Ex.height/5);
    sf::RectangleShape Bpalet;
    sf::RectangleShape Rpalet;

    Bpalet.setSize(Dpalet);
    Bpalet.setFillColor(sf::Color::Blue);
    Bpalet.setOrigin(0,Dpalet.y/2);
    Bpalet.setPosition(Ex.widht/50,Ex.height/2);

    Rpalet.setSize(Dpalet);
    Rpalet.setFillColor(sf::Color::Red);
    Rpalet.setOrigin(Dpalet.x,Dpalet.y/2);
    Rpalet.setPosition(Ex.widht-Ex.widht/50,Ex.height/2);

    Ex.ball.setFillColor(sf::Color(125,127,124,255));
        window.clear(sf::Color::Black);
        window.draw(Ex.fondP);
    sf::Event event;
        while (window.isOpen()){
                  while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }}

              socket.receive(data,100,a,sender,port);

                data[9]=Rpalet.getPosition().y/Ex.height;

                socket.send(data,100,Ex.IPH,54250);

                if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W)||sf::Keyboard::isKeyPressed(sf::Keyboard::Z))&& Rpalet.getPosition().y-Rpalet.getSize().y/2>0)
                    Rpalet.move(0,-10);

                if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S))&&( Rpalet.getPosition().y+Rpalet.getSize().y/2<Ex.height))
                    Rpalet.move(0,10);

                scoreB.setString(std::to_string(int(data[1])));
                scoreR.setString(std::to_string(int(data[2])));
                Bpalet.setPosition(Ex.widht/50,data[3]*Ex.height);
                Ex.ball.setPosition(data[4]*Ex.widht,data[5]*Ex.height);
                Ex.ball.setFillColor(sf::Color(int(data[6]),int(data[7]),int(data[8]),255));
                window.clear(sf::Color::Black);
                window.draw(Ex.fondP);
                window.draw(scoreB);
                window.draw(scoreR);
                window.draw(Bpalet);
                window.draw(Rpalet);
                window.draw(Ex.ball);
            window.display();

                if(Ex.ball.getGlobalBounds().intersects(Rpalet.getGlobalBounds())||Ex.ball.getGlobalBounds().intersects(Bpalet.getGlobalBounds()))
                    Ex.bouces.play();
            if( data[1] >=10){
                sf::Text Bwin;
                Bwin.setFont(Ex.font);
                Bwin.setCharacterSize(100);
                Bwin.setString("The player Blue win !!!\n press space to continue");
                Bwin.setOrigin(Bwin.getGlobalBounds().width/2,Bwin.getGlobalBounds().height/2);
                Bwin.setPosition(Ex.widht/2,Ex.height/2);
                Bwin.setFillColor(sf::Color::Blue);
                Ex.finish.play();
                do{
                    window.draw(Bwin);
                    window.display();
                }while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==false);
                return ;
            }
            if(data[2]>=10){
                sf::Text Rwin;
                Rwin.setFont(Ex.font);
                Rwin.setCharacterSize(100);
                Rwin.setString("The player Red win !!!\n press space to continue");
                Rwin.setOrigin(Rwin.getGlobalBounds().width/2,Rwin.getGlobalBounds().height/2);
                Rwin.setPosition(Ex.widht/2,Ex.height/2);
                Rwin.setFillColor(sf::Color::Red);
                Ex.finish.play();
                do{
                    window.draw(Rwin);
                    window.display();
                }while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==false);
                return ;

            }
                if (data[0]==1){
                    return;
            }
        }
}
void multiRH(){
        float data[10];
    sf::UdpSocket socket;

    socket.bind(54250);
    socket.setBlocking(false);
    std::size_t a;
     unsigned short port;
    sf::IpAddress sender;

    short PointB=0;
    short PointR=0;
    short Rvalue=0;
    short Gvalue=0;
    short Bvalue=0;
    std::string Bpoint="0";
    std::string Rpoint="0";
    sf::Vector2f Dpalet(Ex.widht/30,Ex.height/5);
    sf::RectangleShape Bpalet;
    sf::RectangleShape Rpalet;

    Bpalet.setSize(Dpalet);
    Bpalet.setFillColor(sf::Color::Blue);
    Bpalet.setOrigin(0,Dpalet.y/2);
    Bpalet.setPosition(Ex.widht/50,Ex.height/2);

    Rpalet.setSize(Dpalet);
    Rpalet.setFillColor(sf::Color::Red);
    Rpalet.setOrigin(Dpalet.x,Dpalet.y/2);
    Rpalet.setPosition(Ex.widht-Ex.widht/50,0);

    sf::Event event;

    scoreB.setString("0");
    scoreR.setString("0");

    Ex.ballSpeed=3;
    Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
        while (window.isOpen()){
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }}
                data[1]=PointB;
                data[2]=PointR;
                data[3]=Bpalet.getPosition().y/Ex.height;
                data[4]=Ex.ball.getPosition().x/Ex.widht;
                data[5]=Ex.ball.getPosition().y/Ex.height;
                data[6]=Rvalue;
                data[7]=Gvalue;
                data[8]=Bvalue;
            socket.send(data,100,Ex.IPC,54250);

            if(socket.receive(data,100,a,sender,port)==sf::Socket::Done){
                Rpalet.setPosition(Ex.widht-Ex.widht/50,data[9]*Ex.height);
            }

                if((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))&& Bpalet.getPosition().y-Bpalet.getSize().y/2>0)
                    Bpalet.move(0,-10);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& (Bpalet.getPosition().y+Bpalet.getSize().y/2<Ex.height)){
                    Bpalet.move(0,10);}

                    scoreB.setString(Bpoint);
                    scoreR.setString(Rpoint);
                    Ex.ballSpeed*=1.001;
            window.clear(sf::Color::Black);
                Ex.moveBall();
                window.draw(Ex.fondP);
                window.draw(scoreB);
                window.draw(scoreR);
                window.draw(Bpalet);
                window.draw(Rpalet);
                window.draw(Ex.ball);
            window.display();

            if(Ex.ball.getPosition().y-Ex.ball.getRadius()-Ex.ball.getOutlineThickness()<0||Ex.ball.getPosition().y+Ex.ball.getRadius()+Ex.ball.getOutlineThickness()>Ex.height)
                Ex.ballAngle= -Ex.ballAngle;

            if(Ex.ball.getGlobalBounds().intersects(Rpalet.getGlobalBounds())||Ex.ball.getGlobalBounds().intersects(Bpalet.getGlobalBounds())){
                Ex.ballAngle= pi - Ex.ballAngle + (std::rand() % 20) * pi / 180;
                Ex.ballSpeed+=3;
                Rvalue=rand()%255;
                Gvalue=rand()%255;
                Bvalue=rand()%255;
                Ex.ball.setFillColor(sf::Color(Rvalue,Gvalue,Bvalue,255));
                Ex.bouces.play();
            }
            if (Ex.ball.getPosition().x<0){
                Ex.ballSpeed=5;
                Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
                PointR++;
                Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
                Rpoint= std::to_string(PointR);
                Ex.ballAngle=rand()%360;
            }
            if (Ex.ball.getPosition().x>Ex.widht){
                Ex.ballSpeed=5;
                Ex.ball.setPosition(Ex.widht/2,Ex.height/2);
                PointB++;
                Bpoint= std::to_string(PointB);
                Ex.ballAngle=rand()%360;

            }
            if(PointB>=10){
                sf::Text Bwin;
                Bwin.setFont(Ex.font);
                Bwin.setCharacterSize(100);
                Bwin.setString("The player Blue win !!!\n press space to continue");
                Bwin.setOrigin(Bwin.getGlobalBounds().width/2,Bwin.getGlobalBounds().height/2);
                Bwin.setPosition(Ex.widht/2,Ex.height/2);
                Bwin.setFillColor(sf::Color::Blue);
                data[1]=PointB;
                socket.send(data,100,Ex.IPC,55000);
                Ex.finish.play();
                do{
                    window.draw(Bwin);
                    window.display();
                }while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==false);
                return;
            }
            if(PointR>=10){
                sf::Text Rwin;
                Rwin.setFont(Ex.font);
                Rwin.setCharacterSize(100);
                Rwin.setString("The player Red win !!!\n press space to continue");
                Rwin.setOrigin(Rwin.getGlobalBounds().width/2,Rwin.getGlobalBounds().height/2);
                Rwin.setPosition(Ex.widht/2,Ex.height/2);
                Rwin.setFillColor(sf::Color::Red);
                data[2]=PointR;
                socket.send(data,100,Ex.IPC,55000);
                Ex.finish.play();
                do{
                    window.draw(Rwin);
                    window.display();
                }while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==false);
                return;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                data[0]=1;
                socket.send(data,100,Ex.IPC,55000);
            }
            if(data[0]==1)
                return;
        }
}








