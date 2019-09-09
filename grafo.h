#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

typedef std::vector<std::vector<int>> Grafo;

Grafo transposto(Grafo grafo, int N);
bool vizinhos(Grafo& grafo, int A, int B);
bool possuiVizinhos(Grafo& grafo, int V);
void remove(Grafo& grafo, int A, int B);

#endif /* GRAFO_H */