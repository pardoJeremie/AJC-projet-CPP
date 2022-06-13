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
#define NAME_MAX_SIZE 30

enum class enumgender { F, M };

class contact {
public:
    contact (std::string, std::string, enumgender);
    ~contact () {}
    
    std::string tostringwho ();
    std::string tostringid ();
    
    unsigned int getid () {return id;}
    
    std::string getfirstname () {return firstname;}
    void setfirstname (std::string);
    
    std::string getlastname () {return lastname;}
    void setlastname (std::string);
    
    enumgender getgender () {return gender;}
    
    static void setidautoincrementation (unsigned int idinitial) {idautoincrementation = idinitial;}
private:
    unsigned int id;
    std::string firstname;
    std::string lastname;
    enumgender gender;
    static unsigned int idautoincrementation;
};

bool strcontainnumber (std::string);

#endif /* contact_hpp */
