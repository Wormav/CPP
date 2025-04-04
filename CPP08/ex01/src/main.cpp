/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:58:42 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/04 17:06:57 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Span.hpp>
#include <cstdlib>
#include <ctime>

int main()
{
    try
	{
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        try
		{
            sp.addNumber(42);
        }
		catch (const std::exception& e)
		{
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Span sp2 = Span(1);
        sp2.addNumber(5);

        try
		{
            std::cout << sp2.shortestSpan() << std::endl;
        }
		 catch (const std::exception& e)
		{
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Span largeSpan(10000);
        srand(time(NULL));

        for (int i = 0; i < 10000; i++)
            largeSpan.addNumber(rand());

        std::cout << "Large Span shortest: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Large Span longest: " << largeSpan.longestSpan() << std::endl;

        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        Span sp3(5);
        sp3.addRange(v.begin(), v.end());
        sp3.addNumber(42);
        sp3.addNumber(100);

        std::cout << "Range Span shortest: " << sp3.shortestSpan() << std::endl;
        std::cout << "Range Span longest: " << sp3.longestSpan() << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
