#ifndef CLIENT_H
#define CLIENT_H
#include "server.h"
#include <compare>
#include <crypto.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <random>
class Server;
class Client {
public:
    Client(std::string id, const Server& server); // client constructor
    const std::string get_id() const; // client get_id
    const std::string get_publickey() const; // client get_public key
    const double get_wallet() const; // client get_wallet
    std::string sign(const std::string& txt) const; // client sign
    bool transfer_money(std::string receiver, double value);
    size_t generate_nonce(); // client generate nonce

private:
    Server const* const server;
    const std::string id;
    std::string public_key;
    std::string private_key;
};
#endif // CLIENT_H