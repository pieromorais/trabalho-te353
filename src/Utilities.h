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
    std::string my_addr; 

    size_t my_numero_colunas; // Isso impede que dois números de colunas sejam criados
public:

    Utilities(std::string addr, size_t num_colunas, std::string nome_tela):File(addr, num_colunas, nome_tela){
        // Here I'm sure that db file exists.
        my_addr = addr;
        my_numero_colunas = num_colunas;
    };
    ~Utilities();

    std::vector<std::string> read_file(void); 
    void output_from_csv(void); // recebe o número de colunas
    void adicionar_ao_arquivo(void);
    void closing_file(std::ifstream& file);
    void closing_file(std::ofstream& file);
    void closing_file(std::fstream& file);

};

