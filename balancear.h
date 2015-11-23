#ifndef __balancear_h
#define __balancear_h
#include "definicoes.h"

Node* balancear(Arvore*, Node*);
int isBalanceado(Node*);
int getFatorBalanceamento(Node*);
int getMaiorAltura(Node*);
Node* rotacionar(Arvore*, Node*);
Node* rotacaoSimplesEsquerda(Arvore*, Node*, Node*, Node*);
Node* rotacaoSimplesDireita(Arvore*, Node*, Node*, Node*);
Node* getFolha(Node*, int);
#endif
