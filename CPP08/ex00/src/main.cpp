/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:21:04 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/04 16:42:58 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <vector>
#include <list>
#include <deque>
#include <set>

void printHeader(const std::string& title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

template <typename T>
void printContainer(T& container, const std::string& name)
{
    std::cout << name << " contains: ";
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void testEasyfind(T& container, const std::string& containerName, int valueToFind, bool shouldFind) {
    std::cout << "Searching for " << valueToFind << " in "
	<< containerName << ": ";
    try
	{
        typename T::iterator it = easyfind(container, valueToFind);
        std::cout << "Value found: " << *it << " at position ";

        typename T::iterator begin = container.begin();
        int position = 0;
        while (begin != it)
		{
            ++begin;
            ++position;
        }
        std::cout << position << std::endl;

        if (!shouldFind)
            std::cout << "ERROR: A value that shouldn't have been found was found!" << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
        if (shouldFind)
            std::cout << "ERROR: A value that should have been found wasn't found!" << std::endl;
    }
}

int main()
{
    printHeader("Tests with std::vector");
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    printContainer(vec, "Vector");
    testEasyfind(vec, "vector", 3, true);
    testEasyfind(vec, "vector", 6, false);
    testEasyfind(vec, "vector", 1, true);
    testEasyfind(vec, "vector", 5, true);

    printHeader("Tests with std::list");
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    printContainer(lst, "List");
    testEasyfind(lst, "list", 30, true);
    testEasyfind(lst, "list", 25, false);
    testEasyfind(lst, "list", 10, true);
    testEasyfind(lst, "list", 50, true);

    printHeader("Tests with std::deque");
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_front(50);
    deq.push_back(300);

    printContainer(deq, "Deque");
    testEasyfind(deq, "deque", 100, true);
    testEasyfind(deq, "deque", 150, false);
    testEasyfind(deq, "deque", 50, true);
    testEasyfind(deq, "deque", 300, true);

    printHeader("Tests with std::set");
    std::set<int> mySet;
    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(15);
    mySet.insert(20);
    mySet.insert(25);

    printContainer(mySet, "Set");
    testEasyfind(mySet, "set", 15, true);
    testEasyfind(mySet, "set", 7, false);
    testEasyfind(mySet, "set", 5, true);
    testEasyfind(mySet, "set", 25, true);

    printHeader("Tests with empty container");
    std::vector<int> emptyVec;
    printContainer(emptyVec, "Empty vector");
    testEasyfind(emptyVec, "empty vector", 1, false);

    printHeader("Tests with duplicate values");
    std::list<int> dupList;
    dupList.push_back(42);
    dupList.push_back(42);
    dupList.push_back(17);
    dupList.push_back(42);

    printContainer(dupList, "List with duplicates");
    testEasyfind(dupList, "list with duplicates", 42, true);

    return 0;
}
