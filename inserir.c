#include "inserir.h"
#include "malloc.h"
#include "balancear.h"

Node* inserirNo(int valor){
    Node* novoNo = criaNode();
    novoNo->valor = valor;
    return novoNo;
}

Node* inserir(Arvore* arvore, Node* subRaiz, int valor){
    /* inserção menor ou igual vão para a sae
     * logo,  a remoção dever pegar o maior dos menores*/
        
    if (subRaiz != NULL){
		if (subRaiz->valor < valor)
			subRaiz->sad = inserir(arvore, subRaiz->sad, valor);
		else
			subRaiz->sae = inserir(arvore, subRaiz->sae, valor);
	}else{
		return inserirNo(valor);
	}
		
    return subRaiz;
}

Node* inserirBalancear(Arvore* arvore, Node* subRaiz, int valor){
    subRaiz = inserir(arvore, subRaiz, valor);
	return balancear(arvore, subRaiz);
}
