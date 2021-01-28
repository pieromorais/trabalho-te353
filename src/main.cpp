/*trabalho te353
Loja de informática
Alunos:
Alysson
Eduardo
Felipe
Piero
Vinícius*/

#include<iostream>

#include "File.h"
#include "Utilities.h"
#include "Vendas.h"

bool main_menu(void);

int main(int argc, char* argv[]){
    
    bool menu = false; 
    while(!menu){        
        menu = main_menu();
    }
    
    return 0;
}

bool main_menu(void){
    // Menu para a loja de informatica
    // Isso pode ser mudado, eu estou meio sem ideias
    // de como fazer isso.
    size_t option = 0;
    std::cout << "\n1 - Vendas\n2 - Servicos\n"
    "\n3 - Sair\n";
    std::cout << "Opcao: ";
    std::cin >> option;
    
    switch (option)
    {
    case 1:
        vendas();
        return false; // Maintain the loop.
        break;
    case 2:
        return false;
        break;
    default:
        // Will end if you miss an option.
        return true; // Get out of the loop.
        break;
    }
}