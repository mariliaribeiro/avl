#include "balancear.h"
#include "rotacionar.h"
#include "getPai.h"
#include "getTipoNo.h"

Node* balancear(Arvore* arvore, Node* no){
	no->altura->fatorBalanceamento = getFatorBalanceamento(no);
	
	// verificar se o nó está balanceado
	if(isBalanceado(no) != 1){		
		printf("Desbalanceado! no: %d --- fb = %d\n", no->valor, no->altura->fatorBalanceamento);
		rotacionar(arvore, no);	
	}
	printf("Balanceado! no: %d --- fb = %d\n", no->valor, no->altura->fatorBalanceamento);
	return no;
}

int isBalanceado(Node* no){
	int fb = no->altura->fatorBalanceamento;
	if((fb >= -1) && (fb <= 1))
		return 1;
	else
		return 0;
}

int getFatorBalanceamento(Node* no){
	if(no->sae != NULL)
		no->altura->esquerda = 1 + getMaiorAltura(no->sae);
	else if(no->sad != NULL)
		no->altura->direita = 1 + getMaiorAltura(no->sad);
	return no->altura->direita - no->altura->esquerda;
}

int getMaiorAltura(Node* no){
	if(no->altura->esquerda > no->altura->direita)
		return no->altura->esquerda;
	else
		return no->altura->direita;
}
