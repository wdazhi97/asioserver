#include <iostream>
#include <boost/asio.hpp>
#include "net/server.h"

int main()
{
    boost::asio::io_service io;
    Server server(io, 1234);
    //server.Run();
    boost::asio::steady_timer t(io,boost::asio::chrono::seconds(5));
    t.wait();
    std::cout << "boost" << std::endl;
    return 0;
}