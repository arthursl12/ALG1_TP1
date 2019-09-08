#ifndef DFS_H
#define DFS_H

#include <vector>
#include "grafo.h"

enum Cor {preto, cinza, branco};

class DFS{
public:
    DFS(Grafo& grafo, std::vector<int>& result, bool& ciclo);
    DFS(Grafo& grafo, int V, int& idade, std::vector<int>& idades);
private:
    bool visitaDFS(int idx, Grafo& grafo, std::vector<Cor>& Color, std::vector<int>& result);
    void visitaDFS(int idx, Grafo& grafo, std::vector<Cor>& Color, std::vector<int>& idades, int& idade);
};

#endif /* DFS_H */