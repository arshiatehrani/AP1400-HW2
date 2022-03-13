#include "client.h"
Client::Client(std::string _id, const Server& _server)
    : id { _id }
    , server { &_server }
{
    std::cout << "Client constructor" << std::endl;
    std::string _public_key {}, _private_key {};
    crypto::generate_key(_public_key, _private_key);
    public_key = _public_key;
    private_key = _private_key;
}
const std::string Client::get_id() const
{
    std::cout << "get_id client" << std::endl;
    return id;
}
const std::string Client::get_publickey() const
{
    std::cout << "get_publickey client" << std::endl;
    return public_key;
}
const double Client::get_wallet() const
{
    std::cout << "get_waller client" << std::endl;
    return server->get_wallet(id);
}
std::string Client::sign(const std::string& txt) const
{
    std::string signature = crypto::signMessage(private_key, txt);
    return signature;
}
size_t Client::generate_nonce()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, static_cast<double>(SIZE_MAX));
    return static_cast<size_t>(dist(mt));
}
