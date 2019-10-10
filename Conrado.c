#include "stdio.h"
#include <stdlib.h>

typedef enum{
    VERMELHO, PRETO
}Cor;

typedef struct no{
    Cor cor;
    int dado;
    struct no *esq, *dir, *pai;
}No;

void RSE(No **r){
    No *aux;
    aux = *r;
    *r = (*r)->dir;
    aux->dir = (*r)->esq;
    (*r)->esq = aux;

    (*r)->pai = aux->pai;
    aux->pai = *r;
    if(aux->dir != NULL){
        aux->dir->pai = aux;
    }
}
void RSD(No **r){
    No *aux;
    aux = *r;
    *r = (*r)->esq;
    aux->esq = (*r)->dir;
    (*r)->dir = aux;

    (*r)->pai = aux->pai;
    aux->pai = *r;
    if(aux->esq != NULL){
        aux->esq->pai = aux;
    }
}
void preOrdem(No **r){
    if(*r != NULL){
        if((*r)->cor == VERMELHO)
            printf("VERMELHO  ");
        else 
            printf("PRETO  ");
        if((*r)->pai == NULL){
            printf("%d   [RAIZ]  \n",(*r)->dado);
        }else{
            printf("%i [PAI: %i]\n",(*r)->dado, (*r)->pai->dado);
        }    
            preOrdem(&(*r)->esq);
           preOrdem(&(*r)->dir);
    }
}
No* inserir(No **r, int valor){
    if(*r == NULL){
        No *novo;
        novo = (No*)malloc(sizeof(No));
        novo->dado = valor;
        novo->pai = NULL;
        novo->dir = NULL;
        novo->cor = VERMELHO;
        novo->esq = NULL;
        *r = novo;
        return novo;
    }else{
        No *retorno;
        if(valor > (*r)->dado){
            retorno = inserir(&(*r)->dir, valor);
            (*r)->dir->pai = *r;
        }else{
            if(valor < (*r)->dado){
                retorno = inserir(&(*r)->esq, valor);
                (*r)->esq->pai = *r;
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
void corrigir_pai_esquerda(No **r, No *avaliado){
    No *pai = avaliado->pai;
    No *avo = pai->pai; 
    No *tio = avo->dir;

    if(eh_vermelho(tio)){ // 1º caso
    printf("CASO 1 pai é filho esquerdo \n");
        pai->cor = PRETO;
        avo->cor = VERMELHO;
        tio->cor = PRETO;
        //preOrdem(&avo);

        avaliado = avo;
    }else{
        if(pai->dir == avaliado){ // 2º caso
            printf("CASO 2 pai é filho esquerdo \n");
            if(avo == NULL){
                RSE(&pai);
                *r = pai;
            }else{
                if(avo->esq == pai){
                    RSE(&pai);
                    avo->esq = pai;
                }else{
                    avo->dir = pai;
                }
            }
            avaliado = pai->esq;
        }
        printf("CASO 3 pai é filho esquerdo \n");

        if(avo->pai == NULL){
            RSD(&avo);
            *r = avo;
        }else{
            RSD(&avo);
            avo->pai->dir = avo;
        }
        pai->cor = PRETO;
        pai->dir->cor = VERMELHO;
        //preOrdem(&avo);
        //exit(0);
    }
}

void corrigir_pai_direita(No **r, No *avaliado){
    No *pai = avaliado->pai;
    No *avo = pai->pai; 
    No *tio = avo->esq;

    if(eh_vermelho(tio)){ // 1º caso
    printf("CASO 1 pai é filho direito \n");
        pai->cor = PRETO;
        avo->cor = VERMELHO;
        tio->cor = PRETO;
        //preOrdem(&avo);

        avaliado = avo;
    }else{
        if(pai->esq == avaliado){ // 2º caso
            printf("CASO 2 pai é filho direito \n");
            if(avo == NULL){
                RSD(&pai);
                *r = pai;
            }else{
                if(avo->dir == pai){
                    RSD(&pai);
                    avo->dir = pai;
                }else{
                    avo->esq = pai;
                }
            }
            avaliado = pai->dir;
        }
        printf("CASO 3 pai é filho direito \n");

        if(avo->pai == NULL){
            RSE(&avo);
            *r = avo;
        }else{
            RSE(&avo);
            avo->pai->esq = avo;
        }
        pai->cor = PRETO;
        pai->esq->cor = VERMELHO;
        //preOrdem(&avo);
        //exit(0);
    }
}
void correcao(No **r, No *avaliado){
    while(avaliado->pai != NULL){
        if(avaliado->pai->cor == PRETO)
            break;

        No *pai = avaliado->pai;
        No *avo = pai->pai;
        if(avo->esq == pai){ // e um filho a esquerda
            // corrigir pai que e filho a esquerda
            corrigir_pai_esquerda(r,avaliado);

        }else{ // pai e filho a direita
            corrigir_pai_direita(r,avaliado);
        }
    }
}

int inserirRB(No **r, int valor){
    No *noInserido;
    noInserido = inserir(r,valor);
    correcao(r,noInserido);
    (*r)->cor = PRETO;
}

int existe_n(No **r, int n){
    if(*r == NULL) return 0;
    if((*r)->dado == n) return 1;
    if( n > (*r)->dado) return existe_n(&(*r)->dir,n);
    return existe_n(&(*r)->esq,n);
}
No* maiorElemento(No **r){
    if(*r == NULL) return NULL;
    No* p; 
    for(p = *r; p->dir != NULL; p=p->dir);
    return p;
}
No* temFilhoVermelho(No **r){
    if(*r == NULL){
        printf("Caso estranho \n");
        exit(0);
    }
    if((*r)->dir == NULL && (*r)->esq == NULL){
        printf("Não possui filho \n");
        return NULL;
    }
    if((*r)->esq == NULL){
        printf("Possui filho a direita \n");

        if((*r)->dir->cor == VERMELHO){
            return (*r)->dir;
        }

    }if((*r)->dir == NULL){
        printf("Possui filho a esquerda \n");

        if((*r)->esq->cor == VERMELHO){
            return (*r)->esq;
        }

    }
    return NULL;
}

void corrigirRemocao(No **r){
    if(eh_vermelho(*r)){
        return;
    }
    No * TFV;
    TFV = temFilhoVermelho(r);
    if(TFV != NULL){
        TFV->cor = PRETO;
    }else{
        printf("em construção... \n");
        
    }
}

int remover(No **r, int vlr){
    if(*r == NULL) return 0;
    if((*r)->dado == vlr){
        if((*r)->esq == NULL){

            corrigirRemocao(r);

            No *aux; 
            aux = *r;
            *r = (*r)->dir;
            if(*r != NULL){
                (*r)->pai = aux->pai;
            }
            free(aux);
            return 1;
        }if((*r)->dir == NULL){

            corrigirRemocao(r);

            No *aux; 
            aux = *r;
            *r = (*r)->esq;
            if(*r != NULL){
                (*r)->pai = aux->pai;
            }
            free(aux);
            return 1;
        }
        No *aux = maiorElemento(&(*r)->esq);
        (*r)->dado = aux->dado;
        return remover(&(*r)->esq,(*r)->dado);
    }
    if(vlr >(*r)->dado) return remover(&(*r)->dir,vlr);
    return remover(&(*r)->esq,vlr);
}
int menu()
{
    int x;

    printf("------MENU------\n");
    printf("\n");
    printf("[0] -> Sair\n");
    printf("[1] -> Inserir\n");
    printf("[2] -> Pre ordem\n");
    printf("[3] -> Remover\n");
    printf("[4] -> RSE\n");
    printf("[5] -> \n");
    printf("[6] -> \n");
    printf("\n");
    printf("Informe a operacao desejada: ");
    scanf("%d", &x);
    printf("\n");
    return x;
}
int main(){
    No *r = NULL;
    int op, valor, *qtd;
    qtd = (int *) malloc(sizeof(int));
    (*qtd) = 0;
    No *aux;
    do
    {
        op = menu();
        switch (op)
        {
        case 0:
            printf("Sair da Aplicacao!\n");
            break;

        case 1:{
            printf("Valor: ");
            scanf("%i", &valor);
            inserirRB(&r, valor);
            printf("Elemento %i inserido com sucesso!\n", valor);
        }break;
        
            break;

        case 2:
            printf("Impressao em pre ordem..\n");
            preOrdem(&r);
            break;

        case 3:
            scanf("%d",&valor);
            if(existe_n(&r,valor))
            remover(&r,valor);
            else printf("Não existe esse valor \n");
            break;

        case 4:
            RSE(&r);
            break;
        case 5:
            
            break;
        case 6:
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            
            break;
    }
    } while (op != 0);

    return 0;
}
