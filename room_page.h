#pragma once
#include "userlist.h"
#include "menu.h"
#include "room.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "socket.h"
class Home : public Room, public Menu
{
public:
    std::string statusPage;
    Home(sf::RenderWindow &window, Socket *socket);
    void renderHome();
    void run();

private:
    sf::RenderWindow &window;
    sf::Font font;
    Socket *socket;
};