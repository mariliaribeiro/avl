#include "rotacionar.h"
#include "getPai.h"
#include "getTipoNo.h"

/* 
	-------------------------------------------------------------------------------------
    | Índice | Índice Filho Desbalanceado |           Operações (Rotação)               |
	-------------------------------------------------------------------------------------
	|       |               1             |             símples à esquerda              |          
	|   2   |               0             |             símples à esquerda              |  
	|       |              -1             | dupla c/ filho p/ direita e pai p/ esquerda | 
	-------------------------------------------------------------------------------------
	|       |               1             | dupla c/ filho p/ esquerda e pai p/ direita | 
	|  -2   |               0             |             símples à direita               | 
	|       |              -1             |             símples à direita               |
	-------------------------------------------------------------------------------------
*/
// fbPai = fator de balanceamento do nó desbalanceado
// fbFilho = fator de balanceamento do nó filho do nó desbalanceado

Node* rotacionar(Arvore* arvore, Node* desbalanceado){
	Node* noFilho; //encontrar a folha
	Node* noPai;  // encontar pai da folha;
	int fbFilho;
	int fbPai = desbalanceado->altura->fatorBalanceamento;
	
	
	if (fbPai == 2){		
		fbFilho = getFatorBalanceamento(desbalanceado->sad);
		noFilho = getFolha(desbalanceado->sad);
		noPai = getPai(desbalanceado, noFilho->valor);
		//printf("desbalanceou a direita. fbFilho: %d\n", fbFilho);
		
		if(fbFilho == 1 || fbFilho == 0){
			//printf("\nRotação símples a esquerda\n");
            return rotacaoSimplesEsquerda(arvore, desbalanceado, noPai, noFilho); //noFilho ocupa o lugar do pai
		}
		else if (fbFilho == -1){
            //printf("\nRotação dupla com filho a direita e pai a esquerda\n");
            desbalanceado = rotacaoSimplesDireita(arvore, desbalanceado, noPai, noFilho);
            desbalanceado = rotacaoSimplesEsquerda(arvore, desbalanceado, noPai, noFilho);
            return desbalanceado;
		}
	}
	else if (fbPai == -2){
		fbFilho = getFatorBalanceamento(desbalanceado->sae);
		noFilho = getFolha(desbalanceado->sad);
		noPai = getPai(desbalanceado, noFilho->valor);
		//printf("desbalanceou a esquerda. fbFilho: %d\n", fbFilho);
		
		if(fbFilho == -1 || fbFilho == 0){
            //printf("\nRotação símples a direita\n");
            return rotacaoSimplesDireita(arvore, desbalanceado, noPai, noFilho);
		}
		else if (fbFilho == 1){			
            //printf("\nRotação dupla com filho a esquerda e pai a direita\n");
            desbalanceado = rotacaoSimplesEsquerda(arvore, desbalanceado, noPai, noFilho);
            desbalanceado = rotacaoSimplesDireita(arvore, desbalanceado, noPai, noFilho);
            return desbalanceado;
		}
	}
}

Node* rotacaoSimplesEsquerda(Arvore* arvore, Node* desbalanceado, Node* pai, Node* filho){
	//Node* pai = getPai(desbalanceado, no->valor);
	
	if(desbalanceado->sae->valor != pai->valor){
		Node* subRaiz = getPai(desbalanceado, pai->valor);
		//if(subRaiz->valor < no->valor){}
		subRaiz->sad = filho;
		pai->sae = subRaiz;
		desbalanceado->sae = pai;		
	}else{
		Node* paiDesbalanceado = getPai(arvore->raiz, desbalanceado->valor);
		if(paiDesbalanceado != NULL){
			pai->sad = desbalanceado;
			paiDesbalanceado->sad = pai;
		}else{
			pai->sae = desbalanceado;
			arvore->raiz = pai;
		}
	} 
	return arvore->raiz;
}

Node* rotacaoSimplesDireita(Arvore* arvore, Node* desbalanceado, Node* pai, Node* filho){
	//Node* pai = getPai(desbalanceado, no->valor);

	if(desbalanceado->sae->valor != pai->valor){
		Node* subRaiz = getPai(desbalanceado, pai->valor);
		//if(subRaiz->valor < no->valor){}
		subRaiz->sae = filho;
		pai->sad = subRaiz;
		desbalanceado->sad = pai;		
	}else{
		Node* paiDesbalanceado = getPai(arvore->raiz, desbalanceado->valor);
		if(paiDesbalanceado != NULL){
			pai->sae = desbalanceado;
			paiDesbalanceado->sae = pai;
		}else{
			pai->sad = desbalanceado;
			arvore->raiz = pai;
		}
	} 
	return arvore->raiz;
}
