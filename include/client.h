#ifndef CLIENT_H
#define CLIENT_H
#include "server.h"
#include <crypto.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <random>
class Server;
class Client {
public:
    Client(std::string id, const Server& server);
    const std::string get_id() const;
    const std::string get_publickey() const;
    const double get_wallet() const;
    std::string sign(std::string txt);
    bool transfer_money(std::string receiver, double value);
    size_t generate_nonce();

private:
    Server const* const server;
    const std::string id;
    std::string public_key;
    std::string private_key;
};
#endif // CLIENT_H