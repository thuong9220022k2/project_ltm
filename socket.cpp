#include "socket.h"
#include <cstring>
#include <json-c/json.h>
#include "type.h"
Socket::Socket()
    : serverAddress(new sf::IpAddress("127.0.0.1")), serverPort(12345)
{
}

// Socket::~Socket()
// {
// 	disconnect();
// }

// Server functions
bool Socket::bind(unsigned short port)
{
    if (listener.listen(port) != sf::Socket::Done)
    {
        std::cerr << "Error binding to port " << port << std::endl;
        return false;
    }

    std::cout << "Server listening on port " << port << "..." << std::endl;
    return true;
}

bool Socket::listen()
{
    if (listener.accept(socket) != sf::Socket::Done)
    {
        std::cerr << "Error accepting connection" << std::endl;
        return false;
    }

    std::cout << "Client connected: " << socket.getRemoteAddress() << std::endl;
    return true;
}

bool Socket::accept(Socket &client)
{
    if (listener.accept(client.socket) != sf::Socket::Done)
    {
        std::cerr << "Error accepting connection" << std::endl;
        return false;
    }

    std::cout << "Client connected: " << client.socket.getRemoteAddress() << std::endl;
    return true;
}

bool Socket::connect()
{
    if (socket.connect(*serverAddress, serverPort) != sf::Socket::Done)
    {
        std::cerr << "Error connecting to server" << std::endl;
        return false;
    }
    std::cout << "Connected to server: " << serverAddress << ":" << serverPort << std::endl;
    receiveThread = std::thread(&Socket::receive, this);
    receiveThread.detach();
    return true;
}

bool Socket::send(std::string message)
{
    std::size_t sent;
    if (socket.send(&message, sizeof(message), sent) != sf::Socket::Done)
    {
        std::cerr << "Error sending data to server\n";
        return false;
    }
    else
    {
        std::cout << "Sending data successfully\n";
    }
    return true;
}

void Socket::receive()
{
    std::size_t received;
    std::string response;

    while (true)
    {
        if (socket.receive(&response, sizeof(response), received) != sf::Socket::Done)
        {
            std::cerr << "Error receiving data from server" << std::endl;
        }
        else
        {
            struct json_object *parsed_json = json_tokener_parse(response.c_str());
            struct json_object *jtype;
            json_object_object_get_ex(parsed_json, "type", &jtype);
            int type = json_object_get_int(jtype);
            std::cout << "Received data successfully\n";
            switch (type)
            {
            case LOGIN:
            {

                break;
            }

            default:
                break;
            }
        }
    }
}

void Socket::disconnect()
{
    socket.disconnect();
    listener.close();
    if (receiveThread.joinable())
    {
        receiveThread.join();
    }
    if (sendThread.joinable())
    {
        sendThread.join();
    }
}