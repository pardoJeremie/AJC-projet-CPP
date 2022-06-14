//
//  address.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <sstream>
#include <iomanip>
#include <iostream>
#include "address.hpp"

address::address (unsigned short number, std::string street, std::string complement, unsigned int postalcode, std::string town) {
    this->number = number;
    this->street = street;
    libelleasgoodformat ();
    
    setpostalcode (postalcode);
    setcomplement (complement);
    settown (town);
    
}

std::string address::tostringlibelle () const {
    std::ostringstream oss;
    oss << number << ", " << street;
    return oss.str();
}

std::string address::tostringpostalcode () const {
    std::ostringstream oss;
    oss << std::setw(5) << std::setfill('0') << postalcode;
    return oss.str();
}

void address::setpostalcode (unsigned int postalcode ) {
    if (postalcode < 1000 || 98000 <= postalcode)
        throw std::invalid_argument("invalid argument in address creation:postal code is not a valide on!");
    this->postalcode = postalcode;
}

void address::settown (std::string town) {
    if (town .size() > TOWN_MAX_SIZE)
        throw std::invalid_argument("invalid argument in address creation:town is too large!");
    for ( std::string::iterator it=town.begin(); it!=town.end(); ++it)
        *it = toupper(*it);
    this->town = town;
}

void address::setcomplement (std::string complement) {
    if (complement.size() > COMPLEMENT_MAX_SIZE)
        throw std::invalid_argument("invalid argument in address creation:complement is too large!");
    this->complement = complement;
}

void address::libelleasgoodformat () {
    std::string libelle = tostringlibelle();
    if (libelle.size() > LIBELLE_MAX_SIZE)
        throw std::invalid_argument("invalid argument in address creation: libelle is too large!");
}


