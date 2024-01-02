#ifndef SOCKET_H
#define SOCKET_H

#pragma once

#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>

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
    bool send(std::string message);
    void receive();
    void disconnect();
    void startSendThread();
    std::mutex ther_Mutex;
    // std::condition_variable dataReady;
    // std::queue<DataStruct::Response> queueLogin;
    // std::queue<DataStruct::Response> queueRoom;
    // std::queue<DataStruct::Response> queueFriends;
    // std::queue<DataStruct::Response> queueGameInvitation;
    // DataStruct::Response popLoginData();
    // DataStruct::Response popRoomData();
    // DataStruct::Response popFriendsData();
    // DataStruct::Response popGameInvitationData();

private:
    sf::TcpSocket socket;
    sf::TcpListener listener;
    sf::IpAddress *serverAddress;
    unsigned short serverPort;
    std::thread receiveThread;
    std::thread sendThread;
    std::mutex loginMutex;
    std::mutex roomMutex;
    // std::mutex friendsMutex;
    // std::mutex gameInvitationMutex;
};

#endif // SOCKET_H