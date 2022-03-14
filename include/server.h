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
#include <sstream>
#include <string>
extern std::vector<std::string> pending_trxs;
class Client;
class Server {
public:
    Server() = default; // server default constructor
    std::shared_ptr<Client> add_client(std::string id); // server add_client
    const std::shared_ptr<Client> get_client(const std::string& id) const; // server get_client
    const double get_wallet(const std::string& id) const; // server get_wallet
    static bool parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value); // server parse_trx
    bool add_pending_trx(std::string trx, std::string signature) const; // Server add pending trx
    size_t mine(); // server mine
    friend void show_wallets(const Server& server); // server show wallets

private:
    std::map<std::shared_ptr<Client>, double> clients;
};
#endif // SERVER_H