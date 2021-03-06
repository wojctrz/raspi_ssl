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

////////////////////////////////////////////////////////////////////////////////
///
/// class Server
/// This class handles ssl connections
///
/// *subject* part of the Observer design pattern
///
///////////////////////////////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// vector<Observer*>
    /// list of Observers subscribed to this Subject
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::vector<Observer*> observers;

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// void notify_all
    /// notify all subscribed Observers
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void notify_all();

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// bool create_socket()
    /// create the SSL socket
    /// @return true if no error, false when error occured
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bool create_socket();

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// void init_opennssl()
    /// Initialize OpenSSL
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void init_openssl();

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// void cleanup_openssl
    /// cleanup OpenSSL
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void cleanup_openssl();

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// bool create_context
    /// create SSL context
    ///
    /// @return true if no error, false when error occured
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bool create_context();

    ////////////////////////////////////////////////////////////////////////////////
    ///
    /// bool configure_context
    /// configure SSL context
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void configure_context();

};

#endif   // SERVER_HPP