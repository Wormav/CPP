/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:58 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 16:22:44 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int main() {
    Harl harl;

    std::cout << "Test with DEBUG:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTest with INFO:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTest with WARNING:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTest with ERROR:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTest with unknown level:" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
