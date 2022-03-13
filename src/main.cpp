
#include "client.h"
#include "server.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (true) // make false to run unit-tests
    {
        std::cout << "Hello world!!!" << std::endl;
        Server s {};
        auto bryan { s.add_client("arshia") };
        auto bryan2 { s.add_client("ali") };
        // s.add_client("arshia");
        // std::cout << s.get_client("arshia") << std::endl;
        // std::cout << s.get_wallet("arshia") << std::endl;
        // Client a { "arshia", s };
        // std::cout << a.get_wallet() << std::endl;
        // std::cout << s.add_pending_trx("arshia-ali-5", "aaaaa") << std::endl;
        // s.add_client("arshia");
        s.add_pending_trx("arshia-ali-5", bryan->sign("arshia-ali-5"));
        // while (true)
        //     std::cout << "bryan nonce " << bryan->generate_nonce() << ",bryan2 nonce " << bryan2->generate_nonce() << std::endl;
        for (size_t i {}; i < 100; i++)
            std::cout << "bryan nonce " << bryan->generate_nonce() << ",bryan2 nonce " << bryan2->generate_nonce() << std::endl;

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