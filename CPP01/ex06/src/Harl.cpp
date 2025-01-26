/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:12:40 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 17:05:44 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

void Harl::debug() {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelIndex = 4;

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
            std::cout << std::endl;
            /* FALLTHROUGH */
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            info();
            std::cout << std::endl;
            /* FALLTHROUGH */
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            std::cout << std::endl;
            /* FALLTHROUGH */
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

/*
** En C++98, le compilateur émet des avertissements pour les "fall-through" implicites
** dans les switch-case. Ces avertissements sont traités comme des erreurs avec -Werror.
** Le commentaire /* FALLTHROUGH  est une convention qui indique au compilateur que
** le "fall-through" est intentionnel, permettant ainsi d'éviter ces avertissements.
** En C++17, on utiliserait l'attribut [[fallthrough]] à la place.
*/
