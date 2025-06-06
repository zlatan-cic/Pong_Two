#include "Bat.h"
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

    // Create a bat at the bottom center of the screne
    Bat bat(1920 / 2, 1080 - 20);

    // Crerate text object called HUD
    sf::Text hud;
    sf::Font font;
    font.loadFromFile("fonts/Gameplay.ttf");

    // Set font style to our game
    hud.setFont(font);

    // Make it nice and big
    hud.setCharacterSize(50);

    // Create a color
    hud.setFillColor(sf::Color::White);
    hud.setPosition(20, 20);

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

        // Update the HUD text
        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        hud.setString(ss.str());

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }
};
