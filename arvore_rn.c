#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq,*dir,*pai;
}No;

int menu();
void preordem(No **r);
No* maior_elemento(No **r);
int remover(No **r,int vlr);
void inserir(No **r,int vlr);
int existe_n(No **r,int n);
void rse(No **r);

int main(){
     No *r = NULL;
    int op;
    int valor;
    do{
        op = menu();
        switch(op){
        
        case 0:
        printf("Sair da Aplicacao\n");
        break;

        case 1:{
        printf("Valor: ");
        scanf("%i", &valor);
        inserir(&r, valor);
        printf("Elemento %i inserido com sucesso!\n", valor);
        }break;

        case 2:{
        printf("Impressao em pre ordem..\n");
        preordem(&r);
        }break;

        case 3:{
        int v;
        printf("Informe o valor a ser removido \n");
        scanf("%d",&v);
        if(existe_n(&r,v))
        remover(&r,v);
        else printf("Não existe esse valor \n");

        }break;

        case 4:{
        rse(&r);
        }break;

        case 5:{
        rse(&r->esq);

        }break;

        default : printf("Opcao Invalida \n");
        }

    }while(op!=0);



    return 0;
}

No* maior_elemento(No **r){
    if(*r == NULL) return NULL;
    if((*r)->dir == NULL) return *r;
    return maior_elemento(&(*r)->dir);

}


int remover(No **r,int vlr){
    if(vlr==(*r)->dado){
        //caso 1
        if((*r)->esq == NULL){
            No *aux = *r;
            *r = (*r)->dir;
            if(*r != NULL){
                (*r)->pai = aux->pai;
            }
            free(aux);
            return 1;
        }
        No *aux = maior_elemento(&(*r)->esq);
        (*r)->dado = aux->dado;
        return remover(&(*r)->esq,(*r)->dado);
    }
    if(vlr > (*r)->dado) return remover(&(*r)->dir,vlr);
    return remover(&(*r)->esq,vlr);
}

void preordem(No **r){
    if(*r!=NULL){
    if((*r)->pai == NULL){
    printf("%i [raiz]\n",(*r)->dado);
    }else{
    printf("%i [PAI: %i]\n",(*r)->dado,(*r)->pai->dado);
    }
    preordem(&(*r)->esq);
    preordem(&(*r)->dir);
    }
}

void inserir(No **r,int vlr){
    if(*r == NULL){
        No *novo=(No*)malloc(sizeof(No));
        novo->dado = vlr;
        novo->esq = NULL;
        novo->dir = NULL;
        novo -> pai = NULL;
        *r = novo;
    }else{
        if(vlr>(*r)->dado){
            inserir(&(*r)->dir,vlr);
            (*r)->dir->pai=*r;
        }else{
            inserir(&(*r)->esq,vlr);
            (*r)->esq->pai=*r;
        }
    }
}

int existe_n(No **r,int n){
    if(*r == NULL)
    return 0;
    if((*r)->dado==n)
    return 1;
    if(n > (*r)->dado) return existe_n(&(*r)->dir,n);
    return existe_n(&(*r)->esq,n);

}

void rse(No **r){
    No *aux;
    aux = *r;
    *r = (*r)->dir;
    aux->dir = (*r)->esq;
    (*r)->esq = aux;
    (*r)->pai = aux->pai;
    aux->pai = *r;
    if(aux->dir!=NULL)
    aux->dir->pai=aux;
    if(aux->dir!=NULL)
    aux->dir->pai =aux;
}

void rsd(No **r){
No *aux;
aux = *r;
}



int menu(){
    int op;
    printf("------MENU------\n");
    printf("\n");
    printf("[0] -> Sair\n");
    printf("[1] -> Inserir\n");
    printf("[2] -> Pre ordem\n");
    printf("[3] -> Remover Elemento\n");
    printf("[4] -> RSE\n");
    printf("\n");
    printf("Informe a operacao desejada: ");
    scanf("%d", &op);
    printf("\n");
    return op;
}
