/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:56:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:19:04 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Character.hpp>
#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

int main() {
    std::cout << "\n--- [ Constructors ] ---\n" << std::endl;

    I_MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    I_Character* me = new Character("me");

    A_Materia* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    I_Character* bob = new Character("bob");

    std::cout << "\n--- [ Actions ] ---\n" << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n--- [ Destructors ] ---\n" << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}
