#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "login.h"
#include "menu.h"
#include "userlist.h"
#include "home.h"
#include "room.h"
#include "socket.h"
#include "route.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 670), "CHESS", sf::Style::Titlebar | sf::Style::Close);
    // Login loginScreen(window);
    // loginScreen.run();
    // Menu menu(window);
    // menu.run();
    // Home home(window, {"user1", "user2", "user3"});
    // home.run();
    // Room room(window);
    // room.run();

    window.setPosition(sf::Vector2i(80, 10));
    Socket clientSocket;
    Route route(window, &clientSocket);
    std::thread ther_socket;
    ther_socket = std::thread(&Socket::connect, &clientSocket);
    ther_socket.detach();
    route.run();
    clientSocket.disconnect();
    return 0;
}
