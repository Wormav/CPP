/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:17:45 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/14 22:50:56 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int main()
{
	Zombie stackZombie("StackZombie");
	stackZombie.announce();

	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	delete heapZombie;

	randomChump("RandomChump");

	return (0);
}
