// userlist.hpp
#pragma once
#ifndef USERLIST_H
#define USERLIST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class UserList
{
public:
    UserList(sf::RenderWindow &window, const std::vector<std::string> &users);
    void draw();

private:
    sf::RenderWindow &window;
    sf::Font font;
    std::vector<sf::RectangleShape> rows;
    std::vector<sf::Text> userTexts;
    std::vector<sf::Text> challengeText;
};

#endif // USERLIST_HPP
