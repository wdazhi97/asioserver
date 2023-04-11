#include "../../net/server.h"
#include <iostream>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Usage echo <port>" << std::endl;
        return 1;
    }
    try
    {
        boost::asio::io_service io;
        Server server(io, std::atoi(argv[1]));
        server.Run();
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}