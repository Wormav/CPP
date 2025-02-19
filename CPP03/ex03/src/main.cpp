/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:01:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/19 14:51:42 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <FragTrap.hpp>
#include <DiamondTrap.hpp>

int main()
{
    ClapTrap wormav("Wormav");
    ClapTrap worbav(wormav);

	std::cout << "\n--- [ Wormav VS Worbav ] ---\n" << std::endl;

    wormav.attack("Worbav");
    worbav.takeDamage(5);

    worbav.attack("Wormav");
    wormav.takeDamage(3);

    wormav.beRepaired(2);

    worbav.beRepaired(1);

    wormav.attack("Worbav");
    worbav.takeDamage(4);

    worbav.attack("Wormav");
    wormav.takeDamage(2);

	std::cout << "\n--- [ Scavy join the game ] ---\n" << std::endl;
    ScavTrap scavy("Scavy");

    scavy.attack("Wormav");
    wormav.takeDamage(20);

    scavy.guardGate();

	std::cout << "\n--- [ Fraggy join the game ] ---\n" << std::endl;
    FragTrap fraggy("Fraggy");


	fraggy.attack("Wormav");
    wormav.takeDamage(30);

	fraggy.highFivesGuys();

	std::cout << "\n--- [ Diamond join the game ] ---\n" << std::endl;
	DiamondTrap diamond("Diamond");

	diamond.attack("Wormav");
    wormav.takeDamage(30);

	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();

	std::cout << "\n--- [ END GAME ] ---\n" << std::endl;

    return (0);
}
