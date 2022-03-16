
#include "client.h"
#include "server.h"
#include <gtest/gtest.h>
#include <iostream>
void show_pending_transactions();
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {

        Server s {};
        auto Arshia { s.add_client("Arshia") };
        auto Jessy { s.add_client("Jessy") };
        auto Bryan { s.add_client("Bryan") };
        auto Angelina { s.add_client("Angelina") };

        show_wallets(s);

        Jessy->transfer_money("Arshia", 1);
        Angelina->transfer_money("Jessy", 1);
        Bryan->transfer_money("Angelina", 1);
        Arshia->transfer_money("Bryan", 2);
        Jessy->transfer_money("Angelina", 1);
        Jessy->transfer_money("Angelina", 1);
        Jessy->transfer_money("Angelina", 9);

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
void show_pending_transactions()
{
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& trx : pending_trxs)
        std::cout << trx << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}