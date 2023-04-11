#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>

using boost::asio::io_service;
using boost::asio::ip::tcp;

class Server : public boost::noncopyable
{
public:
    Server(io_service & io, short port):io_(io), acceptor_(io, tcp::endpoint(tcp::v4(), port))
    {
        Start();
    };

    void Run();

private:      

    void Start();
    io_service &io_;
    tcp::acceptor acceptor_;
};