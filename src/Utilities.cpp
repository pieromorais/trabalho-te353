#include <iostream>
#include "Utilities.h"

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
            this->read_file(); // read the file
            return false; // Maintain the loop.
            break;
        case 2:
            return false;
            break;
        case 3:
        return false;
            break;
        default:
            // Will end if you miss an option.
            return true; // Get out of the loop.
            break;
        }
}

void Utilities::read_file(void){
    // Read the file and print it in the screen
    // pretty straight foward
    std::string text; // I need to put the string somewhere
    std::fstream file("db.csv", std::ios::in); // Open the file again :/

    while(!file.eof()){
        std::cout << char(file.get());
    }
    

    this->closing_file(file);
}

void Utilities::closing_file(std::ifstream& file){
    // to close files.
    file.close();
}

void Utilities::closing_file(std::fstream& file){
    // to close other files
    file.close();
}