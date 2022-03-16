#include "client.h"
Client::Client(const std::string& _id, const Server& _server)
    : id { _id }
    , server { &_server }
{
    std::string _public_key {}, _private_key {};
    crypto::generate_key(_public_key, _private_key);
    public_key = _public_key;
    private_key = _private_key;
}
const std::string Client::get_id() const
{
    return id;
}
const std::string Client::get_publickey() const
{
    return public_key;
}
const double Client::get_wallet() const
{
    return server->get_wallet(id);
}
std::string Client::sign(const std::string& txt) const
{
    std::string signature = crypto::signMessage(private_key, txt);
    return signature;
}
bool Client::transfer_money(const std::string& receiver, const double& value)
{
    if (server->get_client(receiver) == nullptr || (value > get_wallet()))
        return false;
    if (receiver.compare(get_id()) == 0)
        return false;

    std::string trx;
    trx = this->get_id() + "-" + receiver + "-" + std::to_string(value);
    return server->add_pending_trx(trx, sign(trx));
}
size_t Client::generate_nonce()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, static_cast<double>(SIZE_MAX));
    return static_cast<size_t>(dist(mt));
}