#include <stdio.h>
#include <stdlib.h>


#define TAM_TAB 13



typedef struct no {
    int dado;
    struct no *prox;
}No;

typedef struct tab_hash{
    No *pos[TAM_TAB];
    int qtd;
}Tab_Hash;

int menu();
int hash(int vlr);
void inicializar_tab_hash(Tab_Hash *tab);
void inserir_inicio(No **C, int vlr);
int buscar_lista(No **C, int vlr);
void inserir_tab_hash(Tab_Hash *tab,int vlr);
void remover_tab_hash();
int buscar_tab_hahs();
void mostrar_lista(No **C);
void mostrar_tab_hash(Tab_Hash *tab);
float fator_carga(Tab_Hash *tab);

int main(){
    int op;
    Tab_Hash tab;

    inicializar_tab_hash(&tab);

    do{
        op = menu();
        switch(op){

            case 0:
            printf("Obrigado \n");
            break;

            case 1:{
            inserir_tab_hash(&tab,10);
            inserir_tab_hash(&tab,20);

            }break;

            case 3:{
            int vlr;
            printf("Valor \n");
            scanf("%d",&vlr);
            if(buscar_tab_hahs(&tab,vlr)){
                printf("Elemento %i encontrado na tabela \n",vlr);
                }else{
                printf("Elemento %i não encontrado na tabela\n",vlr);
                }
            

            }break;

            case 4:{
            mostrar_tab_hash(&tab);

            }break;

            default : printf("OPCAO INVALIDA \n");
        }
    }while(op!=0);

    return 0;
}

//Funções para tabela Encadeada
//Funções para tabela Hash

int hash(int vlr){
    return (vlr*5)%TAM_TAB;
}

float fator_carga(Tab_Hash *tab){
    return tab->qtd / (float)TAM_TAB;
}

void inicializar_tab_hash(Tab_Hash *tab){
    int i;
    tab->qtd = 0;
    for(i=0;i<TAM_TAB;i++){
        tab->pos[i] = NULL;
    }

}

void inserir_inicio(No **C, int vlr){
    if(*C == NULL){
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = vlr;
        novo->prox = *C;
        *C = novo;
    }
}

void inserir_tab_hash(Tab_Hash *tab,int vlr){
    int h = hash(vlr);
    //printf("%i\n",h);

    inserir_inicio(&tab->pos[h],vlr);
    tab->qtd++;
}

void remover_tab_hash(){

}

int buscar_tab_hahs(Tab_Hash *tab, int vlr){
    int h = hash(vlr);
    return buscar_lista(&tab->pos[h],vlr);
}

void mostrar_lista(No **C){
    No *p;
    for(p = *C; p!=NULL; p=p->prox){
        printf("%i",p->dado);
    }
    printf("\n");
}

int buscar_lista(No **C, int vlr){
    No *p;
    for(p = *C; p!=NULL; p=p->prox){
        if(p->dado == vlr)
        return 1;
    }
    return 0;
}

void mostrar_tab_hash(Tab_Hash *tab){
    int i;
    printf("Mostrando a Tabela \n");
    for(i=0;i<TAM_TAB;i++){
        if(tab->pos[i] = NULL){
            mostrar_lista(&tab->pos[i]);
        }
    }
}

int menu(){
    int op;
    printf("[0] - SAIR \n");
    printf("[1] - Inserir \n");
    printf("[2] - REMOVER \n");
    printf("[3] - BUSCAR \n");
    printf("[4] - MOSTRAR TABELA \n");
    printf("[5] - FATOR DE CARAGA \n");
    scanf("%d",&op);
    printf("\n");
    return op;
}
