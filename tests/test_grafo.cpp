#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../grafo.h"
#include "../operacoes.h"
#include <set>

Grafo constroi_grafo(){
    /* Vetor de idades e inicialização do grafo (lista de adjacências) */
    Grafo grafo;
    std::vector<int> idades = {21, 33, 34, 18, 42, 22, 26};
    std::vector<std::string> linhas_arestas = {"1 2","1 3","2 5","3 5","3 6","4 6","4 7","6 7"};
    for (int i = 0; i < 7; i++){
        std::vector<int> n1;
        grafo.push_back(n1);
    }
    
    /* Cria as arestas: X comanda Y, lembrando que no programa os índices dos 
    integrantes começam no 0 e no arquivo de entrada começam de 1*/
    for (int i = 0; i < 8; i++){
        std::string Linha = linhas_arestas[i];
        std::string aux;
        str_tok(Linha," ",aux);
        int X = std::stoi(aux) - 1;
        str_tok(Linha," ",aux);
        int Y = std::stoi(aux) - 1;
        grafo[X].push_back(Y);
    }
    return grafo;
}

TEST_CASE("Grafo: transposto"){
    Grafo g = constroi_grafo();
    Grafo TP = transposto(g, 7);

    std::vector<std::set<int>> G1;
    std::vector<std::set<int>> G2;


    G2[1].insert(0);
    G2[2].insert(0);
    G2[4].insert(1);
    G2[4].insert(2);
    G2[5].insert(2);
    G2[5].insert(3);
    G2[6].insert(3);
    G2[6].insert(5);
    /*
    for(int i = 0; i < 7; i++){
        if (!TP[i].empty()){
            for(auto it = TP[i].begin(); it != TP[i].end(); it++){
                int vizinho = *it;
                G1[i].insert(vizinho);
            }
        }
    }
    bool result = true;
    for(int i = 0; i < 7; i++){
        if(!G2[i].empty()){
            for(auto it = G2[i].begin(); it != G2[i].end(); it++){
                auto resp = G1[i].find(*it);
                CHECK(resp != G1[i].end());
            }
        }
    }
    */
    for (int i = 0; i < 7; i++){
        std::cout << i+1 << ": ";
        if(!g[i].empty()){
            for(auto it = g[i].begin(); it != g[i].end(); it++){
                std::cout << (*it)+1 << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 7; i++){
        std::cout << i+1 << ": ";
        if(!TP[i].empty()){
            for(auto it = TP[i].begin(); it != TP[i].end(); it++){
                std::cout << (*it)+1 << " ";
            }
        }
        std::cout << std::endl;
    }
}
