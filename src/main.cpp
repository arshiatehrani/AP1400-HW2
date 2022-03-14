
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
    if (false) // make false to run unit-tests
    {

        // std::cout << "Hello world!!!" << std::endl;
        Server s {};
        // auto u1 { s.add_client("arshia") };
        // auto u2 { s.add_client("ali") };
        // auto u3 { s.add_client("yasi") };
        // auto u4 { s.add_client("zahra") };

        // std::cout << "arshia's wallet" << u1->get_wallet() << std::endl;
        // std::cout << "ali's wallet" << u2->get_wallet() << std::endl;
        // std::cout << "yasi's wallet" << u3->get_wallet() << std::endl;
        // std::cout << "zahra's wallet" << u4->get_wallet() << std::endl;

        // u1->transfer_money("ali", 1);
        // u2->transfer_money("yasi", 3);
        // u3->transfer_money("arshia", 2);
        // u4->transfer_money("zahra", 6);
        // for (auto a : pending_trxs)
        //     std::cout << a << std::endl;
        // s.mine();

        auto u1 { s.add_client("arshia") };
        auto u2 { s.add_client("arshia") };
        auto u3 { s.add_client("arshia") };
        auto u4 { s.add_client("arshia") };
        std::cout << "u1: " << u1->get_id() << std::endl;
        std::cout << "u2: " << u2->get_id() << std::endl;
        std::cout << "u3: " << u3->get_id() << std::endl;
        std::cout << "u4: " << u4->get_id() << std::endl;

        u1->transfer_money("arshia", 1);
        u2->transfer_money("arshia", 3);
        u3->transfer_money("arshia", 2);
        u4->transfer_money("arshia", 1);
        for (auto a : pending_trxs)
            std::cout << "trx########## " << a << std::endl;
        s.mine();
        // s.add_pending_trx("yasi-zahra-1", u3->sign("yasi-zahra-1"));
        // s.add_pending_trx("zahra-ali-1", u4->sign("zahra-ali-1"));
        // s.add_pending_trx("ali-yasi-1", u2->sign("ali-yasi-1"));
        // std::cout << s.mine() << std::endl;

        // u1->transfer_money("yasi", 5);
        // Server server {};
        // auto bryan { server.add_client("bryan") };
        // auto clint { server.add_client("clint") };
        // bool valid { bryan->transfer_money("no_one", 0.5) };
        // std::cout << "valid: " << valid << std::endl;
        // while (true)
        //     std::cout << "u nonce " << u->generate_nonce() << ",u2 nonce " << u2->generate_nonce() << std::endl;
        // for (size_t i {}; i < 100; i++)
        //     std::cout << "u nonce " << u1->generate_nonce() << ",u2 nonce " << u2->generate_nonce() << std::endl;
        // show_pending_transactions();

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