#include "Vendas.h"
#include "Utilities.h"
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
    // O standart do cpp não permite que eu declare isso localmente
    // por isso a repetição
    // link -> https://stackoverflow.com/questions/11578936/getting-a-bunch-of-crosses-initialization-error
    bool menu1 = false;
    bool menu2 = false;
    bool menu3 = false;
    switch (opcao)
    {
    case 1:
        while(!menu1)
        {
            Softwares obj_soft("db_soft.csv", 5, "Software");
            menu1 = menu_interno("Softwares", obj_soft);
        }
        return false;
        break;
    case 2:
        while (!menu2)
        {
            Pecas obj_pecas("db_pecas.csv", 5, "Pecas");
            menu2 = menu_interno("Pecas", obj_pecas);
        }
        
        return false;
        break;
    case 3:
        while(!menu3)
        {
            Maquinas obj_maquinas("db_maquinas.csv", 5, "Maquinas");
            menu3 = menu_interno("Maquinas", obj_maquinas);
        }
        return false;
        break;    
    default:
        return true;
        break;
    }
}

bool menu_interno(std::string nome_do_menu, Softwares obj){
    // Menu interno para a parte de vendas (softwares)
    std::cout << nome_do_menu << "\n";
    size_t opcao = 0;
    std::cout << "1 - Checar Estoque\n2 - Fazer Venda\n3 - Adicionar Produto\n" <<
    "4 - Repor Estoque\n5 - Voltar\n";
    std::cin >> opcao;
    switch (opcao)
    {
    case 1:
        obj.output_from_csv();
        return false;
        break;
    case 2:
        obj.venda_de_artigos();
        return false;
        break;
    case 3:
        obj.adicionar_ao_arquivo();
        return false;
        break;
    case 4:
        obj.repor_artigos();
        return false;
        break;
    default:
        return true;
        break;
    }
}

bool menu_interno(std::string nome_do_menu, Pecas obj){
    // Menu interno para a parte de vendas (softwares)
    std::cout << nome_do_menu << "\n";
    size_t opcao = 0;
    std::cout << "1 - Checar Estoque\n2 - Fazer Venda\n3 - Adicionar Produto\n" <<
    "4 - Repor Estoque\n5 - Voltar\n";
    std::cin >> opcao;
    switch (opcao)
    {
    case 1:
        obj.output_from_csv();
        return false;
        break;
    case 2:
        obj.venda_de_artigos();
        return false;
        break;
    case 3:
        obj.adicionar_ao_arquivo();
        return false;
        break;
    case 4:
        obj.repor_artigos();
        return false;
        break;
    default:
        return true;
        break;
    }
}

bool menu_interno(std::string nome_do_menu, Maquinas obj){
    // Menu interno para a parte de vendas (softwares)
    std::cout << nome_do_menu << "\n";
    size_t opcao = 0;
    std::cout << "1 - Checar Estoque\n2 - Fazer Venda\n3 - Adicionar Produto\n" <<
    "4 - Repor Estoque\n5 - Voltar\n";
    std::cin >> opcao;
    switch (opcao)
    {
    case 1:
        obj.output_from_csv();
        return false;
        break;
    case 2:
        obj.venda_de_artigos();
        return false;
        break;
    case 3:
        obj.adicionar_ao_arquivo();
        return false;
        break;
    case 4:
        obj.repor_artigos();
        return false;
        break;
    default:
        return true;
        break;
    }
}


