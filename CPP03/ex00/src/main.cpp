/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:01:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/18 11:11:24 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

int main()
{
	ClapTrap wormav("Wormav");
    ClapTrap worbav(wormav);

    std::cout << "\n--- [ Wormav VS Worbav ] ---\n" << std::endl;

    wormav.attack("Worbav");
    worbav.takeDamage(0);

    worbav.attack("Wormav");
    wormav.takeDamage(0);

    wormav.beRepaired(2);

    worbav.beRepaired(1);

    wormav.attack("Worbav");
    worbav.takeDamage(0);

    worbav.attack("Wormav");
    wormav.takeDamage(0);

	std::cout << "\n--- [ END GAME ] ---\n" << std::endl;

	std::cout << "\n--- [ TESTING ALL FUNCTIONS ] ---\n" << std::endl;

	ClapTrap test;

    // Testing assignment operator
    ClapTrap assigned;
    assigned = wormav;
    assigned.attack("Test Target");
    assigned.takeDamage(5);
    assigned.beRepaired(3);

    // Testing default constructor and other functions
    test.attack("Default Target");
    test.takeDamage(3);
    test.beRepaired(1);

    return (0);
}
