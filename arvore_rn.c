#include <stdio.h>
#include <stdlib.h>


typedef enum{VERMELHO, PRETO} Cor;


typedef struct no{
    int dado;
    Cor cor;
    struct no *esq,*dir,*pai;
}No;

int menu();
void preordem(No **r);
No* maior_elemento(No **r);
int remover(No **r,int vlr);
void corrigir_pai_que_e_filho_esquerdo(No **r, No *avaliado);
int eh_vermelho(No *no);
int inserirRB(No **r,int valor);
void correcao(No **r, No *avaliado);
No* inserir(No **r,int vlr);
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
        inserirRB(&r, valor);
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
    if((*r)->cor == VERMELHO)
        printf("VERMELHO  ");
    else
        printf("PRETO   ");
    
    if((*r)->pai == NULL){
        printf("%i [raiz]\n",(*r)->dado);
    }else{
    printf("%i [PAI: %i]\n",(*r)->dado,(*r)->pai->dado);
    }
    preordem(&(*r)->esq);
    preordem(&(*r)->dir);
    }
}

No* inserir(No **r,int vlr){
    if(*r == NULL){
        No *novo=(No*)malloc(sizeof(No));
        novo->dado = vlr;
        novo->esq = NULL;
        novo->dir = NULL;
        novo -> pai = NULL;
        novo->cor = VERMELHO;
        *r = novo;
        return novo;
    }else{
        No *retorno;
        if(vlr>(*r)->dado){
            retorno = inserir(&(*r)->dir,vlr);
            (*r)->dir->pai=*r;
        }else{
            if(vlr < (*r)->dado){
            retorno = inserir(&(*r)->esq,vlr);
            (*r)->esq->pai=*r;
        }else{
            return NULL;
        }
        }

     return retorno;
    }
}

int eh_vermelho(No *no){
    if(no == NULL)
    return 0;
    if(no->cor == VERMELHO)
    return 1;
    return 0;
}

void corrigir_pai_que_e_filho_esquerdo(No **r, No *avaliado){
    No *pai = avaliado->pai;
    No *avo = pai->pai;
    No *tio = avo->dir;

    if(eh_vermelho(tio)){
    pai->cor = PRETO;
    avo->cor = VERMELHO;
    tio->cor = PRETO;

    preordem(&avo);

    avaliado = avo;
    }

}

void correcao(No **r, No *avaliado){
    while(avaliado->pai!=NULL){
        if(avaliado->pai->cor == PRETO)
        break;

        No *pai = avaliado->pai;
        No *avo = pai->pai;
        if(avo->esq == pai){ //o pai é um filho esquerdo 
        corrigir_pai_que_e_filho_esquerdo(r, avaliado);
        }else{ //o pai é um filho direito
        printf("Correcao de Pai que é filho direito ainda não implementado");
        }
    }
}

int inserirRB(No **r,int valor){
    No *noInserido;
    noInserido = inserir(r,valor);
    correcao(r,noInserido);
    (*r)->cor = PRETO;
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
