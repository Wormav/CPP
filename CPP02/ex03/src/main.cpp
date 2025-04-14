/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:19:48 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/14 08:04:48 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(5, 0);
    Point C(0, 5);

    Point P1(2, 2);
    Point P2(5, 5);
    Point P3(2, 4);
    Point P4(2.5, 0);

    std::cout << "P1 is inside: " << bsp(A, B, C, P1) << std::endl;
    std::cout << "P2 is inside: " << bsp(A, B, C, P2) << std::endl;
    std::cout << "P3 is inside: " << bsp(A, B, C, P3) << std::endl;
    std::cout << "P4 is inside: " << bsp(A, B, C, P4) << std::endl;

    return (0);
}
