#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Pong Two", sf::Style::Fullscreen);

    int score = 0;
    int lives = 3;

    int score_2 = 0;
    int lives_2 = 3;

    // Ovo brat CHATgpt pomogo
    sf::Clock scoreCooldown;
    //

    bool hasScored = false;

    // Create a bat at the bottom center of the screne
    Bat bat(1920 / 2, 1080 - 20);
    Bat bat2(1920 / 2, 20);

    bat2.getShape().setFillColor(Color::Green);

    // Create a ball
    Ball ball(1920 / 2, 0);

    // Crerate text object called HUD
    sf::Text hud;
    sf::Font font;
    sf::Text hudP2;//

    font.loadFromFile("fonts/Gameplay.ttf");

    // Set font style to our game
    hud.setFont(font);
    hudP2.setFont(font);//

    // Make it nice and big
    hud.setCharacterSize(30);
    hudP2.setCharacterSize(30); //

    // Create a color
    hud.setFillColor(sf::Color::White);
    hudP2.setFillColor(sf::Color::Green); //
    
    hud.setPosition(20, 20);
    hudP2.setPosition(
        static_cast<float>(window.getSize().x) - hudP2.getLocalBounds().width - 20.0f,
        20.0f
    );


    // Here is our clock for timing everything
    sf::Clock clock;

    Event event;

    // Game loop // // // // //
    while (window.isOpen())
    {
        /*Handle the player input*/
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Quit the game when the window is closed
                window.close();
        }
        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        // Handle the pressing and releasing of the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            bat.moveUp();
        }
        else
        {
            bat.stopUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            bat.moveDown();
        }
        else
        {
            bat.stopDown();
        }
        // player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            bat2.moveLeft();
        }
        else
        {
            bat2.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            bat2.moveRight();
        }
        else
        {
            bat2.stopRight();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            bat2.moveUp();
        }
        else
        {
            bat2.stopUp();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            bat2.moveDown();
        }
        else
        {
            bat2.stopDown();
        }

        // Checing the bat is hiting sides left or righr
        if (bat.getPosition().left < 0 && bat.isMovingLeft())
        {
            std::cout << "Hit the left coner... \n";
            bat.stopLeft();
        }

        if (bat.getPosition().left + bat.getPosition().width > window.getSize().x && bat.isMovingRight())
        {
            std::cout << "Hit the Right coner... \n";
            bat.stopRight();
        }

        // Checing the bat is hiting sides top or and bottom
        if (bat.getPosition().top < 0 && bat.isMovingUp())
        {
            std::cout << "Hit the Uper coner... \n";
            bat.stopUp();
        }

        if (bat.getPosition().top + bat.getPosition().height > window.getSize().y && bat.isMovingDown())
        {
            std::cout << "Hit the Bottom coner... \n";
            bat.stopDown();
        }

        /*
        Update the bat, the ball and the HUD
        *****************************
        *****************************
        *****************************
        */


        /*
        Draw the bat, the ball and the HUD
        */

        // Update the delta time
        Time dt = clock.restart();
        bat.update(dt);
        bat2.update(dt);
        ball.update(dt);

        // HUD Update
        std::stringstream ss, ssP2;
        ss << "Player_1 " << "Score: " << score << " Lives: " << lives;
        ssP2 << "Player_2 " << "Score: " << score_2 << " Lives: " << lives_2;
        hud.setString(ss.str());
        hudP2.setString(ssP2.str());
        hudP2.setOrigin(hudP2.getLocalBounds().width, 0);
        hudP2.setPosition(window.getSize().x - 20, 20);

        // Gornji udarac (Player 1 poen)
        if (ball.getPosition().top + ball.getPosition().height > window.getSize().y)
        {
            if (!hasScored)
            {
                score_2++;
                lives--;
                hasScored = true;
                scoreCooldown.restart();
                ball.reset(1920 / 2, 1080 / 2, 0.7f, -0.7f); // ide ka Player 1 opet

                if (lives < 1)
                {
                    lives = 3;
                    score = 0;
                }
            }
        }

        // Gornji udarac (Player 2 propustio — Player 1 dobija poen)
        if (ball.getPosition().top < 0)
        {
            if (!hasScored)
            {
                score++;
                lives_2--;
                hasScored = true;
                scoreCooldown.restart();
                ball.reset(1920 / 2, 1080 / 2, 0.7f, 0.7f); // ide ka Player 2 opet

                if (lives_2 < 1)
                {
                    lives_2 = 3;
                    score_2 = 0;
                }
            }
        }

        // Resetuj hasScored nakon 1 sekunde
        if (hasScored && scoreCooldown.getElapsedTime().asSeconds() > 1.0f)
        {
            hasScored = false;
        }

        // Side rebound
        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x)
        {
            ball.reboundSides();
        }

        // Paddle hit
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
            hasScored = false; // može da se udari opet bez greške
        }

        if (ball.getPosition().intersects(bat2.getPosition()))
        {
            ball.reboundBatOrTop();
            hasScored = false;
        }

        // Render
        window.clear();
        window.draw(hud);
        window.draw(hudP2);
        window.draw(bat.getShape());
        window.draw(bat2.getShape());
        window.draw(ball.getShape());
        window.display();
    }
};
