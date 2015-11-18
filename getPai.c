#include "getPai.h"

Node* getPai(Node* no, int valor){
    if(no != NULL){
        if (no->valor < valor){
            if (no->sad != NULL && no->sad->valor == valor)
                return no;
            else
                return getPai(no->sad, valor);
        }
        else if(no->valor > valor){
            if (no->sae != NULL && no->sae->valor == valor)
                return no;
            else
                return getPai(no->sae, valor);
        }        
    }else{
        return NULL;
    }
}

Node* getPaiArvore(Arvore* arvore, int valor){
    if(arvore->raiz != NULL){
        if(valor < arvore->raiz->valor){
            if (arvore->raiz->sae != NULL && arvore->raiz->sae->valor == valor)
                return arvore->raiz;
            else
                return getPai(arvore->raiz->sae, valor);
        }
        else if (arvore->raiz->valor < valor){
            if (arvore->raiz->sad != NULL && arvore->raiz->sad->valor == valor)
                return arvore->raiz;
            else
                return getPai(arvore->raiz->sad, valor);
        }
    }else{
        return NULL;
    }
}
