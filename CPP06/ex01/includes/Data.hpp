/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:36:01 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:37:40 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private:
		int value;

	public:
		Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();

		int getValue() const;
		void setValue(int value);
};

#endif
