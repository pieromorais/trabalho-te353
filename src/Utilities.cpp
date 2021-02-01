#include <iostream>
#include <iomanip> // Permite manipular a saida de dados mais facilmente.
#include <string>
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
    // Adicionar outro laço for para verificar a
    // quantidade de produtos no estoque
    std::cout << "\n\n";
    

    std::ifstream file(this->my_addr);
    if(file.is_open())
    {
        std::string line;
        std::getline(file, line);

        std::stringstream ss(line);
        std::string cell;

        size_t counter = 0;
        // Quero verificar se as colunas são as que eu quero
        // caso, contrário quero continuar pq não tem nada que 
        // eu possa fazer

        while(std::getline(ss, cell, ','))
        {
            if(
                cell == "id" || cell == "nome" || cell == "desc" || cell == "qtd" || cell == "preco"
            ){ counter++; }
        }
        struct sDados
        {
            std::string id;
            std::string nome;
            int qtd;
        };
        std::vector<sDados> dados;
        if (counter == 5) {
            
            sDados aux;
            while (std::getline(file, line))
            {
                std::stringstream sstring(line);
                std::string catch_cell;
                
                // pegar o id
                std::getline(sstring, catch_cell, ',');
                aux.id = catch_cell;
                // pegar o nome
                std::getline(sstring, catch_cell, ',');
                aux.nome = catch_cell;
                // pular desc
                std::getline(sstring, catch_cell, ',');
                // pegar qtd e converter para int
                std::getline(sstring, catch_cell, ',');
                aux.qtd = atoi(catch_cell.c_str());
                // só para garantir
                std::getline(sstring, catch_cell, ',');
                dados.push_back(aux);
            }
            for (
                std::vector<sDados>::iterator iter = dados.begin();
                iter != dados.end();
                iter++)
                {
                    if(iter->qtd <=5)
                    {
                        std::cout << "* ATENCAO: " << iter->id << " - " << 
                        iter->nome << ", com estoque baixo: " << iter->qtd <<
                        " pecas\n";
                    }
                }
                file.close();
                // Isso vai apenas rodar se counter for igual a 5
                // caso o contrário vai passar de buenas pq o arquivo
                // é diferente.
        }

    }else{std::cerr << "Erro ao abrir um file - Alerta de estoque baixo!\n";}
    
    
}

