/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:53:14 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/21 16:45:25 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat boss("El Jefe", 1);
        Bureaucrat intern("Becario", 140);
        
        Form important("Contrato Millonario", 20, 50);
        Form simple("Permiso de Vacaciones", 145, 150);

        std::cout << "--- INFO INICIAL ---" << std::endl;
        std::cout << important << std::endl;
        std::cout << simple << std::endl;

        std::cout << "\n--- EL BECARIO INTENTA FIRMAR TODO ---" << std::endl;
        intern.signForm(important); // Fallará (140 > 20)
        intern.signForm(simple);    // Tendrá éxito (140 <= 145)

        std::cout << "\n--- EL JEFE FIRMA LO QUE FALTA ---" << std::endl;
        boss.signForm(important);   // Tendrá éxito (1 <= 20)

        std::cout << "\n--- ESTADO FINAL ---" << std::endl;
        std::cout << important << std::endl;
        std::cout << simple << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Excepción crítica: " << e.what() << std::endl;
    }

    return 0;
}