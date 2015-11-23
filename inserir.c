#include "inserir.h"
#include "malloc.h"
#include "balancear.h"

Node* inserirNo(int valor){
    Node* novoNo = criaNode();
    novoNo->valor = valor;
    return novoNo;
}

Node* inserir(Node* subRaiz, int valor){
    /* inserção menor ou igual vão para a sae
     * logo,  a remoção dever pegar o maior dos menores*/
        
    if (subRaiz != NULL){
		if (subRaiz->valor < valor)
			subRaiz->sad = inserir(subRaiz->sad, valor);
		else
			subRaiz->sae = inserir(subRaiz->sae, valor);
	}else{
        return inserirNo(valor);
	}
	subRaiz = balancear(subRaiz);
    return subRaiz;
}
