/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:22:14 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:23:05 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <sstream>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	void mergeInsertSortVector(std::vector<int>& arr);
	void insertionSortVector(std::vector<int>& arr);
	void mergeVector(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right);

	void mergeInsertSortDeque(std::deque<int>& deq);
	void insertionSortDeque(std::deque<int>& deq);
	void mergeDeque(std::deque<int>& result, std::deque<int>& left, std::deque<int>& right);

	double getTimeDifference(clock_t start, clock_t end);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	bool parseAndStoreNumbers(int argc, char** argv);
	void sort();

	const std::vector<int>& getVector() const;
	const std::deque<int>& getDeque() const;
};

#endif
