//
//  privatecontact.hpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#ifndef privatecontact_hpp
#define privatecontact_hpp

#include <stdio.h>
#include <string>
#include "contact.hpp"
#include "date.hpp"
#include "address.hpp"

class privatecontact : public contact {
public:
    privatecontact (/*contact*/std::string, std::string, enumgender, /*add*/ unsigned short, std::string, std::string ,unsigned int ,std::string,/*date*/unsigned short, unsigned short, unsigned short);
    ~privatecontact () {
        
    }
    
    std::string tostring();
    std::string getbirthdate() {return birthdate.tostring();}
    std::string getlibelle() {return addpostal.tostringlibelle();}
    std::string getpostalcode() {return addpostal.tostringpostalcode();}
    std::string getcomplement() {return addpostal.getcomplement();}
    std::string gettown() {return addpostal.gettown();}
    
private:
    address* addpostal = nullptr;
    date* birthdate = nullptr;
};

#endif /* privatecontact_hpp */
