c#include "rotacionar.h"
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

void rotacionar(Node* no, int fbPai, int fbFilho){
	if (fbPai == 2){
		if(fbFilho == 1 || fbFilho == 0){
			printf("\nRotação símples a esquerda\n");
            //return rotacaoSimplesEsquerda(no); //noFilho ocupa o lugar do pai
		}
		else if (fbFilho == -1){
            //noFilho = rotacaoSimplesDireita(no);
            //noPai = rotacaoSimplesEsquerda(noPai);
            printf("\nRotação dupla com filho a direita e pai a esquerda\n");
		}
	}
	else if (fbPai == -2){
		if(fbFilho == -1 || fbFilho == 0){
			//return rotacaoSimplesDireita(no);
            printf("\nRotação símples a direita\n");
		}
		else if (fbFilho == 1){			
            //noFilho = rotacaoSimplesEsquerda(no);
            //noPai = rotacaoSimplesDireita(noPai);
            printf("\nRotação dupla com filho a esquerda e pai a direita\n");
		}
	}
}

Node* rotacaoSimplesEsquerda(Arvore* arvore, Node* desbalanceado, Node* no){
	pai = getPai(desbalanceado, no->valor);
	if(desbalanceado->sae->valor != pai->valor){
		subRaiz = getPai(desbalanceado, pai->valor);
		//if(subRaiz->valor < no->valor){}
		subRaiz->sad = no;
		pai->sae = subRaiz;
		desbalanceado->sae = pai;		
	}else{
		paiDesbalanceado = getPai(arvore->raiz, desbalanceado->valor);
		if(paiDesbalanceado != NULL){
			pai->sad = desbalanceado;
			paiDesbalanceado->sad = pai;
		}else{
			pai->sae = desbalanceado;
			arvore->raiz = pai;
		}
	} 
}

Node* rotacaoSimplesDireita(Arvore* arvore, Node* desbalanceado, Node* no){
	pai = getPai(desbalanceado, no->valor);
	if(desbalanceado->sae->valor != pai->valor){
		subRaiz = getPai(desbalanceado, pai->valor);
		//if(subRaiz->valor < no->valor){}
		subRaiz->sae = no;
		pai->sad = subRaiz;
		desbalanceado->sad = pai;		
	}else{
		paiDesbalanceado = getPai(arvore->raiz, desbalanceado->valor);
		if(paiDesbalanceado != NULL){
			pai->sae = desbalanceado;
			paiDesbalanceado->sae = pai;
		}else{
			pai->sad = desbalanceado;
			arvore->raiz = pai;
		}
	} 
}
