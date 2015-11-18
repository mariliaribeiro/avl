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

Node* rotacaoSimplesEsquerda(Arvore* arvore, Node* noInserido, int valor){
    Node* noIntermediario = getPaiArvore(arvore, noInserido->valor);
    Node* subRaiz = getPaiArvore(arvore, noIntermediario->valor);

    //subRaiz aponta para nó inserido
    if(valor < subRaiz->valor)
        subRaiz->sae = noInserido; 
    else
        subRaiz->sad = noInserido;

    //nó intermediário passa a ser a raiz
    if(subRaiz->valor < noIntermediario->valor)
        noIntermediario->sae = subRaiz;
    else
        noIntermediario->sad = subRaiz;
        
    return noIntermediario;
}

    //nó inserido aponta para nó intermediário
    /*if(valor < noIntermediario->valor)
        noInserido->sae = noIntermediario; 
    else
        noInserido->sad = noIntermediario;
    */

Node* rotacaoSimplesDireita(Arvore* arvore, Node* noInserido, int valor){
    Node* noIntermediario = getPaiArvore(arvore, noInserido->valor);
    Node* subRaiz = getPaiArvore(arvore, noIntermediario->valor);

    //subRaiz aponta para nó inserido
    if(valor < subRaiz->valor)
        subRaiz->sae = noInserido; 
    else
        subRaiz->sad = noInserido;

    //nó intermediário passa a ser a raiz
    if(subRaiz->valor < noIntermediario->valor)
        noIntermediario->sae = subRaiz;
    else
        noIntermediario->sad = subRaiz;
        
    return noIntermediario;
    
    /*
    Node* noIntermediario = getPaiArvore(arvore, noInserido->valor);
    Node* subRaiz = getPaiArvore(arvore, noIntermediario->valor);
    Node* noAux = subRaiz;
    
    subRaiz = noIntermediario;

    if(valor < noIntermediario->valor)
        subRaiz->sae = noIntermediario->sae;
    else
        subRaiz->sae = noIntermediario->sad;
        
    subRaiz->sad = noAux;    
    return subRaiz;*/
}
