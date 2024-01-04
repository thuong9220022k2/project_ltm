#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "login.h"
#include "menu.h"
#include "userlist.h"
#include "room_page.h"
#include "room.h"
#include "socket.h"
class Route
{
private:
    sf::RenderWindow &window;
    Socket *socket;
    Login login;
    // Menu menu;
    Home home;
    // Room room;
    // UserList userList;
    void getStatusPage(std::string str);

public:
    enum class CurrentScreen
    {
        LOGIN,
        REGISTER,
        HOME,
        ROOM,
        RANK,
        HISTORY,
        GAME
    };
    CurrentScreen currentScreen;
    Route(sf::RenderWindow &window, Socket *socket);
    void update();
    void run();
};