//
//  professionalcontact.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include "professionalcontact.hpp"
#include <regex>

professionalcontact::professionalcontact (/*constact*/ std::string firstname, std::string lastname, enumgender gender,/*add*/ address* addpostal,/*private*/ std::string companyname, std::string email) : contact (firstname, lastname, gender) {
    setcompanyname (companyname);
    setemail (email);
    this->addpostal = addpostal;
}

professionalcontact::~professionalcontact () {
    if (addpostal != nullptr)
        delete addpostal;
}

std::string professionalcontact::tostring() const {
    return "professional contact";
}

void professionalcontact::setcompanyname (std::string companyname) {
    if (companyname.size() > COMPANY_NAME_MAX_SIZE)
            throw std::invalid_argument("invalid argument in professional contact creation: company name is too large!");
    this->companyname = companyname;
}
void professionalcontact::setemail (std::string email ) {
    if (email.size() > EMAIL_MAX_SIZE)
            throw std::invalid_argument("invalid argument in professional contact creation: email is too large!");
    
    const std::regex pattern ("\\w+(\\.+\\w*)*@\\w+(\\.\\w+)+");// define a regular expression
    
    if (!std::regex_match(email, pattern)) // try to match the string with the regular expression
        throw std::invalid_argument("invalid argument in professional contact creation: email is not in the right format!");
    
    this->email = email;
}
