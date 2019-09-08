#ifndef OPERACOES_H
#define OPERACOES_H

#include <vector>
#include <string>
#include <iostream>

#include "grafo.h"

bool str_tok(std::string& str, std::string delimiter, std::string& token);
void Meeting(Grafo& grafo);
void Commander(std::string instr, Grafo& grafo);
void Swap(std::string instr, Grafo& grafo);

#endif /* OPERACOES_H */