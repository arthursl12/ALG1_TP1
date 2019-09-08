#include "grafo.h"
#include <iostream>

/* Analisa se existe a aresta (A,B) no grafo. Retorna 'True' ou 'False'. 
Complexidade linear com o grafo */
bool vizinhos(Grafo& grafo, int A, int B){
    bool result = false;
    for (int i = 0; (unsigned int) i < grafo[A].size(); i++)
        if (grafo[A][B] == true) result = true;
    return result;
}

/* Retorna se o vértice de índice V possui vizinhos */
bool possuiVizinhos(Grafo& grafo, int V){
    return (grafo[V].size() > 0);
}

/* Retorna o grafo transposto de 'grafo', que possui N vértices */
Grafo transposto(Grafo grafo, int N){
    Grafo TP;
    for (int i = 0; i < N; i++){
        /* Inicializa o grafo transposto*/
        std::vector<int> n1;
        TP.push_back(n1);
    }
    std::cout << "A1" << std::endl;
    for (int i = 0; i < N; i++){
        if (!grafo[i].empty()){
            for(auto it = grafo[i].begin(); it != grafo[i].end(); it++){
                int vizinho = *it;
                TP[vizinho].push_back(i);
            }
        }
    }
    return TP;
}