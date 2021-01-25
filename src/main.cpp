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
int main(int argc, char* argv[]){
    
    bool menu = false;

    while(!menu){
        File file("db.csv");
        int option = 0;
        std::cout << "sair?\n1 - sim\n2 - nao\n";
        std::cin >> option;
        switch (option)
        {
        case 1:
            menu = true;
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}