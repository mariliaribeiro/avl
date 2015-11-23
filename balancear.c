#include "balancear.h"
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

Node* balancear(Node* no){
	no->altura->fatorBalanceamento = getFatorBalanceamento(no);
	printf("no: %d -- fb: %d\n", no->valor, no->altura->fatorBalanceamento);

	if(isBalanceado(no) != 1) // está balanceado?
		return rotacionar(no);
    else
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

Node* rotacionar(Node* desbalanceado){
    int fbDesbalanceado = desbalanceado->altura->fatorBalanceamento;
    int fbFilho;    
    Node* noAux;
	    
	if (fbDesbalanceado == 2){ //desbalanceou a sub árvore a esquerda
        fbFilho = desbalanceado->sad->altura->fatorBalanceamento;
		if(fbFilho == 1 || fbFilho == 0){
			return rotacaoSimplesEsquerda(desbalanceado);
		}
		else if (fbFilho == -1){ //Rotação dupla com filho a direita pai a esquerda
			noAux = rotacaoSimplesDireita(desbalanceado->sae);
			return rotacaoSimplesEsquerda(noAux);
		}
	}
	else if (fbDesbalanceado == -2){ //desbalanceou a sub árvore a esquerda
        fbFilho = desbalanceado->sae->altura->fatorBalanceamento;
		if(fbFilho == -1 || fbFilho == 0){
            return rotacaoSimplesDireita(desbalanceado);
		}
		else if (fbFilho == 1){		//Rotação dupla com filho a esquerda e pai a direita]
			noAux = rotacaoSimplesEsquerda(desbalanceado->sad);
			return rotacaoSimplesDireita(noAux);
		}
	}
}

Node* rotacaoSimplesEsquerda(Node* desbalanceado){
	Node* filho = desbalanceado->sad;
	desbalanceado->sad = filho->sae;
	desbalanceado->altura->direita = getMaiorAltura(desbalanceado);
	filho->sae = desbalanceado;
	filho->altura->esquerda = getMaiorAltura(filho);
	desbalanceado = filho;
	return desbalanceado;
}

Node* rotacaoSimplesDireita(Node* desbalanceado){
	Node* filho = desbalanceado->sae;	
	desbalanceado->sae = filho->sad;
	desbalanceado->altura->esquerda = getMaiorAltura(desbalanceado);
	filho->sad = desbalanceado;
	filho->altura->direita = getMaiorAltura(filho);
	desbalanceado = filho;
	return desbalanceado;
}

Node* getFolha(Node* no, int fb){
    if (isFolha(no) ==  1)
        return no;
    else if (fb == 2)
        return getFolha(no->sad, fb);
    else if (fb == -2)
        return getFolha(no->sae, fb);
}

