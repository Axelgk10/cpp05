/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:44:07 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/14 19:26:24 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}


Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}