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

void Room::handleEventRoom(sf::Event &event)
{
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    // Process the event for mouse button press
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (bt1.getGlobalBounds().contains(mousePos))
        {
            isBt1Toggled = !isBt1Toggled; // Toggle the state of the button
            selectedMode = isBt1Toggled ? "Multiplayer" : "";
        }
        else if (bt2.getGlobalBounds().contains(mousePos))
        {
            isBt2Toggled = !isBt2Toggled; // Toggle the state of the button
            selectedMode = isBt2Toggled ? "Singleplayer" : "";
        }
        else if (bt3.getGlobalBounds().contains(mousePos) && selectedMode == "Multiplayer")
        {
            // Send request to create room
            createRoom(selectedMode);
        }
    }
}

void Room::updateUI()
{
    // Update button colors based on toggle state
    bt1.setFillColor(isBt1Toggled ? sf::Color(128, 128, 128) : sf::Color::White);
    bt2.setFillColor(isBt2Toggled ? sf::Color(128, 128, 128) : sf::Color::White);
}

void Room::createRoom(const std::string &mode)
{
    // Code to send request to server using socket and 'send' function
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
            handleEventRoom(e);
        }

        window.clear(sf::Color::White);
        drawRoom();
        updateUI();
        window.display();
    }
}
