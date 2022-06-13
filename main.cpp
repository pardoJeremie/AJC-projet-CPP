//
//  main.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <iostream>
#include <vector>
#include "contact.hpp"
#include "privatecontact.hpp"
#include "professionalcontact.hpp"
#include "address.hpp"
#include "date.hpp"
#include "sqlitefunctions.hpp"

int main(int argc, const char * argv[]) {
    try {
        sqlite3* db = sqliteopen ("dbContacts.db");
        
        std::vector<contact*> contacts = sqliteselect(db);
    
        for(auto& el : contacts)
        if (el != nullptr) {
            std::cout << *el;
            delete el;
        }
        
        sqliteclose(db);
        
    } catch (std::invalid_argument  exp) {
        std::cout << exp.what() << std::endl;
    }
    
    return 0;
}



/*
contact* a = nullptr;
contact* b = nullptr;
try {
    a = new privatecontact (102,"roberts","bartholomew", enumgender::M, new address (13,"rue des moignons","",97018,"pirate town"), new date (13,6,2000));
}catch ( std::invalid_argument exp) {
    std::cout << "Errer in init private contact:\n  " << exp.what() << std::endl;
    delete a;
    a = nullptr;
}
try {
b = new professionalcontact (2890,"jorge","Grotadmorv", enumgender::M, new address (2,"rue des poubelles","",17120,"ordure ville"),"Le Roy du recyclage","jorge.Gotadmorv.192@gmail.com");
}catch ( std::invalid_argument exp) {
    std::cout << "Errer in init professional contact:\n  " << exp.what() << std::endl;
    delete b;
    b = nullptr;
}

if (a != nullptr) {
    std::cout << *a << std::endl;
    delete a;
}

if (b != nullptr) {
    std::cout << *b << std::endl;
    delete b;
}
*/
