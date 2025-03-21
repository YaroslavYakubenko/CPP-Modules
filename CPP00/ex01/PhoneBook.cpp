#include "Phonebook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact() {
    static int index = 0;

    contacts[index % 8].setContact();
    if (contactCount < 8)
        contactCount++;
    index++;
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << "___________________________________________" << std::endl;
    std::cout << "|    Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "___________________________________________" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        contacts[i].displayShort(i);
    }

    std::cout << "Enter index: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= contactCount) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contacts[index].displayFull();
}