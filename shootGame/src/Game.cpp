#include "Game.h"
#include "TextureHolder.h"

Game::Game(): window(sf::VideoMode(800, 600), "SFML window")
,mIsMovingUp(false)
,mIsMovingDown(false)
,mIsMovingLeft(false)
,mIsMovingRight(false)
,mPlayer()
,mTexture()

{
    if (!mTexture.loadFromFile("/home/sh44fi/repos/SFML/Media/Textures/Eagle.png"))
        {

            // Handle loading error
        }

        mPlayer.setTexture(mTexture);
        mPlayer.setPosition(100.f,100.f);




}

 void Game::run(){

 sf::Clock clock;
while (window.isOpen())

{
sf::Time deltaTime = clock.restart();
   processEvents();
   update(deltaTime);
   render();
}


}

void Game::processEvents(){
sf::Event event;
   while (window.pollEvent(event))
   {

    switch(event.type)
    {

    case sf::Event::KeyPressed :
    handlePlayerInput(event.key.code,true);
    break;


    case sf::Event::KeyReleased :
    handlePlayerInput(event.key.code,false);
    break;

    case sf::Event::Closed:
    window.close();
    break;
    }

    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){

if(key == sf::Keyboard::W)
    mIsMovingUp = isPressed;

else if(key == sf::Keyboard::S)
    mIsMovingDown = isPressed;

else if(key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;

else if(key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime){

sf::Vector2f movement(0.f, 0.f);
if (mIsMovingUp)
movement.y -= 100.f;
if (mIsMovingDown)
movement.y += 100.f;
if (mIsMovingLeft)
movement.x -= 100.f;
if (mIsMovingRight)
movement.x += 100.f;

mPlayer.move(movement * deltaTime.asSeconds());

}


void Game::render(){
   // Activate the window for OpenGL rendering
   window.clear();
   // OpenGL drawing commands go here...
   window.draw(mPlayer);

   // End the current frame and display its contents on screen
   window.display();
}



