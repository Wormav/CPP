/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:09:31 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/27 14:09:47 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_HPP
#define MIN_HPP

template <typename T>

T min(T a, T b)
{
    return (a < b) ? a : b;
}

#endif
