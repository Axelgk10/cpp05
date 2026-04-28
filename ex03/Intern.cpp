/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:48:28 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/28 14:35:37 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

AForm* Intern::createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
AForm* Intern::createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
AForm* Intern::createPardon(std::string target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*methods[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*methods[i])(target);
		}
	}

	std::cout << "Error: Intern cannot create form " << formName << std::endl;
	return NULL;
}