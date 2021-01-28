#pragma once

#include <iostream>

#include "Utilities.h"

class Pecas : public Utilities
{
private:
    /* data */
public:
    Pecas(std::string addr, size_t num_col, std::string nome_tela) :
    Utilities(addr, num_col, nome_tela){};
    ~Pecas();   
    
};


