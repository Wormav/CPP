/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:35:16 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/27 14:35:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void iter(T *array, size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>

void print(T &element)
{
    std::cout << element << " ";
}

#endif
