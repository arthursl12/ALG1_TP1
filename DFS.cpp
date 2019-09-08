#include "DFS.h"

/* Algortimo baseado na implementação do Nívio Ziviani vista em sala */
/* Executa a DFS a partir do vértice 0, colocando em 'result' um vetor com o caminhamento 
executado e retornando se há algum ciclo */
DFS::DFS(Grafo& grafo,std::vector<int>& result, bool& ciclo){
    int N = grafo.size();
    std::vector<Cor> Color;
    for (int i = 0; i < N; i++){
        Color.push_back(branco);
    }
    // O algoritmo aqui não escolhe onde começar a busca, vai pelo vértice 0
    for (int i = 0; i < N; i++){
        if (Color[i] == branco)
            ciclo = ciclo || visitaDFS(i, grafo, Color, result);
    }
}

/* Parte recursiva do DFS, aprofunda-se recursivamente no grafo. Além disso, retorna
'True' caso encontre um ciclo, 'False' do contrário */
bool DFS::visitaDFS(int idx, Grafo& grafo, std::vector<Cor>& Color, std::vector<int>& result){
    Color[idx] = cinza;
    if (possuiVizinhos(grafo, idx)){
        /* Procura em todos os vizinhos */
        for (auto it = grafo[idx].begin(); it != grafo[idx].end(); it++){
            if (Color[*it] == branco)
                visitaDFS(*it, grafo, Color, result);
            /* Checa por ciclos, caso o vizinho seja cinza */
            if (Color[*it] == cinza)
                return true;
        }
        
    }
    result.push_back(idx);
    Color[idx] = preto;
    return false;
}