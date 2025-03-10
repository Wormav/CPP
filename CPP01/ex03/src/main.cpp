/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:58 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/10 13:54:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <HumanA.hpp>
#include <HumanB.hpp>

int main()
{
        Weapon club1("crude spiked club");
        HumanA bob("Bob", club1);
        bob.attack();
        club1.setType("some other type of club");
        bob.attack();

        Weapon club2("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club2);
        jim.attack();
        club2.setType("some other type of club");
        jim.attack();

    return (0);
}
