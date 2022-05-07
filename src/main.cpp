#include "../lib/hello_lib/include/lib.hpp"


#include "exception/exception.hpp"
#include "header.hpp"

#include <iostream>
#include <string>

int main (int argc, const char* argv[]) {
    if (argc == 3) {
        std::cout
            << argv[1] << " + "
            << argv[2] << " = "
            << add(std::stoi(argv[1]), std::stoi(argv[2])) << '\n';

            print_hello();

        return 0;

    } else
        throw exception(exception::TYPE::ARGC_ERROR);
}