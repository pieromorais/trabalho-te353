#pragma once // Garante que só será compilado uma única vez.

#include <iostream>

#include "Softwares.h"
#include "Pecas.h"
#include "Maquinas.h"

void vendas(void);
bool menu_vendas(void);
// Overload the funções para o uso interno na parte de vendas
// da loja de informática
bool menu_interno(std::string nome_do_menu, Softwares obj);
bool menu_interno(std::string nome_do_menu, Pecas obj);
bool menu_interno(std::string nome_do_menu, Maquinas obj);


