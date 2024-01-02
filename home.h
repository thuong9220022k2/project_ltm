#pragma once
#include "userlist.h"
#include "menu.h"
#include "room.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
class Home : public Room, public Menu
{
public:
    Home(sf::RenderWindow &window, const std::vector<std::string> &users);
    void drawHome();
    void run();

private:
    sf::RenderWindow &window;
    sf::Font font;
};