//
//  contact.hpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#ifndef contact_hpp
#define contact_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#define NAME_MAX_SIZE 30

enum class enumgender { F, M };

class contact {
public:
    contact (unsigned int, std::string, std::string, enumgender);
    virtual ~contact () {};
    
    
    virtual std::string tostring() const = 0;
    std::string tostringwho () const;
    std::string tostringid () const;
    std::string tostringgender () const;
    
    unsigned int getid () const {return id;}
    
    std::string getfirstname () const {return firstname;}
    void setfirstname (std::string);
    
    std::string getlastname () const {return lastname;}
    void setlastname (std::string);
    
    enumgender getgender () const {return gender;}

private:
    unsigned int id;
    std::string firstname;
    std::string lastname;
    enumgender gender;
};

std::ostream& operator<< (std::ostream&, const contact&);

#endif /* contact_hpp */
