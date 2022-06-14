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
#include "sqlitefunctions.hpp"

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
        std::cout << "MENU DE SELECTION:\n\t1. Lister les contacts privés et professionnels \n\t2. Lister les contacts privés \n\t3. Lister les contacts professionnels \n\t4. Lister les contacts par nom\n\t5. Lister les contacts par ville\n\t6. Ajouter un contact\n\t7. Supprimer un Contact via son identifiant\n\t8. Quitter\n\t\tVotre choix: ";
        std::cin >> selection;
        if(!std::cin.good())
            selection = 0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cout << "\tVotre choix de nom: ";
    getline(std::cin, str);
    std::cout << std::endl;
    for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
        *it = toupper(*it);
    std::vector<contact*> contacts = sqliteselect(db, "where nom = '"+ str +"'");
    printresult(contacts);
}

void submenuselectbytown (sqlite3* db) {
    std::string str;
    std::cout << "\tVotre choix de ville: ";
    getline(std::cin, str);
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
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(c == 'O' || c == 'o')
            pcontact = subsubmenucreationprivatecontact();
        else {
            std::cout << "\tVous ajoutez un contact professionnel.\n";
            pcontact = subsubmenucreationprofessionalcontact();
        }
        sqliteadd (db, pcontact);
        std::cout << "\tContact ajouté!\n";
        
    } catch (std::invalid_argument exp) {
        std::cout << exp.what() << std::endl;
    }
    if (pcontact != nullptr)
        delete pcontact;
    std::cout << std::endl;
}

void submenudelete (sqlite3* db) {
    unsigned int id;
    std::cout << "\tVotre choix d'identifiant: ";
    std::cin >> id;
    while (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\tL'entrée n'est pas un entier! Votre d'identifiant:";
        std::cin >> id;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\tSuppression de l'élément "+ std::to_string(id) +"!\n\n";
    sqlitedelete (db, id);
}


bool quitmenu () {
    char c;
    std::cout << "\tÊtes-vous sûr de vouloir effectuer cette action? [O/N] ";
    std::cin >> c;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    
    std::cout << "\tnom: ";
    getline(std::cin, lastname);
    
    std::cout << "\tprenom: ";
    getline(std::cin, firstname);
    
    enumgender gender = enumgender::F;
    {
        char c;
        std::cout << "\tgenre? [M/F] ";
        std::cin >> c;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(c == 'M' || c == 'm')
            gender = enumgender::M;
    }
    
    /*address*/
    address* paddpostal = nullptr;
    std::string street, complement,town;
    unsigned int number, postalcode;
    
    std::cout << "\taddresse:\n\t\tnuméro: ";
    
    std::cin >> number;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tnuméro: ";
        std::cin >> number;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\t\true: ";
    getline(std::cin, street);
    
    {
        char c;
        std::cout << "\t\tVoulez-vous ajouter un complément? [O/N] ";
        std::cin >> c;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(c == 'O' || c == 'o') {
            std::cout << "\t\tcomplément: ";
            getline(std::cin, complement);
        }
    }
    
    std::cout << "\t\tcode postal: ";
    std::cin >> postalcode;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tcode postal: ";
        std::cin >> postalcode;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\t\tville: ";
    getline(std::cin, town);
    
    /*date*/
    date* pbirthdate = nullptr;
    unsigned short day, month,year;
    std::cout << "\tdate de naissance:\n\t\tjour: ";
     
    std::cin >> day;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tjour: ";
        std::cin >> day;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\t\tmois: ";
    std::cin >> month;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tmois: ";
        std::cin >> month;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\t\tannée: ";
    std::cin >> year;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tannée: ";
        std::cin >> year;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    /*creat contact*/
    try {
        paddpostal =  new address (number, street, complement, postalcode, town);
        pbirthdate = new date (day,month,year);
    } catch (std::invalid_argument exp) { //if birthdate creation fail addpostal is destroyed
        if (paddpostal != nullptr)
            delete paddpostal;
        if (pbirthdate != nullptr)
            delete pbirthdate;
        throw std::invalid_argument(exp.what());
    }
    pprivatecontact = new privatecontact (0, firstname, lastname, gender, paddpostal, pbirthdate);
    return pprivatecontact;
}

professionalcontact* subsubmenucreationprofessionalcontact (){
    professionalcontact* pprofessionalcontact = nullptr;
    
    /*constact* && professional*/
    std::string firstname, lastname,companyname, email;
    std::cout << "information contact:\n";
    std::cout << "\tnom: ";
    getline(std::cin, lastname);
    
    std::cout << "\tprenom: ";
    getline(std::cin, firstname);
    
    enumgender gender = enumgender::F;
    {
        char c;
        std::cout << "\tgenre? [M/F] ";
        std::cin >> c;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(c == 'M' || c == 'm')
            gender = enumgender::M;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cout << "\tmail: ";
    std::cin >> email;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\tnom entreprise: ";
    getline(std::cin, companyname);
    
    /*address*/
    address* paddcompany = nullptr;
    std::string street, complement, town;
    unsigned int number, postalcode;
    
    std::cout << "\taddresse:\n\t\tnuméro: ";
    
    std::cin >> number;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tnuméro: ";
        std::cin >> number;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\t\true: ";
    getline(std::cin, street);
    
    {
        char c;
        std::cout << "\t\tVoulez-vous ajouter un complément? [O/N] ";
        std::cin >> c;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(c == 'O' || c == 'o') {
            std::cout << "\t\tcomplément: ";
            getline(std::cin, complement);
        }
    }
    
    std::cout << "\t\tcode postal: ";
    std::cin >> postalcode;
    while(!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\t\tcode postal: ";
        std::cin >> postalcode;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "\t\tville: ";
    getline(std::cin, town);
    
    /*creat contact*/
    try {
        paddcompany =  new address (number, street, complement, postalcode, town);
    } catch (std::invalid_argument exp) {
        if (paddcompany != nullptr)
            delete paddcompany;
        throw std::invalid_argument(exp.what());
    }
    
    pprofessionalcontact = new professionalcontact (0, firstname, lastname, gender, paddcompany, companyname, email);
    return pprofessionalcontact;
}
