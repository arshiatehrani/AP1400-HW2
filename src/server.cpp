#include "server.h"
std::shared_ptr<Client> Server::add_client(std::string id)
{
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
    std::shared_ptr<Client> pntr_client { std::make_shared<client>(id, *this) };
    clients[pntr_client] = wallet;
    return pntr_client;
}
std::shared_ptr<Client> Server::get_client(std::string id)
{
    for (const auto& [name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            return name;
        }
    }
    throw std::logic_error("Client not found!");
}
double Server::get_wallet(std::string id)
{
    for (const auto& [name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            return value;
        }
    }
    throw std::logic_error("Client not found!");
}