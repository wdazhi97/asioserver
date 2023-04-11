#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <array>

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session(boost::asio::ip::tcp::socket socket) : socket_(std::move(socket))
    {
        data_.resize(1024);
    };

    void Start();

private:

    void Read();

    void Write(std::size_t length);

    std::string data_;

    boost::asio::ip::tcp::socket socket_;
};