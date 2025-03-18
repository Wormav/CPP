/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:01:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/18 11:24:53 by jlorette         ###   ########.fr       */
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

	std::cout << "\n--- [ TESTING ALL FUNCTIONS ] ---\n" << std::endl;

	ClapTrap test;

    // Testing assignment operator for ClapTrap
    ClapTrap assigned;
    assigned = wormav;
    assigned.attack("Test Target");
    assigned.takeDamage(5);
    assigned.beRepaired(3);

    // Testing default constructor and other functions for ClapTrap
    test.attack("Default Target");
    test.takeDamage(3);
    test.beRepaired(1);

    // Testing copy constructor for ScavTrap
    ScavTrap scavyCopy(scavy);
    scavyCopy.attack("Copy Target");
    scavyCopy.guardGate();

    // Testing assignment operator for ScavTrap
    ScavTrap scavyAssigned;
    scavyAssigned = scavy;
    scavyAssigned.attack("Assigned Target");
    scavyAssigned.guardGate();

    // Testing copy constructor for FragTrap
    FragTrap fraggyCopy(fraggy);
    fraggyCopy.attack("Copy Target");
    fraggyCopy.highFivesGuys();

    // Testing assignment operator for FragTrap
    FragTrap fraggyAssigned;
    fraggyAssigned = fraggy;
    fraggyAssigned.attack("Assigned Target");
    fraggyAssigned.highFivesGuys();

    // Testing copy constructor for DiamondTrap
    DiamondTrap diamondCopy(diamond);
    diamondCopy.attack("Copy Target");
    diamondCopy.highFivesGuys();
    diamondCopy.guardGate();
    diamondCopy.whoAmI();

    // Testing assignment operator for DiamondTrap
    DiamondTrap diamondAssigned;
    diamondAssigned = diamond;
    diamondAssigned.attack("Assigned Target");
    diamondAssigned.highFivesGuys();
    diamondAssigned.guardGate();
    diamondAssigned.whoAmI();

	std::cout << std::endl;

	return (0);
}
