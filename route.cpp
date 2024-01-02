#include "route.h"

Route::Route(sf::RenderWindow &window, Socket *socket)
    : window(window), socket(socket), login(window, socket), currentScreen(CurrentScreen::LOGIN)
{
}

void Route::getStatusPage(std::string str)
{
    if (str == "login")
    {
        currentScreen = CurrentScreen::LOGIN;
    }
    else if (str == "register")
    {
        currentScreen = CurrentScreen::REGISTER;
    }
    else if (str == "home")
    {
        currentScreen = CurrentScreen::HOME;
    }
    else if (str == "room")
    {
        currentScreen = CurrentScreen::ROOM;
    }
    else if (str == "rank")
    {
        currentScreen = CurrentScreen::RANK;
    }
    else if (str == "history")
    {
        currentScreen = CurrentScreen::HISTORY;
    }
    else if (str == "game")
    {
        currentScreen = CurrentScreen::GAME;
    }
}

void Route::update()
{
    switch (currentScreen)
    {
    case Route::CurrentScreen::LOGIN:
        login.statusPage = "login";
        login.handleEvents();
        getStatusPage(login.statusPage);
        window.clear();
        login.setupUI();
        login.update();
        login.render();
        break;
    case CurrentScreen::REGISTER:
        break;
    case CurrentScreen::HOME:
        break;
    case CurrentScreen::ROOM:
        break;
    case CurrentScreen::RANK:
        break;
    case CurrentScreen::HISTORY:
        break;
    case CurrentScreen::GAME:
        break;
    default:
        break;
    }
}

void Route::run()
{
    while (window.isOpen())
    {
        update();
        window.display();
    }
}