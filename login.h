#pragma once
#include "text_field.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "socket.h"
class Login
{
private:
    Socket *socket;
    sf::RenderWindow &window;

    std::string _username;
    std::string _password;
    TextField usernameField;
    TextField passwordField;
    sf::RectangleShape loginButton;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text text_username;
    sf::Text text_password;
    sf::Text text_login;
    sf::Text text_Forgot_Password;
    sf::Text text_Remember_me;
    sf::Text text_register;
    bool checkLogin();

public:
    std::string getUsername();
    std::string getPassword();
    std::string statusPage;
    Login(sf::RenderWindow &window, Socket *socket);
    void setupUI();
    void handleEvents();
    void update();
    void render();
    void run();
};