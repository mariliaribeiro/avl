#include "remover.h"
#include "getPai.h"
#include "getTipoNo.h"
#include "balancear.h"


Node* remover(Arvore* arvore, Node* no, int valor){
    Node* noPai;
        
    if (no != NULL){
        if (no->valor == valor){    
			// é a raiz?
			if(isRaiz(arvore, no) == 1)
				noPai = NULL;
			
            // é folha ?            
			if(isFolha(no) == 1)				
				no = removerFolha(arvore, no, noPai, valor);
            
            // é sub folha?
			else if(isSubFolha(no) == 1)
				no = removerSubFolha(arvore, no, noPai, valor);	
			
			// é pai de dois filhos (maior dos menores)?
			else if(isPaiDoisFilhos(no) == 1)			
				no = removerPaiDoisFilhos(arvore, no, noPai, valor);
        }
        else if (no->valor > valor){
			noPai = getPai(no, valor);
            no = remover(arvore, no->sae, valor);
        }
        else{
			noPai = getPai(no, valor);
            no = remover(arvore, no->sad, valor);
        }
    }

    //Node* folha = getFolha(no);
    //atualizarAltura(no);
    //no = balancear(no);
    return no;
}

Node* removerFolha(Arvore* arvore, Node* no, Node* noPai, int valor){
	Node* noRemover = no;
	
	if(noPai != NULL){
		if(noPai->valor > valor)
			 noPai->sae = NULL;
		else
			noPai->sad = NULL;
	}else{
		no = NULL;
		arvore->raiz = no;
	}
		 
	printf("Removido: %d\n", noRemover->valor);
	free(noRemover);
    atualizarAltura(no);
    balancear(no);
	return no;
}

//if ternário -> condição ? verdadeiro : falso
Node* removerSubFolha(Arvore* arvore, Node* no, Node* noPai, int valor){	
	Node* noRemover = no;
	
	if(noPai != NULL){
		if(noPai->valor > valor)		
			noPai->sae = no->sad != NULL ? noRemover->sad : noRemover->sae;
		else
			noPai->sad = no->sad != NULL ? noRemover->sad : noRemover->sae;
	}else{
		no = no->sad != NULL ? noRemover->sad : noRemover->sae;
		arvore->raiz = no;
	}
	
	printf("Removido: %d\n", noRemover->valor);
	free(noRemover);
    atualizarAltura(no);
    balancear(no);
	return no;	
}

Node* removerPaiDoisFilhos(Arvore* arvore, Node* no, Node* noPai, int valor){	
	Node* noRemover = no;
    Node* noSubstituto = getNoSubstituto(no->sae);	 //filho esquerdo do nó que quero remover
    Node* noPaiSubstituto = getPai(no->sae, noSubstituto->valor);
    noPaiSubstituto->sad = noSubstituto->sae;
            
    noSubstituto->sae = noRemover->sae;
    noSubstituto->sad = noRemover->sad;
    	
	if(noPai != NULL){
		if(noPai->valor > valor)		
			noPai->sae = noSubstituto;
		else
			noPai->sad = noSubstituto;
	}else{	
		no = noSubstituto;
		arvore->raiz = no;
	}
	
	printf("Removido: %d\n", noRemover->valor);
	free(noRemover);	
    atualizarAltura(no);
    balancear(no);
    return no;	
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

Node* getFolha(Node* no){
    if (isFolha(no) ==  1){
        return no;
    }
    else{
        no = getFolha(no->sae);
        no = getFolha(no->sad);
        return no;
    }
}
