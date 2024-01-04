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
    void createRoom(const std::string &mode);
    void handleEventRoom(sf::Event &event);
    void updateUI();

private:
    sf::RenderWindow &window;
    sf::Font font;
    sf::RectangleShape bt1;
    sf::RectangleShape bt2;
    sf::RectangleShape bt3;

    bool isBt1Toggled = false;
    bool isBt2Toggled = false;
    std::string selectedMode;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
};