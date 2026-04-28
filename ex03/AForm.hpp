/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:50:00 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/28 12:50:00 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    AForm(const std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned(const Bureaucrat& b);

    // Función virtual pura: hace la clase abstracta
    virtual void execute(Bureaucrat const & executor) const = 0;

    // Validación común para todos los hijos
    void        checkRequirements(Bureaucrat const & executor) const;

    class GradeTooHighException : public std::exception {
        public: virtual const char* what() const throw() { return "Grade is too high!"; }
    };
    class GradeTooLowException : public std::exception {
        public: virtual const char* what() const throw() { return "Grade is too low!"; }
    };
    class FormNotSignedException : public std::exception {
        public: virtual const char* what() const throw() { return "Form is not signed!"; }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif