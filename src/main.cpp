
#include "client.h"
#include "server.h"
#include <gtest/gtest.h>
#include <iostream>
void show_pending_transactions()
{
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& trx : pending_trxs)
        std::cout << trx << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}
int main(int argc, char** argv)
{
    if (true) // make false to run unit-tests
    {

        // std::cout << "Hello world!!!" << std::endl;
        Server s {};
        auto arshia { s.add_client("arshia") };
        auto ali { s.add_client("ali") };
        auto yasi { s.add_client("yasi") };
        auto zahra { s.add_client("zahra") };

        show_wallets(s);

        ali->transfer_money("arshia", 1);
        zahra->transfer_money("ali", 1);
        yasi->transfer_money("zahra", 1);
        arshia->transfer_money("yasi", 2);
        ali->transfer_money("zahra", 1);
        ali->transfer_money("zahra", 1);
        ali->transfer_money("zahra", 9);

        for (auto a : pending_trxs)
            std::cout << a << std::endl;
        s.mine();
        show_wallets(s);
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}