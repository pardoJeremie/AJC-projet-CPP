//
//  address.hpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#ifndef address_hpp
#define address_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#define LIBELLE_MAX_SIZE 250
#define COMPLEMENT_MAX_SIZE 250
#define TOWN_MAX_SIZE 50

class address {
public:
    address (unsigned short, std::string, std::string ,unsigned int ,std::string);
    ~address () {}

    std::string tostringlibelle () const;
    std::string tostringpostalcode () const;
    std::string getcomplement () const {return complement;}
    std::string gettown () const {return town;}

private:
    void setpostalcode (unsigned int);
    void setcomplement (std::string);
    void settown (std::string);
    
    void libelleasgoodformat ();
    
    unsigned short number;
    std::string street;
    std::string complement;
    unsigned int postalcode;
    std::string town;
};

#endif /* address_hpp */
