/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:25:51 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 16:33:57 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <exception>

Base *generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new A();
    if (i == 1)
        return new B();
    if (i == 2)
        return new C();
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
	{
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(std::exception &e) {}

    try
	{
        B &b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(std::exception &e) {}

    try
	{
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(std::exception &e) {}
}

int main(void)
{
    std::cout << "=== Test 1: Génération multiple avec différentes seeds ===" << std::endl;
    for (int i = 0; i < 5; i++)
	{
        srand(time(NULL) + i);
        Base *ptr = generate();
        std::cout << "Instance " << i + 1 << " est de type: ";
        identify(ptr);
        std::cout << "Vérification par référence: ";
        identify(*ptr);
        std::cout << std::endl;
        delete ptr;
    }

    std::cout << "\n=== Test 2: Test avec pointeur NULL ===" << std::endl;
    Base *null_ptr = NULL;
    std::cout << "Identification du pointeur NULL: ";
    identify(null_ptr);

    std::cout << "\n=== Test 3: Test avec instances explicites ===" << std::endl;
    A a_instance;
    B b_instance;
    C c_instance;

    std::cout << "Test des références:" << std::endl;
    Base &ref_a = a_instance;
    Base &ref_b = b_instance;
    Base &ref_c = c_instance;

    std::cout << "Instance A: ";
    identify(ref_a);
    std::cout << "Instance B: ";
    identify(ref_b);
    std::cout << "Instance C: ";
    identify(ref_c);

    std::cout << "\n=== Test 4: Test avec pointeurs explicites ===" << std::endl;
    Base *ptr_a = &a_instance;
    Base *ptr_b = &b_instance;
    Base *ptr_c = &c_instance;

    std::cout << "Pointeur vers A: ";
    identify(ptr_a);
    std::cout << "Pointeur vers B: ";
    identify(ptr_b);
    std::cout << "Pointeur vers C: ";
    identify(ptr_c);

    return 0;
}
