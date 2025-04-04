/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:55:05 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/04 17:05:21 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <iterator>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) > static_cast<long>(_N - _numbers.size()))
				throw std::out_of_range("Cannot add more numbers than the capacity allows");

			_numbers.insert(_numbers.end(), begin, end);
		}


		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span is full, cannot add more numbers";
				}
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return "Not enough numbers to find a span";
				}
		};
};

#endif
