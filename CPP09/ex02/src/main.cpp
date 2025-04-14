/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:21:55 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:21:57 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    if (!sorter.parseAndStoreNumbers(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    sorter.sort();

    return 0;
}
