/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:12:38 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 11:07:47 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

/* static void run(const std::string& s) {
    std::cout << "----- \"" << s << "\" -----" << std::endl;
    ScalarConverter::convert(s);
    std::cout << std::endl;
} */

int main(int argc, char** argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
/*     run("0");
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
    run("999999999999999999999999"); 
    run("qweqeqeqeqeq");
    run("\0");
    run("\\");
    run("234 .24234");
    run("234 .24234f");
    run("3402823466385288598117041834845169254423423423423.00000000000000"); */

    return 0;
}
