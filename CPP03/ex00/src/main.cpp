/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:01:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/18 09:48:15 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

int main()
{
    ClapTrap wormav;
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

    return (0);
}
