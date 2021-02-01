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
    // Pedir para o user entrar com o id do produto.
    std::cout << "Entre com o id do produto a ser vendido:";
    std::cin >> get_id;
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
                vector_s_tabela[i].qtd = vector_s_tabela[i].qtd - 1;
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

void ClearScreen()
{
    std::cout << std::string( 100, '\n' );
}

