#ifndef DFS_H
#define DFS_H

#include <vector>
#include "grafo.h"

enum Cor {preto, cinza, branco};

class DFS{
public:
    DFS(Grafo& grafo, std::vector<int>& result, bool& ciclo);
protected:
    bool visitaDFS(int idx, Grafo& grafo, std::vector<Cor>& Color, std::vector<int>& result);

};


#endif /* DFS_H */