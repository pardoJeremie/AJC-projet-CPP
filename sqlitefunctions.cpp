//
//  sqlitefunctions.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <string>
#include "sqlitefunctions.hpp"
#include "privatecontact.hpp"
#include "professionalcontact.hpp"

sqlite3* sqliteopen (std::string dbpath) {
    sqlite3* db = nullptr;
    if (sqlite3_open(dbpath.c_str(), &db) != SQLITE_OK) {
        std::string errmsg = "ERREUR during the opening of the db : ";
        errmsg.append(sqlite3_errmsg(db));
        throw std::invalid_argument(errmsg);
    }
    return db;
}

void sqliteclose (sqlite3* db) {
    if (sqlite3_close(db) != SQLITE_OK) {
        std::string errmsg = "ERREUR during the clossing of the db : ";
        errmsg.append(sqlite3_errmsg(db));
        throw std::invalid_argument(errmsg);
   }
}

std::vector<contact*>  sqliteselect (sqlite3* db, std::string str) {
    sqlite3_stmt *stmt;
    std::string requet = "select * from contacts " + str + ";";
    sqlite3_prepare_v2(db,requet.c_str(),-1,&stmt, NULL);
    
    std::vector<contact*> contacts;
    
    while ( sqlite3_step(stmt) == SQLITE_ROW) {
        /*const char* gender to enumgender*/
        enumgender gender = enumgender::F;
        if (*sqlite3_column_text(stmt, 3) == 'M')
            gender = enumgender::M;
        
        /*for const char* codepostal to num codepostal*/
        std::string strcodepostal = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        
        /*in case const char* complement is empty*/
        std::string complement = "";
        const unsigned char* pcharcomplement = sqlite3_column_text(stmt, 6);
        if (pcharcomplement != nullptr)
            complement = reinterpret_cast<const char*>(pcharcomplement);
        
        /*for const char* libelle to num and rue*/
        std::string strlibelle = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        unsigned long libelleseparator = strlibelle.find(", ");
        
        if (sqlite3_column_text(stmt, 4) == nullptr) /*if stmt is a privatecontact*/{
            /*const char* string date to num year, month ,day */
            std::string strdate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
            unsigned long dateseparator1 = strdate.find("-");
            unsigned long dateseparator2 = strdate.find("-",dateseparator1+ 1);
            
            contacts.push_back (new privatecontact(sqlite3_column_int(stmt, 0), std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))), std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))), gender, new address(std::stoi(strlibelle.substr(0, libelleseparator)), strlibelle.substr( libelleseparator+2), complement, std::stoi(strcodepostal), std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)))), new date(std::stoi(strdate.substr(dateseparator2+1)), stoi(strdate.substr(dateseparator1+1, dateseparator2)), stoi(strdate.substr(0, dateseparator1)))));
        }
        else /*then stmt is a professionalcontact*/
            contacts.push_back (new professionalcontact(sqlite3_column_int(stmt, 0), std::string(reinterpret_cast<const char*>( sqlite3_column_text(stmt, 2))), std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))), gender, new address(std::stoi(strlibelle.substr(0, libelleseparator)), strlibelle.substr( libelleseparator+2), complement, std::stoi(strcodepostal), std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)))),  std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))), std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9)))));
    }
    sqlite3_finalize(stmt);
     
    return contacts;
}

void sqliteadd (sqlite3* db, contact* pcontact) {
    sqlite3_stmt *stmt;
    std::string requet = "insert into contacts ( nom, prenom, sexe, rue, cp, ville";
    std::string requetvalue = " values ('"+ pcontact->getlastname() + "', '" + pcontact->getfirstname() + "', '" + pcontact->tostringgender()+"'";
    
    privatecontact* pprivatecontact = dynamic_cast <privatecontact*> (pcontact);
    
    if (pprivatecontact != nullptr) {
        
        requet += ", dtnaissance";
        requetvalue += ", '" + pprivatecontact->tostringlibelle() + "', " + pprivatecontact->tostringpostalcode() + ", '" + pprivatecontact->gettown() + "', '" + pprivatecontact->tostringsqlbirthdate() + "'";
        
        if (pprivatecontact->getcomplement() == "") {
            requet += ", complement";
            requetvalue += ", '" + pprivatecontact->getcomplement() + "'";
        }
        
        requet += ")";
        requetvalue += ");";
    }
    else {
        
        professionalcontact* pprofessionalcontact = dynamic_cast <professionalcontact*> (pcontact);
        
        requetvalue += ", '" + pprofessionalcontact->tostringlibelle() + "', " + pprofessionalcontact->tostringpostalcode() + ", '" + pprofessionalcontact->gettown() + "', '" + pprofessionalcontact->getcompanyname() + "', '" + pprofessionalcontact->getemail() + "'";
        
        requet += ", entreprise, mail";
        if (pprofessionalcontact->getcomplement() != "") {
            requet += ", complement";
            requetvalue += ", '" + pprofessionalcontact->getcomplement() + "'";
        }
        
        requet += ")";
        requetvalue += ");";
    }
    
    requet += requetvalue;
    
    sqlite3_prepare_v2(db,requet.c_str(),-1,&stmt, NULL);
    sqlite3_step(stmt);
    
    sqlite3_finalize(stmt);
}

void sqlitedelete (sqlite3* db, unsigned int id) {
    sqlite3_stmt *stmt;
    std::string requet = "delete from contacts where idcontact = " +  std::to_string(id) + ";";
    
    sqlite3_prepare_v2(db,requet.c_str(),-1,&stmt, NULL);
    sqlite3_step(stmt);
    
    sqlite3_finalize(stmt);
}

