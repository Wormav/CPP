/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:28:11 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 23:42:13 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <AForm.hpp>

class Intern {

    public:
        Intern(void);
        ~Intern(void);
        Intern &operator=(const Intern &src);
        Intern(const Intern &cpy);

        AForm *makeForm(std::string const &formName, std::string const &target) const;
        AForm *createShrubbery(std::string const &target) const;
        AForm *createPresidential(std::string const &target) const;
        AForm *createRobotomy(std::string const &target) const;
};

#endif
