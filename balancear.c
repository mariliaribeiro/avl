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

Node* balancear(Arvore* arvore, Node* no){
	no->altura->fatorBalanceamento = getFatorBalanceamento(no);
	
	// verificar se o nó está balanceado
	if(isBalanceado(no) != 1)
		return rotacionar(arvore, no);
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

Node* rotacionar(Arvore* arvore, Node* desbalanceado){
    int fbFilho;
    int fbDesbalanceado = desbalanceado->altura->fatorBalanceamento;
        
	if (fbDesbalanceado == 2){ //desbalanceou a sub árvore a esquerda
        fbFilho = desbalanceado->sad->altura->fatorBalanceamento;
		if(fbFilho == 1 || fbFilho == 0){
            return rotacaoSimplesEsquerda(arvore, desbalanceado);
		}
		/*else if (fbFilho == -1){ //Rotação dupla com filho a direita pai a esquerda
            desbalanceado = rotacaoSimplesDireita(arvore, desbalanceado);
            desbalanceado = rotacaoSimplesEsquerda(arvore, desbalanceado);
            return desbalanceado;
		}*/
	}
	else if (fbDesbalanceado == -2){ //desbalanceou a sub árvore a esquerda
        fbFilho = desbalanceado->sae->altura->fatorBalanceamento;
		if(fbFilho == -1 || fbFilho == 0){
            return rotacaoSimplesDireita(arvore, desbalanceado);
		}
		/*else if (fbFilho == 1){		//Rotação dupla com filho a esquerda e pai a direita
            desbalanceado = rotacaoSimplesEsquerda(arvore, desbalanceado);
            desbalanceado = rotacaoSimplesDireita(arvore, desbalanceado);
            return subRaiz;
		}*/
	}
}

Node* rotacaoSimplesEsquerda(Arvore* arvore, Node* desbalanceado){
    Node* filho = getFolha(desbalanceado->sad, desbalanceado->altura->fatorBalanceamento);
	Node* pai = getPai(desbalanceado, filho->valor);

    if (desbalanceado->valor == arvore->raiz->valor){//nó desbalanceado é a raiz
        desbalanceado->sad = pai->sae;
        pai->sae = desbalanceado;
        arvore->raiz = pai;
        return arvore->raiz;
    }else{ // nó desbalanceado não é a raíz
        Node* subRaiz = getPai(arvore->raiz, desbalanceado->valor);
        desbalanceado->sad = pai->sae;
        pai->sae = desbalanceado;
        subRaiz = pai;
        return subRaiz;
    }
}

Node* rotacaoSimplesDireita(Arvore* arvore, Node* desbalanceado){
    Node* filho = getFolha(desbalanceado->sae, desbalanceado->altura->fatorBalanceamento);
	Node* pai = getPai(desbalanceado, filho->valor);

	if (desbalanceado->valor == arvore->raiz->valor){//nó desbalanceado é a raiz
        desbalanceado->sae = pai->sad;
        pai->sad = desbalanceado;
        arvore->raiz = pai;
        return arvore->raiz;
    }else{ // nó desbalanceado não é a raíz
        Node* subRaiz = getPai(arvore->raiz, desbalanceado->valor);
        desbalanceado->sae = pai->sad;
        pai->sad = desbalanceado;
        /*if(subRaiz->valor == arvore->raiz->valor)
            subRaiz->sae = pai;
        else if (subRaiz->valor < desbalanceado->valor)
            subRaiz->sad = pai;
        else*/
        subRaiz = pai;
        return subRaiz;
    }
    return arvore->raiz;
}

Node* getFolha(Node* no, int fb){
    if (isFolha(no) ==  1)
        return no;
    else if (fb == 2)
        return getFolha(no->sad, fb);
    else if (fb == -2)
        return getFolha(no->sae, fb);
}

