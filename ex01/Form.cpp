/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:42:05 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/21 16:30:49 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), sig(false), _gradeSig(150), _gradeExe(150) {}

Form::Form(const std::string name, int gradeSig, int gradeExe) : name(name), sig(false), _gradeSig(gradeSig), _gradeExe(gradeExe) {
	if(gradeSig < 1 || gradeExe < 1)
		throw Form::GradeTooHighException();
	if(gradeSig > 150 || gradeExe > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) :name(other.name), sig(other.sig), _gradeSig(other._gradeSig), _gradeExe(other._gradeExe) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->sig = other.sig;
	}
	return *this;
}
Form::~Form() {}


std::string Form::getName() const { return name; }
bool	Form::getIsSigned() const { return sig; }
int		Form::getGradeToSign() const { return _gradeSig; }
int		Form::getGradeToExecute() const { return _gradeExe; }

void Form::beSigned(const Bureaucrat& b) {
	if(b.getGrade() > _gradeSig)
		throw Form::GradeTooLowException();
	sig = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName() 
		<< " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< " | Grade to sign: " << f.getGradeToSign()
		<< " | Grade to execute: " << f.getGradeToExecute();
	return os;
}