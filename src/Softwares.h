#pragma once

#include <iostream>

#include"Utilities.h"

class Softwares : public Utilities
{
    /*Essa classe irá lidar com a vendas de software
    da loja de info. Ela é filha de utilities, pois
    queremos criar, ler e alterar arquivos de bancos
    de dados (arquivos csv) que contenham os programas*/
private:
    /* data */
public:
    Softwares(std::string addr, size_t num_colunas, std::string nome_tela) : Utilities(addr, num_colunas, nome_tela){
    
    }
    ~Softwares();
};
