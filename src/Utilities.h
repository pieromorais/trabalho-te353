# pragma once

#include <iostream>
#include <fstream>

#include "File.h"

class Utilities : public File
{
    /* This class will contain everything that we need
    to make thing pretty, which means that every piece
    of code that we don't know where to put it, has it place 
    right here.
    
    I change my mind, now this class heirds the File class and
    add some features.

    methods:
    menu - a simple menu with four options: Ler estoque,
    Adicionar produto, Fazer venda e sair. More features 
    can be added later, for now this simple menu will work.*/
private:
    std::ifstream my_file;    
public:

    Utilities(std::string addr):File(addr){
        // Here I'm sure that db file exists.
        my_file.open("db.csv");
    };
    ~Utilities();

    void read_file(void);
    void closing_file(std::ifstream& file);
    void closing_file(std::fstream& file);

    bool make_menu(void); // create a menu for us
};

