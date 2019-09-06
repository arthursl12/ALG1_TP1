#include "operacoes.h"

/* Particiona a string 'str' pelo delimitador 'delimiter' e guarda o token particionado na string 'token' (o token é removido da string original);
Se não encontrar o token, apenas coloca a string original no 'token';
Retorna 'True' se foi possível fazer a operação, 'False' se não encontrar o delimitador e não conseguir fazer o particionamento; */
bool str_tok(std::string& str, std::string delimiter, std::string& token){
    std::size_t idx = str.find(delimiter);
    token = str.substr(0, idx);

    if (idx == std::string::npos){
        /* Não achou o delimitador: não faz nada e coloca a string original no token*/
        token = str;
        return false;
    }
    str.erase(0, idx+1); /* Remove o token e o delimitador da string original */
    return true;
}

/* Propõe uma ordenação topológica da DAG que é o grafo em questão, em outras 
palavras, propõe uma ordem de fala na reunião em que um subordinado não pode falar
antes de algum superior direto ou indireto */
void Meeting(Grafo& grafo){
    std::stack<int> pilha;
    // DFS_Pilha
    std::cout << "M ";
    while(!pilha.empty()){
        int A = pilha.top();
        std::cout << A;
        pilha.pop();
        if (pilha.size() != 0) std::cout << " ";
    }
    std::cout << std::endl;
}

/* Recebe uma pessoa P e imprime qual a pessoa mais jovem que a comanda, direta ou indiretamente
Se P não comandar ninguém, imprime '*' */
void Commander(std::string instr, Grafo& grafo){
    std::string aux;
    str_tok(instr," ", aux);
    str_tok(instr," ", aux);
    int P = std::stoi(aux);
    // Transposto(grafo)
    // DFS_procura idade
    int resp = -1;
    if (resp == -1){
        /* Aluno não é comandado por ninguém */
        std::cout << "C *" << std::endl;
    }else{
        std::cout << "C " << resp << std::endl;
    }
}

/* Analisa se existe a aresta (A,B) no grafo. Retorna 'True' ou 'False'. 
Complexidade linear */
bool vizinhos(Grafo& grafo, int A, int B){
    bool result = false;
    for (int i = 0; (unsigned int) i < grafo[A].size(); i++)
        if (grafo[A][B] == true) result = true;
    return result;
}

/* Verifica se A comanda B. Se sim, inverte: B comanda A. Verifica se a inversão
não cria ciclos. Se não, mantém a inversão. Se sim, não altera a aresta */
void Swap(std::string instr, Grafo& grafo){
    std::string aux;
    str_tok(instr," ", aux);
    str_tok(instr," ", aux);
    int A = std::stoi(aux);
    str_tok(instr," ", aux);
    int B = std::stoi(aux);
    
    // Verifica aresta
    if (!vizinhos(grafo,A,B)){
        std::cout << "S N" << std::endl;
        return;
    }
    // Copia grafo
    // Swap no grafo cópia
    // DFS_procura ciclos
    bool ciclos = false;
    if (ciclos == true){
        std::cout << "S N" << std::endl;
    }else{
        std::cout << "S T" << std::endl;
        // grafo = C_grafo;
    }
}