/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:56:57 by jlorette          #+#    #+#             */
/*   Updated: 2025/05/07 11:15:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {
    _numbers.reserve(N);
}

Span::Span(const Span &src) : _N(src._N), _numbers(src._numbers) {}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        _N = rhs._N;
        _numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N)
        throw FullSpanException();

    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1)
        throw NotEnoughNumbersException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        minSpan = std::min(minSpan, span);
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1)
        throw NotEnoughNumbersException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}
