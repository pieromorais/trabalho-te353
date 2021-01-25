#include <iostream>
#include "Utilities.h"

Utilities::Utilities(/* args */)
{
    // Maybe something in the future
}

Utilities::~Utilities()
{
}

bool Utilities::make_menu(void) {
    // Simple menu for the our store.
    int option = 0;
        std::cout << "sair?\n1 - Ler Estoque\n2 - Adicionar Produto\n"
        "3 - Fazer venda\n4 - Sair\n";
        std::cout << "Opcao: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            return false;
            break;
        case 2:
            return false;
            break;
        case 3:
        return false;
            break;
        default:
            // Will end if you miss an option.
            return true;
            break;
        }
}
