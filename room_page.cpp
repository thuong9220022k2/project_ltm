#include "home.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "socket.h"
Home::Home(sf::RenderWindow &window, Socket *socket)
    : window(window), Menu(window), Room(window), socket(socket)
{
    font.loadFromFile("arial.ttf");
};

void Home::renderHome()
{
    renderMenu();
    drawRoom();
}

void Home::run()
{
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
            handleEventsMenu(e);
            handleEventRoom(e);
        }
        window.clear(sf::Color::White);
        updateMenu();
        updateUI();
        renderHome();
        window.display();
    }
}