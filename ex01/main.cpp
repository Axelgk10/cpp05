/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:53:14 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/21 14:53:21 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form taxForm("Tax Form 22-B", 50, 100);

        std::cout << taxForm << std::endl;

        std::cout << "\n--- Intern tries to sign ---" << std::endl;
        intern.signForm(taxForm); // Fallará pero no detendrá el programa

        std::cout << "\n--- Boss tries to sign ---" << std::endl;
        boss.signForm(taxForm);   // Tendrá éxito

        std::cout << "\n" << taxForm << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Main catch: " << e.what() << std::endl;
    }

    return 0;
}