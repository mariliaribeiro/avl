#ifndef __remover_h
#define __remover_h

#include "definicoes.h"

Node* remover(Node*, int);
Node* removerFolha(Node*, int);
Node* removerSubFolha(Node*, int);
Node* removerPaiDoisFilhos(Node*, int);
Node* getMaiorMenores(Node*);
Node* getNoSubstituto(Node*);

#endif
