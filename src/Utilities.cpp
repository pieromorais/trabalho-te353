#include <iostream>
#include <sstream>
#include "Utilities.h"

Utilities::~Utilities()
{
}

bool Utilities::make_menu(void) {
    // Simple menu for the our store.
    int option = 0;
        std::cout << "\n1 - Ler Estoque\n2 - Adicionar Produto\n"
        "3 - Fazer venda\n4 - Sair\n";
        std::cout << "Opcao: ";
        std::cin >> option;
        fflush(stdout);
        switch (option)
        {
        case 1:
            this->print_vector(); // read the file
            return false; // Maintain the loop.
            break;
        case 2:
            this->print_any();
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

std::vector<std::string> Utilities::read_file(void){
          
    /// Esse método lê o arquivo depois cria e retorna
    // um vetor de strings que pode ser imprimida na tela 
    // da maneira que a gente quiser.
    // A professora pediu algo bonitinho, mas eu sei lá.
    std::ifstream file(this->my_addr, std::ios::in); // Open the file again :/

    if(!file.is_open()) throw std::runtime_error(
        "Nao foi possivel abrir o arquivo"
    ); // caso não seja possível abrir o arquvio por algum motivo
    // mas em tese a class File garante que ele estará aberto

    // O que vai retornar
    std::vector<std::string> result; // Cria o vetor de strings que será retornado

    while (!file.eof())
    {
        std::string line; 
        std::getline(file, line); // pega uma linha por vez

        std::stringstream ss(line); // cria um stream de char que podem,
        // ser separados

        std::string cell; // Valor da celula
        while (std::getline(ss, cell, ',')) // pega a stringstream e separa
        // ","
        {
            result.push_back(cell);
        }        
    }    

    this->closing_file(file);
    return result;
}

void Utilities::print_vector(void){
    // Para testar
    std::vector<std::string> resultado;

    resultado = this->read_file();
    size_t count = 0;
    for(size_t i = 0; i < resultado.size(); i++){
        std::cout << resultado[i] << "\t";
        count++;
        if (count == 5)
        {
            std::cout << "\n";
        }
        
    }
}

void Utilities::print_any(void){
    std::cout << "hello world" << "\n";
}

void Utilities::closing_file(std::ifstream& file){
    // to close files.
    file.close();
}

void Utilities::closing_file(std::fstream& file){
    // to close other files
    file.close();
}