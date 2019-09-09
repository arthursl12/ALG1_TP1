#include "grafo.h"
#include <iostream>

/* Analisa se existe a aresta (A,B) no grafo. Retorna 'True' ou 'False'. 
Complexidade linear com o grafo */
bool vizinhos(Grafo& grafo, int A, int B){
    bool result = false;
    for (auto it = grafo[A].begin(); it != grafo[A].end(); it++){
        if(*it == B) result = true;
    }
    return result;
}

/* Retorna se o vértice de índice V possui vizinhos */
bool possuiVizinhos(Grafo& grafo, int V){
    return (grafo[V].size() > 0);
}

/* Retorna o grafo transposto de 'grafo', que possui N vértices. 
Complexidade linear com o grafo, pois faz uma passada por toda a lista de adjacências */
Grafo transposto(Grafo grafo, int N){
    Grafo TP;
    for (int i = 0; i < N; i++){
        /* Inicializa o grafo transposto*/
        std::vector<int> n1;
        TP.push_back(n1);
    }
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

/* Remove a aresta (A,B) do grafo 'grafo', dado que ela existe. 
Complexidade linear com o tamanho da lista de adjacências do vértice A */
void remove(Grafo& grafo, int A, int B){
    auto it = grafo[A].begin();
    while (*it != B)
        it++;
    grafo[A].erase(it);
}