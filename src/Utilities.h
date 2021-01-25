# pragma once

class Utilities
{
    /* This class will contain everything that we need
    to make thing pretty, which means that every piece
    of code that we don't know where to put it, has it place 
    right here.
    
    methods:
    menu - a simple menu with four options: Ler estoque,
    Adicionar produto, Fazer venda e sair. More features 
    can be added later, for now this simple menu will work.*/
private:
    /* data - Nothing*/
public:
    Utilities();
    ~Utilities();

    bool make_menu(void); // create a menu for us
};

