#include <iostream>
#include <iomanip> // Permite manipular a saida de dados mais facilmente.
#include <sstream>
#include "Utilities.h"

Utilities::~Utilities()
{
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

    file.close();
    return result;
}

void Utilities::output_from_csv(void){
    // Esse método pretende criar outputs legais e gerais
    // que podem ser utilizadas por outras partes do
    // programa.
    // Parametros: 
    //              - num_col: número de colunas para saber onde pular
    // uma linha. Esse método supõe que os dados são retorna do método
    // read_file.
    std::vector<std::string> resultado;
    resultado = this->read_file();
    size_t counter = 0;
    for (
        std::vector<std::string>::iterator iter = resultado.begin(); 
        iter != resultado.end(); ++iter
        )
    {
        std::cout << *iter << std::setw(30);
        counter++;
        if (counter == this->my_numero_colunas)
        {
            std::cout << "\n";
            counter = 0;
        }                
    }    
}

void Utilities::adicionar_ao_arquivo(void){
    // Abrir arquivos e adicionar o que user 
    // quiser - mas será tratado como string
    //this->output_from_csv();

    std::ofstream file;
    file.open(this->my_addr, std::ios_base::app);

    if (file.is_open())
    {
        std::string nome_coluna;
        for (size_t i = 0; i < this->my_numero_colunas; i++)
        {
            std::cout << "Entre com a coluna " << i << "\n";
            // só para garantir
            fflush(stdin);
            setbuf(stdin, NULL);
            std::getline(std::cin, nome_coluna);
            // só para garantir
            fflush(stdin);
            setbuf(stdin, NULL);
            file << nome_coluna << ",";          
        }
        file << "\n";
    }else{
        // Em tese isso não vai acontecer pq eu forço
        // a criação de um arquivo caso ele não exista
        std::cerr << "Ruim\n" ;        
    }
     file.close();
}

void Utilities::closing_file(std::ifstream& file){
    // to close files.
    file.close();
}

void Utilities::closing_file(std::fstream& file){
    // to close other files
    file.close();
}

void Utilities::closing_file(std::ofstream& file){
    // to close another files
    file.close();
}