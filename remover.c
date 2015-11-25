#include "remover.h"
#include "getPai.h"
#include "getTipoNo.h"
#include "balancear.h"


Node* remover(Node* subRaiz, int valor){        
    if (subRaiz != NULL){
        if(subRaiz->valor != valor){
            if (subRaiz->valor > valor){
                subRaiz->sae =  remover(subRaiz->sae, valor);
                subRaiz->altura->esquerda -=1;
            }else{
                subRaiz->sad =  remover(subRaiz->sad, valor);
                subRaiz->altura->direita -= 1;
            }
        }else{
            if(isFolha(subRaiz) == 1) // é folha ?            
				return removerFolha(subRaiz, valor);
			else if(isSubFolha(subRaiz) == 1) // é sub folha?
				return removerSubFolha(subRaiz, valor);	
			else if(isPaiDoisFilhos(subRaiz) == 1) // é pai de dois filhos (maior dos menores)?
				return removerPaiDoisFilhos(subRaiz, valor);
        }       
    }

    subRaiz->altura->fatorBalanceamento = subRaiz->altura->direita - subRaiz->altura->esquerda;
    //printf("no:%d \n", subRaiz->valor);
    //printf("no:%d he:%d hd:%d fb:%d\n", subRaiz->valor, subRaiz->altura->direita, subRaiz->altura->esquerda, subRaiz->altura->fatorBalanceamento);
    return balancear(subRaiz);
}

Node* removerFolha(Node* no, int valor){
    printf("Removido: %d\n", no->valor);
    free(no);
    return NULL;
}

//if ternário -> condição ? verdadeiro : falso
Node* removerSubFolha(Node* no, int valor){
		printf("Removido: %d\n", no->valor);
		free(no);	
		return no->sad != NULL ? no->sad : no->sae;
}

Node* removerPaiDoisFilhos(Node* no, int valor){
    Node* noSubstituto = getNoSubstituto(no->sae);	 //filho esquerdo do nó que quero remover
    Node* noPaiSubstituto = getPai(no->sae, noSubstituto->valor);
    noPaiSubstituto->sad = noSubstituto->sae;
            
    noSubstituto->sae = no->sae;
    noSubstituto->sad = no->sad;

    printf("Removido: %d\n", no->valor);
    free(no);
    return noSubstituto;
}

Node* getMaiorMenores(Node* no){
	if(no != NULL){
		if(no->sad == NULL)
			return no;
		else
			return getMaiorMenores(no->sad);
	}
}

Node* getNoSubstituto(Node* no){
	if(no->sad != NULL)	
		return getMaiorMenores(no->sad);
	else
		return no;
}
