#ifndef SERVER_HPP
#define SERVER_HPP

#include <stdio.h>
#include <unistd.h>
#include <cstdint>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <vector>
#include "observer.hpp"


class Server
{
public:
    Server(uint16_t port);
    int start();
    int stop();
    void attach(Observer* observer);
private:

    uint8_t recv_buff[1024];

    int buff_size;

    uint16_t port;

    int sock;

    SSL_CTX* context;

    std::vector<Observer*> observers;

    void notify_all();

    int create_socket();

    void init_openssl();

    void cleanup_openssl();

    SSL_CTX *create_context();

    void configure_context();

};

#endif   // SERVER_HPP