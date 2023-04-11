#include "server.h"
#include "session.h"
#include <iostream>

void Server::Start()
{
    boost::shared_ptr<boost::asio::ip::tcp::socket> acc_socket(new boost::asio::ip::tcp::socket(io_));
    acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket)
    {
        if(!ec)
        {
            std::cout << "success accept" << socket.is_open() << std::endl;
            std::make_shared<Session>(std::move(socket))->Start();
        }
        else
        {
            std::cerr << "accept error" << std::endl;
        }
        Start();
    });
}

void Server::Run()
{
    io_.run();
}