//
//  date.hpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#ifndef date_hpp
#define date_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

class date {
public:
    date(unsigned short, unsigned short, unsigned short);
    ~date () {}
    
    bool isbirthday ();
    
    unsigned short getage () const;
    std::string tostring () const;
    std::string tostringsql () const;
    
private:
    void asgoodformat ();
    bool asgooddayformat ();
    
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

#endif /* date_hpp */
