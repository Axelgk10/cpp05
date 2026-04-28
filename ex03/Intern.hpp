/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:48:08 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/28 14:32:21 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm* makeForm(std::string formName, std::string target);

private:
	AForm* createShrubbery(std::string target);
	AForm* createRobotomy(std::string target);
	AForm* createPardon(std::string target);
};

#endif