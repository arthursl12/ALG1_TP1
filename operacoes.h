#ifndef OPERACOES_H
#define OPERACOES_H

#include <stack>
#include <vector>
#include <string>
#include <iostream>

typedef std::vector<std::vector<int>> Grafo;

bool str_tok(std::string& str, std::string delimiter, std::string& token);
void Meeting(Grafo& grafo);
void Commander(std::string instr, Grafo& grafo);
bool vizinhos(Grafo& grafo, int A, int B);
void Swap(std::string instr, Grafo& grafo);

#endif /* OPERACOES_H */