#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main() {
    std::srand(std::time(NULL)); // Semilla para el 50% de robotomía

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 140);
        
        ShrubberyCreationForm f1("Garden");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Criminal");

        std::cout << "\n--- SHRUBBERY TEST ---" << std::endl;
        boss.signForm(f1);
        intern.executeForm(f1); // Fallará por grado (140 > 137)
        boss.executeForm(f1);   // Funcionará

        std::cout << "\n--- ROBOTOMY TEST ---" << std::endl;
        boss.signForm(f2);
        boss.executeForm(f2);   // 50% probabilidad éxito

        std::cout << "\n--- PARDON TEST ---" << std::endl;
        // intern.executeForm(f3); // Fallará (no firmada)
        boss.signForm(f3);
        boss.executeForm(f3);

    } catch (std::exception &e) {
        std::cout << "Main error: " << e.what() << std::endl;
    }
    return 0;
}