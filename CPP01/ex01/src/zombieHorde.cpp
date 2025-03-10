/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:52:15 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/10 14:01:38 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;
    Zombie* horde = static_cast<Zombie*>(operator new[](N * sizeof(Zombie)));
    for (int i = 0; i < N; i++) {
        std::ostringstream oss;
        oss << name << "_" << (i + 1);
        new (horde + i) Zombie(oss.str());
    }
    return (horde);
}
