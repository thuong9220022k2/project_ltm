#include "room.h"

Room::Room(sf::RenderWindow &window)
    : window(window)
{
    font.loadFromFile("arial.ttf");

    bt1.setSize(sf::Vector2f(200, 50));
    bt1.setFillColor(sf::Color::White);
    bt1.setOutlineColor(sf::Color::Black);
    bt1.setOutlineThickness(1.0f);
    bt1.setPosition(550, 150);

    bt2.setSize(sf::Vector2f(200, 50));
    bt2.setFillColor(sf::Color::White);
    bt2.setOutlineColor(sf::Color::Black);
    bt2.setOutlineThickness(1.0f);
    bt2.setPosition(850, 150);

    bt3.setSize(sf::Vector2f(200, 50));
    bt3.setFillColor(sf::Color::White);
    bt3.setOutlineColor(sf::Color::Black);
    bt3.setOutlineThickness(1.0f);
    bt3.setPosition(710, 250);

    text1.setString("Multiplayer");
    text1.setFont(font);
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(610, 160);

    text2.setString("Singleplayer");
    text2.setFont(font);
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(910, 160);

    text3.setString("Create Room");
    text3.setFont(font);
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::Black);
    text3.setPosition(750, 260);
}

void Room::drawRoom()
{
    window.draw(bt1);
    window.draw(bt2);
    window.draw(bt3);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
}

void Room::run()
{
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        drawRoom();
        window.display();
    }
}
