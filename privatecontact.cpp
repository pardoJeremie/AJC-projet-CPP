//
//  privatecontact.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include "privatecontact.hpp"

privatecontact::privatecontact (/*constact*/ std::string firstname, std::string lastname, enumgender gender,/*add*/ address* addpostal,/*date*/ date* birthdate) : contact (firstname, lastname, gender) {
    this->addpostal = addpostal;
    this->birthdate = birthdate;
}
privatecontact::~privatecontact () {
    if (addpostal != nullptr)
        delete addpostal;
    if (birthdate != nullptr)
        delete birthdate;
}

std::string privatecontact::tostring() const {
    return "private contact";
}
