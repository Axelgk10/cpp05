/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:43:41 by axgimene          #+#    #+#             */
/*   Updated: 2026/04/14 19:16:50 by axgimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Test 1: Creación normal ---" << std::endl;
    try {
        Bureaucrat hercules("Hercules", 2);
        std::cout << hercules << std::endl;
        hercules.incrementGrade();
        std::cout << "After promotion: " << hercules << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grado demasiado alto (0) ---" << std::endl;
    try {
        Bureaucrat god("God", 0);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grado demasiado bajo (151) ---" << std::endl;
    try {
        Bureaucrat slave("Slave", 151);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Incremento fuera de rango ---" << std::endl;
    try {
        Bureaucrat top("TopManager", 1);
        std::cout << top << std::endl;
        top.incrementGrade(); // Esto lanzará excepción
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    return 0;
}