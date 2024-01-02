#include "home.h"

Home::Home(sf::RenderWindow &window, const std::vector<std::string> &users)
    : window(window), Menu(window), Room(window)
{
    font.loadFromFile("arial.ttf");
};

void Home::drawHome()
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
        }
        window.clear(sf::Color::White);
        updateMenu();
        drawHome();
        window.display();
    }
}