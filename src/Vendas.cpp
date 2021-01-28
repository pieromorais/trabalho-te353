#include "Vendas.h"

void vendas(void){
    // Mesma lógica do main
    bool menu = false;
    while(!menu){
        menu = menu_vendas();
    }
}

bool menu_vendas(void){
    // Menu para lidar com a parte de vendas da
    // loja de informática
    size_t opcao = 0;
    std::cout << "1 - Softwares\n2 - Pecas\n3 - Maquinas\n4 - Voltar\n";
    std::cin >> opcao;
    switch (opcao)
    {
    case 1:
        std::cout << "Softwares\n";
        return false;
        break;
    case 2:
        std::cout << "Pecas\n";
        return false;
        break;
    case 3:
        std::cout << "Maquinas\n";
        return false;
        break;    
    default:
        return true;
        break;
    }
}