//
//  privatecontact.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <sstream>
#include "privatecontact.hpp"

privatecontact::privatecontact (/*constact*/ unsigned int id, std::string firstname, std::string lastname, enumgender gender,/*add*/ address* addpostal,/*date*/ date* birthdate) : contact (id, firstname, lastname, gender) {
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
    std::ostringstream oss;
    oss << "Particulier : " << tostringid() << "\n\n\t" << tostringwho() << "\n\t" << addpostal->tostringlibelle() << "\n\t" << addpostal->tostringpostalcode() << " " << addpostal->gettown() << "\n\tAge : " << birthdate->getage() << " ans";
    if(birthdate->isbirthday())
        oss << " et Bon Anniversaire !";
    oss << "\n\n";
    return oss.str();
}
