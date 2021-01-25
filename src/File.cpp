#include "File.h"

#include <iostream>
#include <fstream>

File::File(std::string address)
{
    // Try to open the file
    // is possible to open the file ? - Do it
    // if not - create one
    std::ifstream file(address);
    file.exceptions( std::ifstream::badbit );
    if(file.fail()){
        // if I can't open the db file, I will create one then.
        file.close();
        std::ofstream new_file("db.csv");
        // Create a new db file with:
        // id, name, description, qtd, price
        new_file << "id," << "name," << "desc," << "qtd," << "price" << "\n";
        new_file.close();
    }   
}

File::~File()
{
}
