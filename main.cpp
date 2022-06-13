//
//  main.cpp
//  AJC projet C++
//
//  Created by pardo jérémie on 13/06/2022.
//

#include <iostream>
#include <sqlite3.h>

int main(int argc, const char * argv[]) {
    
    std::cout << "sqlite3 version " << sqlite3_libversion() << std::endl;
    
    return 0;
}
