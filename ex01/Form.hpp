/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:42:58 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/21 15:46:33 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool sig;
	const int _gradeSig;
	const int _gradeExe;

public:
	Form();
	Form(const std::string name, int gradeSig, int gradeExe);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	// Acción principal
    void        beSigned(const Bureaucrat& b);

    // Excepciones
    class GradeTooHighException : public std::exception {
        public: virtual const char* what() const throw() { return "Form grade too high!"; }
    };
    class GradeTooLowException : public std::exception {
        public: virtual const char* what() const throw() { return "Form grade too low!"; }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif