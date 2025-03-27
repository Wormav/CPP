/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:08:42 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/27 14:09:19 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T>

void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif
