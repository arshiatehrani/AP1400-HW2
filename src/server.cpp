#include "server.h"
std::shared_ptr<Client> Server::add_client(std::string id)
{
    std::cout << "add_client server" << std::endl;
    for (const auto& [name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(1000, 9999);
            std::string rnd_num { std::to_string(static_cast<int>(dist(mt))) };
            id += rnd_num;
            break;
        }
    }

    double wallet { 5 };
    std::shared_ptr<Client> pntr_client { std::make_shared<Client>(id, *this) };
    clients[pntr_client] = wallet;
    return pntr_client;
}
const std::shared_ptr<Client> Server::get_client(const std::string& id) const
{
    std::cout << "get_client server" << std::endl;
    for (const auto& [name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            return name;
        }
    }
    return nullptr;
}
const double Server::get_wallet(const std::string& id) const
{
    std::cout << "get_wallet server" << std::endl;
    for (const auto& [name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            return value;
        }
    }
    throw std::logic_error("Client not found!");
}

void show_wallets(const Server& server)
{
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& client : server.clients)
        std::cout << client.first->get_id() << " : " << client.second << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}