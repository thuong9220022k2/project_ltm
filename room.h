#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class Room
{
public:
    Room(sf::RenderWindow &window);
    void drawRoom();
    void run();

private:
    sf::RenderWindow &window;
    sf::Font font;
    sf::RectangleShape bt1;
    sf::RectangleShape bt2;
    sf::RectangleShape bt3;

    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
};