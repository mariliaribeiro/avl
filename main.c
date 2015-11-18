#include "definicoes.h"
#include "malloc.h"
#include "inserir.h"
#include "ordenar.h"
#include "buscar.h"
#include "remover.h"

void popular(Arvore*);
void exibeOrdem(Arvore*);
void exibeBusca(Arvore*);
void exibeRemocao(Arvore*);

int main(){
	Arvore* minhaArvore;
	minhaArvore = criaArvore();
    popular(minhaArvore);
    exibeOrdem(minhaArvore);
    exibeBusca(minhaArvore);
    //exibeRemocao(minhaArvore);
    //exibeOrdem(minhaArvore);
        
	return 1;
}

void popular(Arvore* arvore){
    arvore->raiz = inserir(arvore, arvore->raiz, 20);
    arvore->raiz = inserir(arvore, arvore->raiz, 10);
    arvore->raiz = inserir(arvore, arvore->raiz, 15);
    arvore->raiz = inserir(arvore, arvore->raiz, 13);
    arvore->raiz = inserir(arvore, arvore->raiz, 18);
    /*arvore->raiz = inserir(arvore->raiz, 5);
    arvore->raiz = inserir(arvore->raiz, 2);
    arvore->raiz = inserir(arvore->raiz, 7);
    arvore->raiz = inserir(arvore->raiz, 30);
    arvore->raiz = inserir(arvore->raiz, 25);
    arvore->raiz = inserir(arvore->raiz, 45);
    arvore->raiz = inserir(arvore->raiz, 28);
    arvore->raiz = inserir(arvore->raiz, 27);
    arvore->raiz = inserir(arvore->raiz, 29);
    arvore->raiz = inserir(arvore->raiz, 40);
    arvore->raiz = inserir(arvore->raiz, 60);
    arvore->raiz = inserir(arvore->raiz, 6);*/
}

void exibeOrdem(Arvore* arvore){
    printf("\n#----- Visualizando estrutura da árvore -----#\n");
    printf("Árvore pré-ordem: ");
    preOrdem(arvore->raiz);
    printf("\nArvore pós-ordem: ");
    posOrdem(arvore->raiz);
    printf("\nÁrvore em ordem: ");
    emOrdem(arvore->raiz);
    printf("\n");
}

void exibeBusca(Arvore* arvore){
    printf("\n#----- Buscando valores da árvore -----#\n");
    imprimeBusca(buscar(arvore->raiz, 10), 10);
    imprimeBusca(buscar(arvore->raiz, 20), 20);
    imprimeBusca(buscar(arvore->raiz, 15), 15);
    imprimeBusca(buscar(arvore->raiz, 31), 31);
}

void exibeRemocao(Arvore* arvore){
    printf("\n#----- Removendo valores da árvore: -----#\n");
    remover(arvore, arvore->raiz, 13);
    remover(arvore, arvore->raiz, 25);
    remover(arvore, arvore->raiz, 10);
    remover(arvore, arvore->raiz, 20);
}
