#include "File.h"

#include <iostream>
#include <fstream>
#include<vector>
File::File(){}

File::File(std::string address, size_t num_colunas)
{   
    
    // Try to open the file
    // is possible to open the file ? - Do it
    // if not - create one
    // o parameetro address contém endereço/nome do arquivo.
    std::ifstream file(address);
    file.exceptions( std::ifstream::badbit );
    if(file.fail()){
        // if I can't open the any file, I will create one then.
        // Agora é o user que define quantas colunas serão criadas
        // e quais serão os seus nomes.
        // Isso possibilita usar essa classe como base para outras
        // criando os arquivos que a gente precisar, com o formato
        // específico para cada necessidade que aparecer no código.
        std::string texto;
        std::vector<std::string> nome_das_colunas;
        for (size_t i = 0; i < num_colunas; i++)
        {
            std::cout << "Nome da " << i << " coluna" << "\n";
            std::cin >> texto; // Pega o texto da i-ésima coluna
            nome_das_colunas.push_back(texto); // coluna do texto no vetor de strings.
        }
    
        file.close();
        std::ofstream new_file(address);
        
        // Coloca os nomes das colunas no arquivo de nome address
        for (size_t i = 0; i < num_colunas; i++)
        {
            new_file << nome_das_colunas[i] << ",";
        }
        new_file << "\n";
        new_file.close();
    }   
}

File::~File()
{
}
