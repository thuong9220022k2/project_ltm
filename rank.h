#pragma once
#include "userlist.h"
#include "menu.h"
#include "room.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "socket.h"
class Rank
{
public:
    std::string statusPage;
    Rank(sf::RenderWindow &window, Socket *socket);
    void renderRank();
    void run();

private:
    sf::RenderWindow &window;
    sf::Font font;
    Socket *socket;
};