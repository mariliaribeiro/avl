#ifndef __definicoes_h
#define __definicoes_h

#include<stdio.h>
#include<stdlib.h>

typedef struct node Node; 
typedef struct arvoreBinaria Arvore;
typedef struct alturaNo Altura;


struct alturaNo{
	int esquerda;
	int direita;
	int fatorBalanceamento;
};

struct node {
	int valor; //element
	Node *sae; //sub árvore a esquerda
	Node *sad; //sub árvore a direita
	Altura* altura;
};

struct arvoreBinaria {
	Node* raiz;
};


#endif
