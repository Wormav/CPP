/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:56:57 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/04 17:05:17 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

// Constructeur par défaut
Span::Span() : _N(0) {}

// Constructeur avec taille
Span::Span(unsigned int N) : _N(N) {
    _numbers.reserve(N);
}

// Constructeur de copie
Span::Span(const Span &src) : _N(src._N), _numbers(src._numbers) {}

// Opérateur d'assignation
Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        _N = rhs._N;
        _numbers = rhs._numbers;
    }
    return *this;
}

// Destructeur
Span::~Span() {}

// Ajouter un nombre
void Span::addNumber(int number) {
    if (_numbers.size() >= _N)
        throw FullSpanException();

    _numbers.push_back(number);
}

// Trouver le plus court span
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

// Trouver le plus long span
int Span::longestSpan() const {
    if (_numbers.size() <= 1)
        throw NotEnoughNumbersException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}
