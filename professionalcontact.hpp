//
//  professionalcontact.hpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#ifndef professionalcontact_hpp
#define professionalcontact_hpp

#include <stdio.h>
#include "contact.hpp"
#include "address.hpp"

#define COMPANY_NAME_MAX_SIZE 50
#define EMAIL_MAX_SIZE 50

class professionalcontact : public contact {
public:
    professionalcontact (/*contact*/std::string, std::string, enumgender,/*add*/ address*,/*private*/ std::string, std::string);
    ~professionalcontact ();
    
    std::string tostring() const override;
    std::string getlibelle() const {return addpostal->tostringlibelle();}
    std::string getpostalcode() const {return addpostal->tostringpostalcode();}
    std::string getcomplement() const {return addpostal->getcomplement();}
    std::string gettown() const {return addpostal->gettown();}
    
    void setcompanyname (std::string);
    void setemail (std::string);
    
private:
    
    std::string companyname;
    address* addpostal = nullptr;
    std::string email;
};

#endif /* professionalcontact_hpp */
