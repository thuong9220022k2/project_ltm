#include "text_field.h"

TextField::TextField(unsigned int maxChars) : m_size(maxChars),
                                              m_rect(sf::Vector2f(15.0f * m_size, 35.0f)),
                                              m_hasfocus(false)
{
    m_font.loadFromFile("arial.ttf");
    m_rect.setOutlineThickness(2.0f);
    m_rect.setFillColor(sf::Color::White);
    m_rect.setOutlineColor(sf::Color(127, 127, 127));
    m_rect.setPosition(this->getPosition());
}

const std::string TextField::getText() const
{
    return m_text;
}

void TextField::setPosition(float x, float y)
{
    sf::Transformable::setPosition(x, y);
    m_rect.setPosition(x, y);
}

bool TextField::contains(sf::Vector2f point) const
{
    return m_rect.getGlobalBounds().contains(point);
}

void TextField::setFocus(bool focus)
{
    m_hasfocus = focus;
    m_rect.setOutlineColor(focus ? sf::Color::Blue : sf::Color(127, 127, 127));
}

void TextField::handleInput(sf::Event e)
{
    if (!m_hasfocus || e.type != sf::Event::TextEntered)
    {
        return;
    }

    if (e.text.unicode == 8 && !m_text.empty())
    { // Backspace key
        m_text.pop_back();
    }
    else if (m_text.size() < m_size && e.text.unicode >= 32 && e.text.unicode < 127)
    {
        m_text += static_cast<char>(e.text.unicode);
    }
}