void Utilities::adicionar_ao_arquivo(void){
    // Abrir arquivos e adicionar o que user 
    // quiser - mas será tratado como string
    //this->output_from_csv();
    struct sHeader
    {
        std::vector <std::string> columns;
    };
    
    std::ifstream read_header(this->my_addr);
    sHeader header;
    if(read_header.is_open())
    {
        // Verificar se o file está aberto
        // e pegar a primeira linha que é o header
        // das files db.
        std::string line;
        std::getline(read_header, line);

        std::stringstream ss(line);
        std::string col;

        // pegar essa primeira linha e quebra-la
        // para pegar cada uma das colunas
        while(std::getline(ss, col, ','))
        {
            header.columns.push_back(col);
        }
        read_header.close();
    }else{
        std::cerr << "Deu ruim ao ler o arquivo\n";
    }
    

    std::ofstream file;
    file.open(this->my_addr, std::ios_base::app);

    if (file.is_open())
    {
        std::string nome_coluna;
        for (size_t i = 0; i < this->my_numero_colunas; i++)
        {
            std::cout << "Entre com a coluna " << header.columns[i] << "\n";
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

void Utilities::venda_de_artigos(void){
    struct s_tabela
    {
        // Struct para receber os valores contidos
        // nas tabelas csv.
        // Em tese, vai ficar mais facil manipular 
        // os dados desse jeito.
        int id;
        std::string nome;
        std::string desc;
        int qtd;
        float preco;
    };
    
    size_t contador = 0;

    std::ifstream file(this->my_addr);
    if (file.is_open())
    {
        std::string line;
        while(std::getline(file, line)){
            // Quero contar a quantida de linhas
            // para um termina arquivo csv.
            // Com o número de linhas eu consigo alocar
            // a quantidade necessária de memória para
            // guardar a struct s_tabela.
            contador++;
        }       
    }else{
        std::cerr << "Deu Ruim ao Abrir o Arquivo!\n";
    }

    // Eu tenho que alocar (contador - 1) por causa do header
    // que não me interessa.
    
    std::vector<s_tabela> vector_s_tabela;

    // Voltando para o começo do arquivo
    file.clear();
    file.seekg(0);
    
    // Para tirar o header do arquivo csv
    std::string line;
    std::getline(file, line);
    std::cout << line << "\n";
    
    while (std::getline(file, line))
    {   
        std::cout << line << "\n";
        std::string cell;
        std::stringstream ss(line);

        while(std::getline(ss, cell, ',')){
            // Como eu estou usando o C++11, as funções
            // std::stoi e std::stod não funcionam.
            // referencia -> https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
            s_tabela aux;
            aux.id = atoi(cell.c_str());
            std::getline(ss, cell, ',');
            aux.nome = cell;
            std::getline(ss, cell, ',');
            aux.desc = cell;
            std::getline(ss, cell, ',');
            aux.qtd = atoi(cell.c_str());
            std::getline(ss, cell, ',');
            aux.preco = atof(cell.c_str());
            vector_s_tabela.push_back(aux);
        }                   
                
        // Por algum motivo ele esta printando tudo na tela
        // eu não sei pq.
        // Vou dar clear na tela e seguir em frente, mas seria
        // bom consertar isso. Não encontrei uma solução fácil
        // na net.
    }
    // Limpando as coisa por aqui.
    ClearScreen();
    file.close();
    // Alter os valores no id desejado.
    int get_id = 0;
    size_t prod_vendidos = 0; // Quantos produtos foram vendidos, para reduzir do estoque.
    double valor_da_compra = 0;
    // Pedir para o user entrar com o id do produto.
    std::cout << "Entre com o id do produto a ser vendido:";
    std::cin >> get_id;
    std::cout << "\n";
    std::cout << "Quantos produtos foram comprados:";
    std::cin >> prod_vendidos;
    std::cout << "\n";

    size_t nao_encontrado = 0;
    for (size_t i = 0; i < (contador - 1); i++)
    {
        // Atualiza a quantidade do produto no estoque
        if(get_id == vector_s_tabela[i].id) {
            if (vector_s_tabela[i].qtd == 0)
            {
                ClearScreen();
                std::cout << "Sem produto, repor estoque!\n";
            }else{
                vector_s_tabela[i].qtd = vector_s_tabela[i].qtd - prod_vendidos;
                valor_da_compra = prod_vendidos * vector_s_tabela[i].preco;
                std::cout << vector_s_tabela[i].nome << ": " << prod_vendidos << " vendidos\n";
                std::cout << "Saldo: " << valor_da_compra << "\n";
                std::cout << "\n";
            }
        }
        else{
            nao_encontrado++;
        }
    }
    if (nao_encontrado == (contador -1)) {
        ClearScreen();
        std::cerr << "Id nao encontrado\n";
        
    }
    else{
        // Reescrevendo o arquivo csv com as novas informações
        // Criando um novo arquivo csv vazio
        std::ofstream clear_file(this->my_addr);
        clear_file.close();
        // Abrindo o novo arquivo csv vazio e append.
        std::ofstream new_file;
        new_file.open(this->my_addr, std::ios_base::app);

        if(new_file.is_open()){
            new_file << "id,nome,desc,qtd,preco,\n";
            for (size_t i = 0; i < (contador - 1); i++)
            {
                new_file << vector_s_tabela[i].id << "," << vector_s_tabela[i].nome << "," <<
                vector_s_tabela[i].desc << "," << vector_s_tabela[i].qtd << "," <<
                vector_s_tabela[i].preco << "\n";           
            }        
        }else{
            std::cerr << "Erro ao escrever o arquivo\n";
        }
        // Fechando o arquivo
        new_file.close();
        // Desalocando a mémoria.

        // Lipando a tela
        //ClearScreen();
    }    
}

void Utilities::repor_artigos(void){
    // Essa função coleta o id do produto que será
    // reposto, e adiciona a quantidade comprada 
    // para fazer a reposição.
    // Ela é bem parecida com a função de vendas
    // no que tange as suas partes com a manipula-
    // ção de arquivos.
    // Eu posso querer também mudar o preço do produto
    // devido a algum reajuste.
    struct sRecebeTabela
    {
        // struct que recebe os valores da tabela
        // só funciona pq eu sei o formato das tabelas
        // em vendas.
        int id;
        std::string nome;
        std::string desc;
        int qtd;
        float preco;
    };
    // Vector com a quantidade necessária de linha para
    // conter toda a tabela em formato csv.
    std::vector <sRecebeTabela> vector_de_linhas_da_tabela;

    std::ifstream ler_file(this->my_addr); 
    std::string header;
    if(ler_file.is_open())
    {
        std::string line;
        std::getline(ler_file, line); // Não quero o header
        header = line;
        while(std::getline(ler_file, line))
        {
            std::stringstream ss(line);
            std::string cell;

            sRecebeTabela tabela_aux;
            std::getline(ss, cell, ',');        
            tabela_aux.id = atoi(cell.c_str());
            std::getline(ss, cell, ',');
            tabela_aux.nome = cell;
            std::getline(ss, cell, ',');
            tabela_aux.desc = cell;
            std::getline(ss, cell, ',');
            tabela_aux.qtd = atoi(cell.c_str());
            std::getline(ss, cell, ',');
            tabela_aux.preco = atof(cell.c_str());

            vector_de_linhas_da_tabela.push_back(tabela_aux);        
        }
    }else{std::cerr << "Deu ruim ao abri o arquivo!\n";}
    ler_file.close();

    int get_id = 0;
    size_t qtd_adicionada = 0;
    size_t opcao = 0;
    double novo_preco = 0;

    // Interagir com o usuário
    std::cout << "Digite o nome do id do produto, cujo o estoque sera reposto:";
    std::cin >> get_id;
    std::cout << "\n";
    std::cout << "Quantos produtos serao adicionados:";
    std::cin >> qtd_adicionada;
    std::cout << "\n";
    std::cout << "Deseja alterar o preco? 1 - Sim\n2 - Para manter o preco antigo\n";
    std::cin >> opcao;
    switch (opcao)
    {
    case 1:
        std::cout << "Novo preco:";
        std::cin >> novo_preco;
        std::cout << "\n";
        break;
    
    default:
        break;
    }
    size_t counter = 0;
    for (
        std::vector<sRecebeTabela>::iterator iter = vector_de_linhas_da_tabela.begin(); 
        iter != vector_de_linhas_da_tabela.end(); ++iter
        )
    {
        if(iter->id == get_id && opcao == 1)
        {
            // faz mudança de preço e adiciona a quatidade 
            // adicionada pelo usuário
            iter->qtd += qtd_adicionada;
            iter->preco = novo_preco;
        }else if(iter->id == get_id){
            // Apenas altera a quantidade no estoque
            iter->qtd += qtd_adicionada;
        }
        counter++;
        if(counter == vector_de_linhas_da_tabela.size()) std::cout << "Id nao encontrado\n";
    }    
    // Apenas lcrio um novo arquivo vazio
    std::ofstream clear_file(this->my_addr);
    if(clear_file.fail()) std::cerr << "Erro ao criar um novo arquivo - Reposicao!\n";
    clear_file.close();

    std::ofstream gravar_file(this->my_addr, std::ios_base::app);
    if(gravar_file.is_open()){
        gravar_file << header << "\n";
        for(
            std::vector<sRecebeTabela>::iterator iter = vector_de_linhas_da_tabela.begin();
            iter != vector_de_linhas_da_tabela.end();
            iter++    
        ){
            gravar_file << iter->id << "," << iter->nome << "," << iter->desc << "," <<
            iter->qtd << "," << iter->preco << "," << "\n";
        }
    }else {std::cerr << "Erro ao gravar arquivo - Reposicao!\n";}
    
    gravar_file.close();
}

void ClearScreen()
{
    std::cout << std::string( 100, '\n' );
}

