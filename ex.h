class Ex{
public:
    Ex();
    sf::CircleShape ball;
    sf::Clock clock;

    float factor;
    float ballSpeed=3;
    float deltaTime;
    int ballAngle=180;
    void moveBall();
    void volume();
    void pos();
    int height;
    int widht;
    int retour;
    int port;
    sf::IpAddress IPH;
    sf::IpAddress IPC;
    std::string tex;

    sf::Font font;

    sf::Sprite fondP;
    sf::Texture TfondP;

    sf::Sprite fondS;
    sf::Texture TfondS;

    sf::Sprite Bmute;
    sf::Texture TBmute;

    sf::Sprite Bquit;
    sf::Texture TBquit;

    sf::Sprite Bsolo;
    sf::Texture TBsolo;

    sf::Sprite Bmultil;
    sf::Texture TBmultil;

    sf::Sprite Bmultir;
    sf::Texture TBmultir;

    sf::Sprite Breturn;
    sf::Texture TBreturn;

    sf::Sprite Bjoin;
    sf::Texture TBjoin;

    sf::Sprite Bcreate;
    sf::Texture TBcreate;

    sf::SoundBuffer SBbounces;
    sf::SoundBuffer SBfinish;

    sf::Sound bouces;
    sf::Sound finish;

    sf::Music music;
    sf::Image icon;

private:
    short sons=100;
};
