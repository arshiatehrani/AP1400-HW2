
#include "client.h"
#include "server.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        std::cout << "Hello world!!!" << std::endl;
        Server s {};
        auto u1 { s.add_client("arshia") };
        auto u2 { s.add_client("ali") };
        auto u3 { s.add_client("yasi") };
        auto u4 { s.add_client("zahra") };
        // s.add_client("arshia");
        // std::cout << s.get_client("arshia") << std::endl;
        // std::cout << s.get_wallet("arshia") << std::endl;
        // Client a { "arshia", s };
        // std::cout << a.get_wallet() << std::endl;
        // std::cout << s.add_pending_trx("arshia-ali-5", "aaaaa") << std::endl;
        // s.add_client("arshia");
        s.add_pending_trx("arshia-ali-5", u1->sign("arshia-ali-5"));
        s.add_pending_trx("yasi-zahra-5", u3->sign("yasi-zahra-5"));
        s.add_pending_trx("zahra-ali-5", u4->sign("zahra-ali-5"));
        s.add_pending_trx("ali-yasi-5", u2->sign("ali-yasi-5"));
        // s.mine();
        u1->transfer_money("yasi", 5);
        Server server {};
        auto bryan { server.add_client("bryan") };
        auto clint { server.add_client("clint") };
        bool valid { bryan->transfer_money("no_one", 0.5) };
        std::cout << "valid: " << valid << std::endl;
        // while (true)
        //     std::cout << "u nonce " << u->generate_nonce() << ",u2 nonce " << u2->generate_nonce() << std::endl;
        // for (size_t i {}; i < 100; i++)
        //     std::cout << "u nonce " << u1->generate_nonce() << ",u2 nonce " << u2->generate_nonce() << std::endl;

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