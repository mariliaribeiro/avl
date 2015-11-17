#include "malloc.h"

Arvore* criaArvore() {
	Arvore* novaArvore = (Arvore*) malloc(sizeof(Arvore));
	novaArvore->raiz = NULL;
	return novaArvore;
}


Altura* criaAltura(){
	Altura* novaAltura = (Altura*) malloc(sizeof(Altura));
	novaAltura->esquerda = 0;
	novaAltura->direita = 0;
	novaAltura->fatorBalanceamento = novaAltura->direita - novaAltura->esquerda;
	return novaAltura;	
}

Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->sae = NULL;
    novoNo->sad = NULL;   
    novoNo->altura = criaAltura();	
	return novoNo;
}

