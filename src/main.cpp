#include "header.hpp"
#include "lib.hpp"

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
    } else {
        constexpr std::size_t _err_argc = 3;
        std::cerr << "error: " << _err_argc << '\n';
        return _err_argc;
    }
}