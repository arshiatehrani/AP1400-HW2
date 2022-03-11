
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
        s.add_client("arshia");
        std::cout << s.get_client("arshia") << std::endl;
        std::cout << s.get_wallet("arshia") << std::endl;
        Client a { "arshia", s };
        std::cout << a.get_wallet() << std::endl;
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