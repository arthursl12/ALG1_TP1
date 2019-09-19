#include <fstream>
#include <chrono>
#include "operacoes.h"
#include "DFS.h"

/* Inicializa o grafo, lendo as entradas do arquivo */
void inicializacao(Grafo& grafo, std::ifstream& arq, std::vector<int>& idades, int& N, int& Instr){
    /* Parâmetros da primeira linha */
    std::string Linha;
    std::getline(arq,Linha);
    std::string aux;
    str_tok(Linha," ",aux);
    N = std::stoi(aux);
    str_tok(Linha," ",aux);
    int Arestas = std::stoi(aux);
    str_tok(Linha," ",aux);
    Instr = std::stoi(aux);

    
    /* Vetor de idades e inicialização do grafo (lista de adjacências) */
    std::getline(arq,Linha);
    for (int i = 0; i < N; i++){
        str_tok(Linha," ",aux);
        idades.push_back(std::stoi(aux));
        std::vector<int> n1;
        grafo.push_back(n1);
    }
    
    /* Cria as arestas: X comanda Y, lembrando que no programa os índices dos 
    integrantes começam no 0 e no arquivo de entrada começam de 1*/
    for (int i = 0; i < Arestas; i++){
        std::getline(arq,Linha);
        str_tok(Linha," ",aux);
        int X = std::stoi(aux) - 1;
        str_tok(Linha," ",aux);
        int Y = std::stoi(aux) - 1;
        grafo[X].push_back(Y);
    }
}

int main(int argc, char* argv[]){
    /* Coleta o argumento: nome do arquivo a ser lido e abre o arquivo*/
    if (argc != 2){std::cout << "Argumento faltando"; exit(1);}
    std::string nome_arq = argv[1];
    std::ifstream arq;
    arq.open(nome_arq, std::ios::in);
    if (!arq.is_open()){std::cout << "Erro na abertura do arquivo"; exit(1);}

    /* Execução do programa: leitura e processamento */
    Grafo grafo;
    std::vector<int> idades;
    int N;
    int Instr;
    inicializacao(grafo, arq, idades, N, Instr);

    /* Leitura das instruções e execução de cada uma delas */
    std::string Linha;
    for (int i = 0; i < Instr; i++){
        std::getline(arq,Linha);
        if (Linha[0] == 'C') Commander(Linha, grafo, N, idades);
        if (Linha[0] == 'M') Meeting(grafo);
        if (Linha[0] == 'S') Swap(Linha, grafo);
    }

    arq.close();
    return 0;
}