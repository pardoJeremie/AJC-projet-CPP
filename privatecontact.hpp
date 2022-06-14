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
    privatecontact (/*contact*/ unsigned int, std::string, std::string, enumgender,/*add*/ address*,/*date*/ date*);
    ~privatecontact ();
    
    std::string tostring() const override;
    std::string tostringbirthdate() const {return birthdate->tostring();}
    std::string tostringsqlbirthdate() const {return birthdate->tostringsql();}
    std::string tostringlibelle() const {return addpostal->tostringlibelle();}
    std::string tostringpostalcode() const {return addpostal->tostringpostalcode();}
    std::string getcomplement() const {return addpostal->getcomplement();}
    std::string gettown() const {return addpostal->gettown();}
    
private:
    address* addpostal = nullptr;
    date* birthdate = nullptr;
};

#endif /* privatecontact_hpp */
