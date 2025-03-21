#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::string formatField(std::string field) const;

public:
    void setContact();
    void displayShort(int index) const;
    void displayFull() const;
};


#endif