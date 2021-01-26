# pragma once

#include <iostream>
#include <fstream>
#include <vector>

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
    can be added later, for now this simple menu will work.
    
    Talvez isso sirva apenas para controle do estoque, sei la.*/
private:
    std::ifstream my_file;   
    std::string my_addr; 
public:

    Utilities(std::string addr):File(addr){
        // Here I'm sure that db file exists.
        my_file.open(addr);
        my_addr = addr;
    };
    ~Utilities();

    std::vector<std::string> read_file(void); 
    void print_vector(void);
    void print_any(void);
    void closing_file(std::ifstream& file);
    void closing_file(std::fstream& file);

    bool make_menu(void); // create a menu for us
};

