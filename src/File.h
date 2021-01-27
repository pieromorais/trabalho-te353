#pragma once

#include <iostream>
#include <fstream>
class File
{
    /* The first and only thing that this class do 
    is to create a db.csv file if it does not exist
    
    The new file has the follow fields:
    id - product identifier (unique)
    name - name of the product
    desc - description of the product
    qtd - how many of each product do we have in our storage
    price - unity price for each piece
    
    This class will be the parent for the other ones that will handle
    reading and writing and other stuff.*/
public:
    File();
    File(std::string address, size_t num_colunas);
    ~File();

    // external methods
    void close_file(void);
};

