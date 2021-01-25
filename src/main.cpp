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

int main(int argc, char* argv[]){
    
    bool menu = false;
    Utilities utils;

    while(!menu){
        File file("db.csv");
        menu = utils.make_menu();
    }
    
    return 0;
}