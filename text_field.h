#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#pragma once

#include <SFML/Graphics.hpp>

class TextField : public sf::Transformable, public sf::Drawable
{
private:
    unsigned int m_size;
    sf::Font m_font;
    std::string m_text;
    sf::RectangleShape m_rect;
    bool m_hasfocus;

public:
    TextField(unsigned int maxChars);

    const std::string getText() const;

    void setPosition(float x, float y);

    bool contains(sf::Vector2f point) const;

    void setFocus(bool focus);

    void handleInput(sf::Event e);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(m_rect, states);
        sf::Text text(m_text, m_font);
        text.setPosition(m_rect.getPosition() + sf::Vector2f(6.0f, 3.5f)); // Offset for text
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(18);
        target.draw(text, states);
    }
};

#endif // TEXTFIELD_H