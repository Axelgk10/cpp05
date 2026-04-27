#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkRequirements(executor);

    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Could not open file for writing");

    file << "         _-_\n"
         << "      /~~   ~~\\\n"
         << "   /~~         ~~\\\n"
         << "  {               }\n"
         << "   \\  _-     -_  /\n"
         << "     ~  \\ //  ~\n"
         << "    _~ -_|_-_ ~\n"
         << "      ~ - ~ -\n"
         << "\n"
         << "        _-_\n"
         << "     /~~   ~~\\\n"
         << "  /~~         ~~\\\n"
         << " {               }\n"
         << "  \\  _-     -_  /\n"
         << "    ~  \\ //  ~\n"
         << "   _~ -_|_-_ ~\n"
         << "     ~ - ~ -\n"
         << "\n"
         << "       _-_\n"
         << "    /~~   ~~\\\n"
         << " /~~         ~~\\\n"
         << "{               }\n"
         << " \\  _-     -_  /\n"
         << "   ~  \\ //  ~\n"
         << "  _~ -_|_-_ ~\n"
         << "    ~ - ~ -\n";

    file.close();
}
