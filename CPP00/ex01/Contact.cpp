#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setContact() {
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickName);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|" 
        << std::setw(10) << formatField(firstName) << "|"
        << std::setw(10) << formatField(lastName) << "|"
        << std::setw(10) << formatField(nickName) << std::endl;
}

std::string Contact::formatField(std::string field) const {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}