/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:43:56 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/21 16:38:32 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT__HPP
#define BUREAUCRAT__HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& f) const;
    void executeForm(AForm const & form) const;

    class GradeTooHighException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Grade is too high (Max 1)!";
        }
    };
    class GradeTooLowException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Grade is too low (Min 150)!";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif