//
//  sqlitefunctions.hpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#ifndef sqlitefunctions_hpp
#define sqlitefunctions_hpp

#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
#include <vector>
#include "contact.hpp"

sqlite3* sqliteopen (std::string);
void sqliteclose (sqlite3*);

std::vector<contact*> sqliteselect (sqlite3*, std::string = "");
void sqliteadd (sqlite3*, contact*);
void sqlitedelete (sqlite3*, unsigned int);

#endif /* sqlitefunctions_hpp */
