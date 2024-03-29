#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(sf::RenderWindow &window);
    // ~Menu();

    std::string statusPage;

    void setupUIMenu();
    void handleEventsMenu(sf::Event event);
    void updateMenu();
    void renderMenu();
    void run();

private:
    sf::RenderWindow &window;
    sf::RectangleShape user;
    sf::Texture t_user;
    sf::Sprite s_user;
    sf::Font font;

    sf::RectangleShape room;
    sf::RectangleShape rank;
    sf::RectangleShape history;

    sf::Text s_room;
    sf::Text s_rank;
    sf::Text s_history;
};