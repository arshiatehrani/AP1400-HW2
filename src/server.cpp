#include "server.h"
std::shared_ptr<Client> Server::add_client(std::string id)
{
    for (const auto& [name, number] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq()) {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(1000, 9999);
            std::string rnd_num { std::to_string(static_cast<int>(dist(mt))) };
            id += rnd_num;
            break;
        }
    }

    double wallet { 5 };
    std::shared_ptr<Client> pntr_client { std::make_shared<client>(id) };
    clients[pntr_client] = wallet;
    return pntr_client;
}