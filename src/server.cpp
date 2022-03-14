#include "server.h"
std::vector<std::string> pending_trxs;
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
    std::shared_ptr<Client> pntr_client { std::make_shared<Client>(id, *this) };
    clients[pntr_client] = wallet;
    return pntr_client;
}
const std::shared_ptr<Client> Server::get_client(const std::string& id) const
{
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
    for (const auto& [name, value] : clients) {
        const std::strong_ordering order = id <=> (*name).get_id();
        if (std::is_eq(order)) {
            return value;
        }
    }
    throw std::logic_error("Client is not found!");
}

bool Server::parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value)
{
    std::string svalue;
    size_t cnt {};
    for (const auto& c : trx) {
        if (c == '-') {
            cnt++;
            continue;
        }
        if (cnt == 0)
            sender += c;
        if (cnt == 1)
            receiver += c;
        if (cnt == 2)
            svalue += c;
    }
    if (cnt != 2)
        throw std::runtime_error("Wrong input!");
    value = std::stod(svalue);
    std::cout << sender << " " << receiver << " " << value << std::endl;
    return true;
}

bool Server::add_pending_trx(std::string trx, std::string signature) const
{

    std::string sender_id;
    std::string receiver_id;
    double value;
    parse_trx(trx, sender_id, receiver_id, value);
    bool authentic = crypto::verifySignature(get_client(sender_id)->get_publickey(), trx, signature);
    if (authentic && (get_client(sender_id)->get_wallet() >= value)) {
        pending_trxs.push_back(trx);
        return true;
    }
    return false;
}
size_t Server::mine()
{
    if (pending_trxs.size() == 0)
        return 0;
    else {
        std::string hash;
        std::string mempool;
        std::vector<std::string> sender { pending_trxs.size() };
        std::vector<std::string> receiver { pending_trxs.size() };
        std::vector<double> value { static_cast<double>(pending_trxs.size()) };
        for (size_t i {}; i < pending_trxs.size(); i++) {
            mempool += pending_trxs[i];
        }
        // extracting senders, receivers and values
        for (size_t j {}; j < pending_trxs.size(); j++) {
            parse_trx(pending_trxs[j], sender[j], receiver[j], value[j]);
        }
        while (true) {
            for (const auto& [id, wallet] : clients) {
                size_t nonce { (*id).generate_nonce() };
                hash = crypto::sha256(mempool + std::to_string(nonce));
                if (hash.substr(0, 10).find("000") != std::string::npos) {
                    for (size_t x {}; x < pending_trxs.size(); x++) {
                        clients[get_client(sender[x])] -= value[x];
                        clients[get_client(receiver[x])] += value[x];
                    }
                    clients[id] += 6.25;
                    pending_trxs.clear();
                    std::cout << "Miner's ID: " << (*id).get_id() << std::endl;
                    return nonce;
                }
            }
        }
    }
}
void show_wallets(const Server& server)
{
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& client : server.clients)
        std::cout << client.first->get_id() << " : " << client.second << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}