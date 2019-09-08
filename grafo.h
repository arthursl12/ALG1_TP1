#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

typedef std::vector<std::vector<int>> Grafo;

Grafo transposto(Grafo grafo);
bool vizinhos(Grafo& grafo, int A, int B);
bool possuiVizinhos(Grafo& grafo, int V);

#endif /* GRAFO_H */