/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:07:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 15:45:15 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_REPLACE_HPP
#define STRING_REPLACE_HPP

#define ERR_ARGS "\033[31mThe number of arguments provided is not correct!\
\033[0m"

#define ERR_USAGE "\033[31mPlease use the program as follows: \
<file name> <target string> <replacemen string>\033[0m"

#define ERR_OPEN_FILE "\033[31mError: Unable to open the file\033[0m"

std::string replace_str(const std::string& src, const std::string& s1,
const std::string& s2);

#endif
