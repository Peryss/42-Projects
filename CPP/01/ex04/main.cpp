/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:24:49 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 16:53:49 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(const std::string& content, const std::string& s1, const std::string& s2)
{
    
}

int main(int argc, char** argv)
{
    if (argc != 4) 
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty." << std::endl;
        return (1);
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Cannot open input file: " << filename << std::endl;
        return (1);
    }

    char c;
    std::string content;
    while (infile.get(c))
        content += c;
    infile.close();
    
    std::string replaced = replaceString(content, s1, s2);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error: Cannot open output file." << std::endl;
        return 1;
    }

    outfile << replaced;
    outfile.close();

    std::cout << "Replacement done. Output written to: " << filename + ".replace" << std::endl;
    return 0;
}
