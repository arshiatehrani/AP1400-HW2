#ifndef SERVER_H
#define SERVER_H
#include "client.h"
#include <compare>
#include <crypto.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
class Client;
class Server {
public:
    Server() = default;
    std::shared_ptr<Client> add_client(std::string id);
    const std::shared_ptr<Client> get_client(const std::string& id) const;
    const double get_wallet(const std::string& id) const;
    bool parse_trx(std::string trx, std::string sender, std::string receiver, double value);
    bool add_pending_trx(std::string trx, std::string signature);
    size_t mine();
    friend void show_wallets(const Server& server);

private:
    std::map<std::shared_ptr<Client>, double> clients;
};

#endif // SERVER_H