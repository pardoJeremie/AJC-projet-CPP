//
//  main.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <iostream>
#include "sqlitefunctions.hpp"
#include "menufunctions.hpp"

int main(int argc, const char * argv[]) {
    try {
        sqlite3* db = sqliteopen ("dbContacts.db");
        
        mainmenu (db);
        
        sqliteclose(db);
        
    } catch (std::invalid_argument  exp) {
        std::cout << exp.what() << std::endl;
    }
    
    return 0;
}
