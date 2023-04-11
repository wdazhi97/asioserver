#include "session.h"
#include <iostream>

void Session::Start()
{
    Read();
}

void Session::Read()
{
    auto self = shared_from_this();
    socket_.async_read_some(boost::asio::buffer(data_), [this, self](boost::system::error_code ec, std::size_t length)
    {
        if(!ec)
        {
            //std::cout << "read " <<  length << std::endl;
            Write(length);
        }
        else
        {
            std::cerr << "read error " << ec << std::endl;
        }
    });
}

void Session::Write(std::size_t length)
{
    auto self = shared_from_this();
    socket_.async_write_some(boost::asio::buffer(data_), [this, self](boost::system::error_code ec, std::size_t length)
    {
        if(!ec)
        {
            //std::cout << "write " << length << std::endl;
            Read();
        }
        else
        {
            std::cerr << "write error " << ec << std::endl;
        }
    });
}