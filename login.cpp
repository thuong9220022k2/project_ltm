#include "login.h"
#include <string.h>
#include <json-c/json.h>
#include <iostream>
#include "type.h"
Login::Login(sf::RenderWindow &window, Socket *socket)
    : window(window), usernameField(20), passwordField(20)
{
    _username = "";
    _password = "";
    statusPage = "login";

    if (!backgroundTexture.loadFromFile("bg_login.png"))
    {
        std::cerr << "Failed to load background image." << std::endl;
    }
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Unable to download font" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundTexture.setSmooth(true);
    setupUI();
}

void Login::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
        window.display();
    }
}

void Login::setupUI()
{
    usernameField.setPosition(450, 255);
    passwordField.setPosition(450, 355);
    backgroundSprite.setPosition(0, 0);
    loginButton.setSize(sf::Vector2f(200, 40));
    loginButton.setOutlineThickness(2.0f);
    loginButton.setFillColor(sf::Color(49, 215, 21));
    loginButton.setOutlineColor(sf::Color(49, 215, 21));
    loginButton.setPosition(500, 470);
    text_username.setFont(font);
    text_password.setFont(font);
    text_login.setFont(font);
    text_Forgot_Password.setFont(font);
    text_Remember_me.setFont(font);
    text_register.setFont(font);
    text_username.setCharacterSize(20);
    text_password.setCharacterSize(20);
    text_login.setCharacterSize(30);
    text_Forgot_Password.setCharacterSize(16);
    text_Remember_me.setCharacterSize(16);
    text_register.setCharacterSize(18);
    text_username.setString("Username");
    text_password.setString("Password");
    text_login.setString("Log in");
    text_Forgot_Password.setString("Forgot Password?");
    text_Remember_me.setString("Remember me");
    text_register.setString("Don't have an account yet, please register");
    text_username.setPosition(450, 220);
    text_password.setPosition(450, 320);
    text_login.setPosition(555, 470);
    text_Forgot_Password.setPosition(600, 405);
    text_Remember_me.setPosition(450, 405);
    text_register.setPosition(440, 530);
    text_login.setStyle(sf::Text::Bold);
    text_login.setFillColor(sf::Color::Black);
    text_register.setFillColor(sf::Color(5, 255, 246));
}

void Login::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            // socket->disconnect();
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            auto pos = sf::Mouse::getPosition(window);
            usernameField.setFocus(usernameField.contains(sf::Vector2f(pos)));
            passwordField.setFocus(passwordField.contains(sf::Vector2f(pos)));
            sf::FloatRect loginButtonBounds = loginButton.getGlobalBounds();
            if (loginButtonBounds.contains(sf::Vector2f(pos)))
            {
                if (usernameField.getText() != "" && passwordField.getText() != "")
                {
                    _username = usernameField.getText();
                    _password = passwordField.getText();
                    if (checkLogin())
                    {
                        // while (!getFriendsList());
                        statusPage = "home";
                    }
                    else
                    {
                        std::cout << "Dang nhap that bai" << std::endl;
                    }
                }
                else
                {
                    std::cout << "hay nhap du dl!";
                }
            }
            sf::FloatRect text_registerBounds = text_register.getGlobalBounds();
            if (text_registerBounds.contains(sf::Vector2f(pos)))
            {
                statusPage = "register";
            }
        }
        else
        {
            usernameField.handleInput(event);
            passwordField.handleInput(event);
        }
    }
}

bool Login::checkLogin()
{
    struct json_object *jobj = json_object_new_object();
    struct json_object *jtype = json_object_new_int(LOGIN);
    struct json_object *jusername = json_object_new_string(_username.c_str());
    struct json_object *jpassword = json_object_new_string(_password.c_str());
    json_object_object_add(jobj, "type", jtype);
    json_object_object_add(jobj, "username", jusername);
    json_object_object_add(jobj, "password", jpassword);
    const char *json_string = json_object_to_json_string(jobj);
    socket->send(json_string);
    socket->receive();

    json_object_put(jobj);

    json_object *responseObj = socket->LoginResponse();
    if (responseObj != NULL)
    {
        json_object *jmessage;

        // Kiểm tra thông điệp trong phản hồi
        if (json_object_object_get_ex(responseObj, "message", &jmessage))
        {
            const char *message = json_object_get_string(jmessage);

            if (strcmp(message, "LOGIN SUCCESS") == 0)
            {
                json_object_put(responseObj);
                return true;
            }
            else
            {
                std::cerr << "Login failed: " << message << std::endl;
            }
        }
        json_object_put(responseObj);
    }
    return false;
}

void Login::update()
{
    // Cập nhật logic khi cần thiết
}

void Login::render()
{
    window.clear();
    window.draw(backgroundSprite);
    window.draw(usernameField);
    window.draw(passwordField);
    window.draw(loginButton);
    window.draw(text_username);
    window.draw(text_password);
    window.draw(text_login);
    window.draw(text_Forgot_Password);
    window.draw(text_Remember_me);
    window.draw(text_register);
}

std::string Login::getUsername()
{
    return _username;
}

std::string Login::getPassword()
{
    return _password;
}