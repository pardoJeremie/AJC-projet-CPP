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
#define EMAIL_MAX_SIZE 250

class professionalcontact : public contact {
public:
    professionalcontact (/*contact*/ unsigned int, std::string, std::string, enumgender,/*add*/ address*,/*private*/ std::string, std::string);
    ~professionalcontact ();
    
    std::string tostring() const override;
    std::string tostringlibelle() const {return addcompany->tostringlibelle();}
    std::string tostringpostalcode() const {return addcompany->tostringpostalcode();}
    std::string getcomplement() const {return addcompany->getcomplement();}
    std::string gettown() const {return addcompany->gettown();}
    std::string getcompanyname() const {return companyname;}
    std::string getemail() const {return email;}
    
    void setcompanyname (std::string);
    void setemail (std::string);
    
private:
    
    std::string companyname;
    address* addcompany = nullptr;
    std::string email;
};

#endif /* professionalcontact_hpp */
