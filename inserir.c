#include "inserir.h"
#include "malloc.h"
#include "rotacionar.h"

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
        //return rotacionar(arvore, subRaiz); //raiz recebe o nó da rotação
	}
		
    return subRaiz;
}

Node* balancear(Arvore* arvore, Node* subRaiz, int valor){
	rotacionar();
}
