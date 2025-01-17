/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:17:45 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/17 19:25:25 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>

int main() {
    int N = 5;
    std::string name = "Zombie_amazing_name";

    Zombie* horde = zombieHorde(N, name);
    if (!horde) {
        std::cerr << "Erreur : Unable to create the horde." << std::endl;
        return (1);
    }

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    for (int i = 0; i < N; i++) {
        horde[i].~Zombie();
    }
    operator delete[](horde);

    return 0;
}
