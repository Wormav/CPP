/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:44:27 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 15:45:03 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string replace_str(const std::string& src, const std::string& s1,
const std::string& s2)
{
	if (s1.empty())
		return src;

	std::string result;
	size_t start = 0;
	size_t pos;

	while ((pos = src.find(s1, start)) != std::string::npos)
	{
		result += src.substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
	}
	result += src.substr(start);

	return result;
}
