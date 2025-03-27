/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:43:39 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/27 14:49:50 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : elements(NULL), n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), n(n) {}

template <typename T>
Array<T>::Array(const Array &other) : elements(NULL), n(0)
{
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
	{
        delete[] elements;
        n = other.n;
        elements = new T[n];
        for (unsigned int i = 0; i < n; ++i)
            elements[i] = other.elements[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= n)
        throw std::out_of_range("Index out of range");
    return elements[index];
}

template <typename T>

unsigned int Array<T>::size() const
{
    return n;
}
