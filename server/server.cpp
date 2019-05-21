#include "server.hpp"

    Server::Server(uint16_t port)
    {
        this->port = port;
    }

    void Server::attach(Observer* observer)
    {
        observers.push_back(observer);
    }

    void Server::notify_all()
    {
        for(std::vector<Observer*>::iterator i = observers.begin(); i != observers.end(); i++)
        {
            (*i)->update(recv_buff, buff_size);
        }
    }

    int Server::start()
    {
        init_openssl();
        if(!create_context())
        {
            perror("Error while creating context");
            ERR_print_errors_fp(stderr);
            exit(EXIT_FAILURE);
        }
        configure_context();
        if(!create_socket())
        {
            perror("Error while creating socket");
            exit(EXIT_FAILURE);
        }
        while(1)
        {
            // wait and accept incoming connections
            struct sockaddr_in addr;
            uint len = sizeof(addr);
            SSL *ssl;
            const char reply[] = "test\n";

            int client = accept(sock, (struct sockaddr*)&addr, &len);
            if (client < 0)
            {
                perror("Unable to accept");
                exit(EXIT_FAILURE);
            }

            ssl = SSL_new(context);
            SSL_set_fd(ssl, client);

            if (SSL_accept(ssl) <= 0)
            {
                ERR_print_errors_fp(stderr);
            }
            else
            {
                int NumRead;
                NumRead = SSL_read(ssl, recv_buff, 1024);
                if(NumRead < 0)
                {
                    perror("Error in read");
                    exit(EXIT_FAILURE);
                }
                buff_size = NumRead;
                printf("Read %d bytes: ", buff_size); //for debug purposes only
                for(int i = 0; i < buff_size; ++i)
                {
                    printf("%d ", (uint8_t)recv_buff[i]);
                }
                printf("\n");
                SSL_write(ssl, reply, strlen(reply));
            }

            notify_all();

            SSL_free(ssl);
            close(client);
        }
    }

    int Server::stop()
    {

    }

    bool Server::create_socket()
    {
        struct sockaddr_in addr;

        addr.sin_family = AF_INET;
        addr.sin_port = htons(this->port);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
        {
            perror("Unable to create socket");
            return false;
        }

        if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        {
            perror("Unable to bind");
            return false;
        }

        if (listen(sock, 1) < 0)
        {
            perror("Unable to listen");
            return false;
        }

        return true;
    }

    void Server::init_openssl()
    {
        SSL_load_error_strings();	
        OpenSSL_add_ssl_algorithms();
    }

    void Server::cleanup_openssl()
    {
        EVP_cleanup();
    }

    bool Server::create_context()
    {
        const SSL_METHOD *method;

        method = SSLv23_server_method();

        context = SSL_CTX_new(method);
        if (!context)
        {
            // error occured
            return false;
        }

        return true;
    }

    void Server::configure_context()
    {
        SSL_CTX_set_ecdh_auto(context, 1);

        // set the certificate file
        if (SSL_CTX_use_certificate_file(context, "crypto/server.crt", SSL_FILETYPE_PEM) <= 0)
        {
            ERR_print_errors_fp(stderr);
            exit(EXIT_FAILURE);
        }

        // set the key file
        if (SSL_CTX_use_PrivateKey_file(context, "crypto/private.pem", SSL_FILETYPE_PEM) <= 0 )
        {
            ERR_print_errors_fp(stderr);
            exit(EXIT_FAILURE);
        }
    }