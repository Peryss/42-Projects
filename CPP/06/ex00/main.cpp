#include <iostream>
#include "ScalarConverter.hpp"

/*static void run(const std::string& s) {
    std::cout << "=== \"" << s << "\" ===\n";
    ScalarConverter::convert(s);
    std::cout << std::endl;
}*/

int main(int argc, char** argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }

    // Sample tests from subject + a few extras
    /*run("0");
    run("-42");
    run("42");
    run("0.0f");
    run("-4.2f");
    run("4.2f");
    run("42.0f");
    run("42.0");
    run("nan");
    run("nanf");
    run("+inff");
    run("-inff");
    run("+inf");
    run("-inf");
    run("a");
    run("'b'");
    run("128");
    run("999999999999999999999999"); */

    return 0;
}
