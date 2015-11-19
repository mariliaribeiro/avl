#include "balancear.h"
#include "rotacionar.h"
#include "getPai.h"
#include "getTipoNo.h"

Node* balancear(Arvore* arvore, Node* no, Node* noInserido){
	Node* noPai = getPai(arvore->raiz, no->valor);
	int alturaPercorrida;

	// verificar se o nó está balanceado
	if(isBalanceado(no) != 1){		
		return rotacionar(arvore, no, noInserido);	
	}
	return no;
}

int isBalanceado(Node* no){
	if(no->altura->direita >= -1 && no->altura->esquerda <= 1)
		return 1;
	else
		return 0;
}

Node* calculaAltura(Node* no){
	// é folha?
	if(isFolha(no) == 1)
		return no;	
	
	// é sub folha?
	else if(isSubFolha(no) == 1){
		no->altura->esquerda = getAltura(no);
		no->altura>direita = getAltura(no);
		no->altura->fatorBalanceamento = no->altura>direita - no->altura->esquerda;
		return no;
	}	
		
	// é pai de dois filhos (maior dos menores)?
	else if(isPaiDoisFilhos(no) == 1){
		no->altura->esquerda = getAltura(no);
		no->altura>direita = getAltura(no);
		no->altura->fatorBalanceamento = no->altura>direita - no->altura->esquerda;
		return no;
	}			
}


Altura* getAltura(Node no){
	Altura* altura;
	
	if (no != NULL){
		if(isSubFolha(no) == 1){
			if(no->sae != NULL){
				altura->esquerda += 1;
				return getAltura(no->sae);
			}else if(no->sad != NULL){
				alturaDireita += 1;
				return getAltura(no->sad);
			}
		}
		else if(isPaiDoisFilhos(no) == 1){
			altura->esquerda += 1;
			altura->direita += 1;
			altura = getAltura(no->sae);
			altura = getAltura(no->sad);
			return altura;
		}
	}
	return altura;
}
