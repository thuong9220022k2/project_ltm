#include "rank.h"

// Constructor
Rank::Rank(sf::RenderWindow &window, Socket *socket)
    : window(window), socket(socket)
{
    // Load font
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error loading arial.ttf" << std::endl;
    }

    // Initialize other members if necessary
    statusPage = "Rank Page";
}

// Render the rank information
void Rank::renderRank()
{
    // Example of rendering the status page title
    sf::Text title;
    title.setString("OKER RANK");
    title.setCharacterSize(24);
    title.setFillColor(sf::Color::Black);
    title.setPosition(100, 50); // Example position
    window.draw(title);

    // TODO: Add more rendering code here for rank details

    window.display();
}

// Run method for handling events and updating the UI
void Rank::run()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        // TODO: Add event handling specific to Rank
    }

    // Render rank information
    renderRank();
}
