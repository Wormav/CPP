/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:58 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 15:44:36 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string_replace.hpp>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 4)
    {
        std::cerr << "\033[31m" << ERR_ARGS << std::endl;
        std::cerr << ERR_USAGE << "\033[0m" << std::endl;
        return (1);
    }

    std::ifstream inFile(argv[1]);
    if (!inFile.is_open())
    {
        std::cerr << ERR_OPEN_FILE << std::endl;
        return (1);
    }

    std::string outFileName = std::string(argv[1]) + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile.is_open())
    {
        std::cerr << ERR_OPEN_FILE << outFileName << std::endl;
        inFile.close();
        return (1);
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        outFile << replace_str(line, argv[2], argv[3]);
        if (!inFile.eof())
            outFile << std::endl;
    }

    inFile.close();
    outFile.close();

    return (0);
}
