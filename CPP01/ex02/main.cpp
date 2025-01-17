/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:17:45 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/17 20:35:03 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of the string variable:" << &str << std::endl;
	std::cout << "memory address held by stringPTR:" << stringPTR << std::endl;
	std::cout << "memory address held by stringREF:" << &stringREF <<std::endl;

	std::cout << std::endl;

	std::cout << "value of the string variable:" << str << std::endl;
    std::cout << "value pointed to by stringPTR:" << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF:" << stringREF << std::endl;

    return (0);
}
