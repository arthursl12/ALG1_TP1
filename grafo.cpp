#include "grafo.h"

/* Analisa se existe a aresta (A,B) no grafo. Retorna 'True' ou 'False'. 
Complexidade linear */
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