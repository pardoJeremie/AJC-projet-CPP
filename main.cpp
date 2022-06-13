//
//  main.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <iostream>
//#include <sqlite3.h>
#include "contact.hpp"
#include "address.hpp"
#include "date.hpp"

int main(int argc, const char * argv[]) {
    
    //std::cout << "sqlite3 version " << sqlite3_libversion() << std::endl;
    contact* a = nullptr;
    try {
        a = new contact ("Aaa","AAA", enumgender::M);
    }catch ( std::invalid_argument exp) {
        std::cout << "Errer in init contact: " << exp.what() << std::endl;
        delete a;
        a = nullptr;
    }
    if (a != nullptr)
        std::cout << "id: "<< a->tostringid () << "\n  name: "<< a->tostringwho () << std::endl;
    
    
    
    address* add = nullptr;
    try {
        add = new address (13,"rue du des moignons","",97018,"pirate town");
    }catch ( std::invalid_argument exp) {
        std::cout << "Errer in init address: " << exp.what() << std::endl;
        delete add;
        add = nullptr;
    }
    if (add != nullptr) {
        std::cout << add->tostringlibelle();
        if (add->getcomplement() != "")
            std::cout << ", " << add->getcomplement();
        std::cout<< std::endl << add->tostringpostalcode() << " " << add->gettown() << std::endl ;
    }
    
    date* d = nullptr;
    try {
        d = new date (1,6,2022);
    }catch ( std::invalid_argument exp) {
        std::cout << "Errer in init date: " << exp.what() << std::endl;
        delete d;
        d = nullptr;
    }
    if (d != nullptr) {
        std::cout << d->tostring() << std::endl ;
    }
    
    return 0;
}
