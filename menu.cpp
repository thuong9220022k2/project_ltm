#include "menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow &window) : window(window)
{
    statusPage = "play";
    setupUIMenu();
}

// Menu::~Menu() {
// }

void Menu::setupUIMenu()
{
    font.loadFromFile("arial.ttf");

    t_user.loadFromFile("profile.png");
    s_user.setTexture(t_user);

    user.setSize(sf::Vector2f(300, 120));
    user.setPosition(0, 0);
    user.setFillColor(sf::Color(224, 164, 102));

    room.setSize(sf::Vector2f(300, 120));
    room.setFillColor(sf::Color(224, 164, 102));
    room.setPosition(300, 0);

    rank.setSize(sf::Vector2f(300, 120));
    rank.setFillColor(sf::Color(224, 164, 102));
    rank.setPosition(600, 0);

    history.setSize(sf::Vector2f(300, 120));
    history.setFillColor(sf::Color(224, 164, 102));
    history.setPosition(900, 0);

    s_user.setPosition(150, 40);

    s_room.setFont(font);
    s_rank.setFont(font);
    s_history.setFont(font);

    s_room.setString("Room");
    s_rank.setString("Rank");
    s_history.setString("History");

    s_room.setFillColor(sf::Color::Black);
    s_rank.setFillColor(sf::Color::Black);
    s_history.setFillColor(sf::Color::Black);

    s_room.setCharacterSize(30);
    s_rank.setCharacterSize(30);
    s_history.setCharacterSize(30);

    s_room.setPosition(420, 40);
    s_rank.setPosition(720, 40);
    s_history.setPosition(1020, 40);

    s_user.setScale(0.1f, 0.1f);
}

void Menu::handleEventsMenu(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (room.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                statusPage = "home";
            }
            if (rank.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                statusPage = "rank";
            }
            if (history.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
            {
                statusPage = "history";
            }
        }
    }
}

void Menu::updateMenu()
{
    if (statusPage == "home")
    {
        room.setFillColor(sf::Color(228, 131, 31));
        rank.setFillColor(sf::Color(224, 164, 102));
        history.setFillColor(sf::Color(224, 164, 102));
    }
    else if (statusPage == "history")
    {
        history.setFillColor(sf::Color(228, 131, 31));
        room.setFillColor(sf::Color(224, 164, 102));
        rank.setFillColor(sf::Color(224, 164, 102));
    }
    else
    {
        rank.setFillColor(sf::Color(228, 131, 31));
        room.setFillColor(sf::Color(224, 164, 102));
        history.setFillColor(sf::Color(224, 164, 102));
    }
}

void Menu::renderMenu()
{
    window.draw(user);
    window.draw(s_user);

    window.draw(room);
    window.draw(s_room);

    window.draw(rank);
    window.draw(s_rank);

    window.draw(history);
    window.draw(s_history);
}

void Menu::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            handleEventsMenu(event);
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        updateMenu();
        window.clear();
        renderMenu();
        window.display();
    }
}