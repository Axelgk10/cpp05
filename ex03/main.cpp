/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:47:23 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/28 14:39:48 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    unknown = someRandomIntern.makeForm("coffee request", "Boss"); // Caso de error

    // Ejemplo de uso con un burócrata
    if (scf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete rrf; // IMPORTANTE: El Intern hace 'new', nosotros hacemos 'delete'
    }
    
    delete scf;
    delete ppf;
    // delete unknown; // No es necesario, es NULL

    return 0;
}