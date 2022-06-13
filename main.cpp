//
//  main.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <iostream>
//#include <sqlite3.h>
#include "contact.hpp"

int main(int argc, const char * argv[]) {
    
    //std::cout << "sqlite3 version " << sqlite3_libversion() << std::endl;
    contact* a = nullptr;
    try {
        a = new contact ("Aaa","AAA", enumgender::M);
        std::cout << "creation of a contact"<< std::endl;
    }catch ( std::invalid_argument exp) {
        std::cout << "Errer in init contact: " << exp.what() << std::endl;
        delete a;
        a = nullptr;
        std::cout << "the contact was not created"<< std::endl;
    }
    
    if (a != nullptr)
        std::cout << "id: "<< a->tostringid () << "\n  name: "<< a->tostringwho () << std::endl;
    
    
    return 0;
}
