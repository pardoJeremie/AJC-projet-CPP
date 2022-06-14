//
//  menufunctions.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 14/06/2022.
//

#include <vector>
#include "menufunctions.hpp"
#include "contact.hpp"
#include "address.hpp"
#include "date.hpp"
#include "privatecontact.hpp"
#include "professionalcontact.hpp"

void submenuselectall (sqlite3*);
void submenuselectprivate (sqlite3*);
void submenuselectprofessional (sqlite3*);

void submenuselectbylastname (sqlite3*);
void submenuselectbytown (sqlite3*);

void submenuadd (sqlite3*);
void submenudelete (sqlite3*);

bool quitmenu ();

void printresult(std::vector<contact*>);

privatecontact* subsubmenucreationprivatecontact ();
professionalcontact* subsubmenucreationprofessionalcontact ();


void mainmenu (sqlite3* db) {
    bool stoploop = false;
    int selection;
    while (!stoploop) {
        std::cout << "MENU DE SELECTION:\n\t1. Lister les contacts privés et professionnels \n\t2. Lister les contacts privés \n\t3. Lister les contacts professionnels \n\t4. Lister les contacts par nom\n\t5. Lister les contacts par ville\n\t6. Ajouter un contact\n\t7. Supprimer un Contact via son identifiant\n\t8. Quitter\n\t\tvotre choix: ";
        std::cin >> selection;
        if(!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selection = 0;
        }
        std::cout << std::endl;
        switch (selection) {
            case 1:
                submenuselectall(db);
                break;
            case 2:
                submenuselectprivate(db);
                break;
            case 3:
                submenuselectprofessional(db);
                break;
            case 4:
                submenuselectbylastname(db);
                break;
            case 5:
                submenuselectbytown(db);
                break;
            case 6:
                submenuadd(db);
                break;
            case 7:
                submenudelete(db);
                break;
            case 8:
                stoploop = quitmenu();
                break;
            default:
                std::cout << "\tMauvaise entrée!\n\n";
                break;
        }
    }
}

void submenuselectall (sqlite3* db) {
    std::vector<contact*> contacts = sqliteselect(db);
    printresult(contacts);
}
void submenuselectprivate (sqlite3* db) {
    std::vector<contact*> contacts = sqliteselect(db, "where entreprise is null");
    printresult(contacts);
}
void submenuselectprofessional (sqlite3* db) {
    std::vector<contact*> contacts = sqliteselect(db, "where entreprise is not null");
    printresult(contacts);
}

void submenuselectbylastname (sqlite3* db) {
    std::string str;
    std::cout << "\tvotre choix de nom: ";
    std::cin >> str;
    std::cout << std::endl;
    for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
        *it = toupper(*it);
    std::vector<contact*> contacts = sqliteselect(db, "where nom = '"+ str +"'");
    printresult(contacts);
}
void submenuselectbytown (sqlite3* db) {
    std::string str;
    std::cout << "\tvotre choix de ville: ";
    std::cin >> str;
    std::cout << std::endl;
    for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
        *it = toupper(*it);
    std::vector<contact*> contacts = sqliteselect(db, "where ville = '"+ str +"'");
    printresult(contacts);
}

void submenuadd (sqlite3* db) {
    contact* pcontact = nullptr;
    try {
        char c;
        std::cout << "\tVoulez-vous ajouter un contact privé? [O/N] ";
        std::cin >> c;
        if(c == 'O' || c == 'o')
            pcontact = subsubmenucreationprivatecontact();
        else {
            std::cout << "\tVous ajoutez un contact professionnel.\n";
            pcontact = subsubmenucreationprofessionalcontact();
        }
        sqliteadd (db, pcontact);
        std::cout << "\tContact ajouté!\n";
        
    } catch (std::invalid_argument  exp) {
        std::cout << exp.what() << std::endl;
        if (pcontact != nullptr)
            delete pcontact;
    }
    std::cout << std::endl;
}
void submenudelete (sqlite3* db) {
    unsigned int id;
    std::cout << "\tvotre choix d'identifiant: ";
    std::cin >> id;
    while (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\tL'entrée n'est pas un entier! Votre d'identifiant:";
        std::cin >> id;
    }
    std::cout << "\tsuppression de l'élément ayant l'identifiant: "+ std::to_string(id) +"!\n\n";
    sqlitedelete (db, id);
}

bool quitmenu () {
    char c;
    std::cout << "\tÊtes-vous sûr de vouloir effectuer cette action? [O/N] ";
    std::cin >> c;
    if(c == 'O' || c == 'o')
        return true;
    return false;
}

void printresult(std::vector<contact*> contacts) {
    std::cout << "---Liste des résultats----\n\n";
    for(auto& el : contacts)
    if (el != nullptr) {
        std::cout << *el;
        delete el;
    }
    std::cout << "--------------------------\n\n";
}

privatecontact* subsubmenucreationprivatecontact () {
    privatecontact* pprivatecontact = nullptr;
    
    /*constact*/
    std::string firstname, lastname;
    enumgender gender;
    /*add*/
    address* addpostal = nullptr;
    /*date*/
    date* birthdate = nullptr;
    try {
        addpostal =  new address (13,"rue des moignons","",97018,"pirate town");
        birthdate = new date (40,6,2000);
    } catch (std::invalid_argument  exp) {
        if (addpostal != nullptr)
            delete addpostal;
        if (birthdate != nullptr)
            delete birthdate;
        throw std::invalid_argument(exp.what());
    }
    pprivatecontact = new privatecontact (0,"roberts","bartholomew", enumgender::M, addpostal, birthdate);
    return pprivatecontact;
}
professionalcontact* subsubmenucreationprofessionalcontact (){
    professionalcontact* pprofessionalcontact = nullptr;
    
    /*constact*/
    std::string firstname, lastname;
    enumgender gender;
    /*add*/
    address* addcompany = nullptr;
    try {
        addcompany =  new address (13,"rue des moignons","",97018,"pirate town");
    } catch (std::invalid_argument  exp) {
        if (addcompany != nullptr)
            delete addcompany;
        throw std::invalid_argument(exp.what());
    }
    /*professional*/
    std::string companyname, email;
    
    pprofessionalcontact = new professionalcontact (0,"jorge","Grotadmorv", enumgender::M, addcompany,"Le Roy du recyclage","jorge.Gotadmorv.192@gmail.com");
    return pprofessionalcontact;
}
