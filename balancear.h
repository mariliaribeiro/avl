#ifndef __balancear_h
#define __balancear_h
#include "definicoes.h"

Node* balancear(Node*);
int isBalanceado(Node*);
int getFatorBalanceamento(Node*);
int getMaiorAltura(Node*);
Node* rotacionar(Node*);
Node* rotacaoSimplesEsquerda(Node*);
Node* rotacaoSimplesDireita(Node*);
void atualizarAltura(Node*);
#endif
