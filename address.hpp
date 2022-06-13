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
#define LIBELLE_MAX_SIZE 50
#define COMPLEMENT_MAX_SIZE 50
#define TOWN_MAX_SIZE 50

class address {
public:
    address (unsigned short, std::string, std::string ,unsigned int ,std::string);
    ~address () {}

    std::string tostringlibelle();
    std::string tostringpostalcode();
    std::string getcomplement() {return complement;}
    std::string gettown() {return town;}
    
private:
    void asgoodformat ();
    
    unsigned short number;
    std::string street;
    std::string complement;
    unsigned int postalcode;
    std::string town;
};

#endif /* address_hpp */
