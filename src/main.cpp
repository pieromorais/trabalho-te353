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
    
    bool menu = false; // Keep the menu going until true come in.
    Utilities utils("db.csv", 5); // Create an object

    while(!menu){        
        menu = utils.make_menu();
    }
    
    return 0;
}