/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:48:52 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 12:56:35 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <A_Animal.hpp>
#include <Brain.hpp>

class Cat : public A_Animal
{
	private:
    	Brain* brain;

	public:
    	Cat();
    	Cat(const Cat& other);
    	Cat& operator=(const Cat& other);
    	virtual ~Cat();

    	void makeSound() const;
		void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif
