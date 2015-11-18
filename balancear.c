#include "balancear.h"
#include "rotacionar.h"
#include "getPai.h"
#include "getTipoNo.h"

Node* balancear(Arvore* arvore, Node* no){
	Node* noPai;
	int alturaPercorrida;
	
	// verificar se o nó está balanceado
	if(isBalanceado(no) != 1){
		if (no->valor < arvore->raiz->valor)
			noPai = getPai(arvore->raiz->sae, no->valor);
		else
			noPai = getPai(arvore->raiz->sad, no->valor);
	}
	
	// 
	
	/*Node* noPai;
	int fatorBalanceamento;
	//int fatorBalanceamentoPai = getFatorBalanceamento(altura);
    
    if (no != NULL){
        if (no->valor == valor){
			no->altura = getAltura(no); 
			fatorBalanceamento = getFatorBalanceamento(no, altura);
			
			if (isBalanceado(fatorBalanceamento) != 1){
				getRotacao();		
			}
        }
        else if (no->valor > valor){
			noPai = getPai(no, valor);
            return remover(no->sae, valor);
        }
        else{
			noPai = getPai(no, valor);
            return remover(no->sad, valor);
        }
    }*/
    return no;	
}

int isBalanceado(Node* no){
	if(no->altura->direita >= -1 && no->altura->esquerda <= 1)
		return 1;
	else
		return 0;
}

/*
int getAltura(Node no){
	if (no != NULL){
		
	}
}

int getFatorBalanceamento(Altura altura){
	return (altura->alturaDireita) - (altura->alturaEsquerda);
}
*/
