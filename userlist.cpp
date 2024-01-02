#include "userlist.h"

UserList::UserList(sf::RenderWindow &window, const std::vector<std::string> &users)
    : window(window), font(font)
{
    font.loadFromFile("arial.ttf");
    float startY = 100; // Vị trí bắt đầu của bảng trên cửa sổ
    // rows.reserve(users.size());
    // userTexts.reserve(users.size());
    // challengeText.reserve(users.size());

    for (size_t i = 0; i < users.size(); ++i)
    {
        sf::RectangleShape row(sf::Vector2f(300, 60));
        row.setFillColor(sf::Color::White);
        row.setOutlineColor(sf::Color::Black);
        row.setOutlineThickness(1.0f);
        row.setPosition(250, startY + i * 60);
        rows.push_back(row);

        sf::Text userText(users[i], font, 20);
        userText.setPosition(260, startY + i * 60 + 20);
        userText.setFillColor(sf::Color::Black);
        userTexts.push_back(userText);

        sf::Text challenge("Challenge", font, 20);
        challenge.setPosition(400, startY + i * 60 + 20);
        challenge.setFillColor(sf::Color::Black);
        challengeText.push_back(challenge);
    }
}

void UserList::draw()
{
    for (size_t i = 0; i < rows.size(); ++i)
    {
        window.draw(rows[i]);
        window.draw(userTexts[i]);
        window.draw(challengeText[i]);
    }
}
