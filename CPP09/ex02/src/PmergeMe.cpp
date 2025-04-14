/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:22:05 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:22:07 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseAndStoreNumbers(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num <= 0 || iss.peek() != EOF) {
			return false;
		}
		_vec.push_back(num);
		_deq.push_back(num);
	}
	return true;
}

void PmergeMe::sort() {

	std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    clock_t vecStart = clock();
    mergeInsertSortVector(_vec);
    clock_t vecEnd = clock();

    clock_t deqStart = clock();
    mergeInsertSortDeque(_deq);
    clock_t deqEnd = clock();

    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "
              << std::fixed << getTimeDifference(vecStart, vecEnd) << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : "
              << std::fixed << getTimeDifference(deqStart, deqEnd) << " us" << std::endl;
}
void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
	if (arr.size() <= 1) return;

	if (arr.size() <= 16) {
		insertionSortVector(arr);
		return;
	}

	std::vector<int> left, right;
	size_t middle = arr.size() / 2;

	for (size_t i = 0; i < middle; ++i)
		left.push_back(arr[i]);

	for (size_t i = middle; i < arr.size(); ++i)
		right.push_back(arr[i]);

	mergeInsertSortVector(left);
	mergeInsertSortVector(right);
	mergeVector(arr, left, right);
}

void PmergeMe::insertionSortVector(std::vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::mergeVector(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
	size_t leftSize = left.size();
	size_t rightSize = right.size();
	size_t i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			++i;
		} else {
			arr[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < leftSize) {
		arr[k] = left[i];
		++i;
		++k;
	}

	while (j < rightSize) {
		arr[k] = right[j];
		++j;
		++k;
	}
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) {
	if (deq.size() <= 1) return;

	if (deq.size() <= 16) {
		insertionSortDeque(deq);
		return;
	}

	std::deque<int> left, right;
	size_t middle = deq.size() / 2;

	for (size_t i = 0; i < middle; ++i)
		left.push_back(deq[i]);

	for (size_t i = middle; i < deq.size(); ++i)
		right.push_back(deq[i]);

	mergeInsertSortDeque(left);
	mergeInsertSortDeque(right);
	mergeDeque(deq, left, right);
}

void PmergeMe::insertionSortDeque(std::deque<int>& deq) {
	for (size_t i = 1; i < deq.size(); ++i) {
		int key = deq[i];
		int j = i - 1;

		while (j >= 0 && deq[j] > key) {
			deq[j + 1] = deq[j];
			--j;
		}
		deq[j + 1] = key;
	}
}

void PmergeMe::mergeDeque(std::deque<int>& result, std::deque<int>& left, std::deque<int>& right) {
	size_t leftSize = left.size();
	size_t rightSize = right.size();
	size_t i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j]) {
			result[k] = left[i];
			++i;
		} else {
			result[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < leftSize) {
		result[k] = left[i];
		++i;
		++k;
	}

	while (j < rightSize) {
		result[k] = right[j];
		++j;
		++k;
	}
}

double PmergeMe::getTimeDifference(clock_t start, clock_t end) {
	return static_cast<double>(end - start) / (CLOCKS_PER_SEC);
}

const std::vector<int>& PmergeMe::getVector() const {
	return _vec;
}

const std::deque<int>& PmergeMe::getDeque() const {
	return _deq;
}
