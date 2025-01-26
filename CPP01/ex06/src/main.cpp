/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:58 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 16:58:50 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./harlFilter \"level\"" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(argv[1]);

    return (0);
}
