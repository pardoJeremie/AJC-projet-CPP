//
//  sqlitefunctions.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include "sqlitefunctions.hpp"

sqlite3* sqliteopen (std::string dbpath) {
    sqlite3* db;
    if (sqlite3_open(dbpath.c_str(), &db) != SQLITE_OK) {
        std::cout << "ERREUR during opening of the db : " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }
    return db;
}

bool sqliteclose (sqlite3* db) {
    if (sqlite3_close(db) != SQLITE_OK) {
       std::cout << "ERREUR during clossing of the db : " <<  sqlite3_errmsg(db) << std::endl;
      return false;
   }
    return true;
}

void sqliteselect (sqlite3* db, std::string str) {
    sqlite3_stmt *stmt;
    std::string requet = "select * from contacts " + str + ";";
    sqlite3_prepare_v2(db,requet.c_str(),-1,&stmt, NULL);
    
    while ( sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << sqlite3_column_int(stmt, 0) <<  "," << sqlite3_column_text(stmt, 1) <<  ","   << sqlite3_column_text(stmt, 2) <<  "," << sqlite3_column_text(stmt, 3) << std::endl;
    }
    sqlite3_finalize(stmt);
}

void sqliteadd (sqlite3*, contact*) {}

void sqlitedelete (sqlite3*, unsigned int) {}

