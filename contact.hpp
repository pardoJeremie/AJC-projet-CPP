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
    std::string tostringgender () const;
    
    unsigned int getid () const {return id;}
    std::string getfirstname () const {return firstname;}
    std::string getlastname () const {return lastname;}
    enumgender getgender () const {return gender;}

protected:
    std::string tostringwho () const;
    std::string tostringid () const;
    
private:
    void setfirstname (std::string);
    void setlastname (std::string);
    
    unsigned int id;
    std::string firstname;
    std::string lastname;
    enumgender gender;
};

std::ostream& operator<< (std::ostream&, const contact&);

#endif /* contact_hpp */
