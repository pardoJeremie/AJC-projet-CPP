//
//  contact.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <sstream>
#include <iomanip>
#include <cctype>
#include "contact.hpp"

bool strcontainnumber (std::string);

contact::contact (unsigned int id, std::string firstname, std::string lastname, enumgender gender) {
    this->id = id;
    setfirstname(firstname);
    setlastname(lastname);
    this->gender = gender;
}

std::string contact::tostringwho () const {
    std::ostringstream oss;
    oss << tostringgender() << ". " << lastname << " " << firstname;
    return oss.str();
}

std::string contact::tostringid () const {
    std::ostringstream oss;
    oss << std::setw(5) << std::setfill('0') << id;
    return oss.str();
}

std::string contact::tostringgender () const {
    if (gender == enumgender::M)
        return "M";
    return "F";
}

void contact::setfirstname (std::string firstname) {
    if (firstname.size() > NAME_MAX_SIZE)
        throw std::invalid_argument("invalid argument in contact creation: first name is to large!");
    
    if (strcontainnumber(firstname))
        throw std::invalid_argument("invalid argument in contact creation: first name contain numerical!");
    
    if (firstname.size() > 0) {
        firstname.at(0) = toupper(firstname.at(0));
        for ( std::string::iterator it=firstname.begin()+1; it!=firstname.end(); ++it)
            *it = tolower(*it);
    }

    this->firstname = firstname;
}

void contact::setlastname (std::string lastname) {
    if (lastname.size() > NAME_MAX_SIZE)
        throw std::invalid_argument("invalid argument in contact creation: last name is too large!");
    
    if (strcontainnumber(lastname))
        throw std::invalid_argument("invalid argument in contact creation: last name contain numerical!");
    
    for ( std::string::iterator it=lastname.begin(); it!=lastname.end(); ++it)
        *it = toupper(*it);
    this->lastname = lastname;
}


std::ostream& operator<< (std::ostream& os, const contact& objcontact) {
    os << objcontact.tostring();
    return os;
}

bool strcontainnumber (std::string s) {
    return std::find_if(s.begin(), s.end(), ::isdigit) != s.end();
}
