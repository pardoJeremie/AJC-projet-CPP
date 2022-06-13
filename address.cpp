//
//  address.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <sstream>
#include <iomanip>
#include "address.hpp"
#include <iostream>

address::address (unsigned short number, std::string street, std::string complement, unsigned int postalcode, std::string town) {
    this->number = number;
    this->street = street;
    this->complement = complement;
    this->postalcode = postalcode;
    this->town = town;
    
    asgoodformat ();
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

void address::asgoodformat () {
    
    std::string libelle = tostringlibelle();
    
    if (libelle.size() > LIBELLE_MAX_SIZE)
        throw std::invalid_argument("invalid argument in address creation: libelle is too large!");
    
    if (postalcode < 1000 || 98000 <= postalcode)
        throw std::invalid_argument("invalid argument in address creation:postal code is not a valide on!");
    
    if (complement.size() > COMPLEMENT_MAX_SIZE)
        throw std::invalid_argument("invalid argument in address creation:complement is too large!");
    
    if (town .size() > TOWN_MAX_SIZE)
        throw std::invalid_argument("invalid argument in address creation:town is too large!");
    
}
