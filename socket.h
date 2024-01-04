#ifndef SOCKET_H
#define SOCKET_H

#pragma once

#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <json-c/json.h>
class Socket
{
public:
    Socket();
    // ~Socket();
    // Server functions
    bool bind(unsigned short port);
    bool listen();
    bool accept(Socket &client);
    // Client functions
    bool connect();
    bool Socket::send(std::const char message);
    void receive();
    void disconnect();
    void startSendThread();
    std::mutex ther_Mutex;
    json_object *LoginResponse();

private:
    sf::TcpSocket socket;
    sf::TcpListener listener;
    sf::IpAddress *serverAddress;
    unsigned short serverPort;
    std::thread receiveThread;
    std::thread sendThread;
    std::mutex loginMutex;
    std::mutex roomMutex;
    std::queue<json_object *> responseLoginQueue;
    std::mutex queueLoginMutex;
    // std::mutex friendsMutex;
    // std::mutex gameInvitationMutex;
};

#endif // SOCKET_H