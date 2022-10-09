#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


class Game
{
    public:
        Game();
        void run();

    private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


    private:
    sf::RenderWindow window;
    sf::Texture mTexture;
    sf::Sprite mPlayer;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
};


#endif // GAME_H
