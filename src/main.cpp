
/// : static library
#include "../lib/hello_lib/include/lib.hpp"

/// : submodule git
#include "argparse/argparse.hpp"

/// : config
#include "config/config.hpp"

/// : exception
#include "exception/exception.hpp"

/// : headers
#include "header.hpp"


/// : standart template library (STL)
#include <iostream>
#include <string>

int main (int argc, const char* argv[]) {
    argparse::ArgumentParser _prs(V1_PROJECT_NAME, V1_VERSION);

    _prs.add_argument("first") .scan<'i',int>();
    _prs.add_argument("second").scan<'i',int>();

    try {
        _prs.parse_args(argc, argv);

        auto _input1 = _prs.get<int>("first");
        auto _input2 = _prs.get<int>("second");

        std::cout
            << _input1 << " + "
            << _input2 << " = "
            << add(_input1, _input2) << '\n';

        print_hello();  /// static library

    } catch(const std::runtime_error& err) {
        constexpr std::size_t args_no_received { 2 };
        std::cerr << err.what() << std::endl;
        std::cerr <<    _prs    << std::endl;
        std::exit(args_no_received);
    }

    /// test exception
    bool _is_err = false;
    std::cin >> _is_err;

    if (_is_err)
        throw exception(exception::TYPE::ARGC_ERROR);
    /// test exception

    return 0;
}