#include <stdio.h>
#include <stdlib.h>
void lervetor(int *vetor, int tam);
void imprimir(int *vetor,int tam);
int compararCrescente(const void* p1, const void* p2);
int compararDecrescente(const void* p1, const void* p2);
int lerVetorInteiro(int *vetor);
int menu();
int main(){
    int op=0;
    do{
        op = menu();
        switch(op){
            case 0:
            printf("Obrigado por Utilizar a aplicação \n");
            break;
            case 1:{
                int *vetor;
                int tam;
                printf("Informe o tamanho do Vetor \n");
                scanf("%d",&tam);
                lervetor(vetor,tam);
                qsort(vetor,tam,sizeof(int),compararCrescente);
                printf("-------CRESCENTE----------\n");
                imprimir(vetor,tam);
                qsort(vetor,tam,sizeof(int),compararDecrescente);
                printf("-------DECRESCENTE-------\n");
                imprimir(vetor,tam);
                free(vetor);

            }break;

            case 2:{
                int *vetor  = (int*) malloc(sizeof(int));
                int tam = lerVetorInteiro(vetor);
                imprimir(vetor,tam);
                qsort(vetor,tam,sizeof(int),compararCrescente);
                printf("-------CRESCENTE----------\n");
                imprimir(vetor,tam);
                qsort(vetor,tam,sizeof(int),compararDecrescente);
                printf("-------DECRESCENTE-------\n");
                imprimir(vetor,tam);
                free(vetor);
            
            }break;

            case 3:{
                int *vetor;
                int tam;
                int contadorpar;
                int contadorimpar;
                int i=0;
                printf("Informe o tamanho do Vetor \n");
                scanf("%d",&tam);
                vetor = (int*)malloc(tam*sizeof(int));
                lervetor(vetor,tam);
                if(vetor[i] % 2 == 0)
                contadorpar++;
                else
                contadorimpar--;
                printf("%d %d",contadorpar,contadorimpar);
        

            }break;

            default: printf("Opção Invalida \n");
        }
    }while(op != 0);
    return 0;
}

void lervetor(int *vetor, int tam){
int i=0;
for(;i<tam;i++){
    printf("Informe a posição V[%d] \n",i);
    scanf("%d",&vetor[i]);
    }      
}

int compararCrescente(const void* p1, const void* p2){
    if(*(int*)p1 == *(int*)p2) return 0;
    else if( *(int*)p1 < *(int*)p2 )
    return -1;
    else return 1;
}

int compararDecrescente(const void* p1, const void* p2){
    if(*(int*)p1 == *(int*)p2) return 0;
    else if( *(int*)p1 < *(int*)p2 )
    return 1;
    else return -1;
}


void imprimir(int *vetor,int tam){
    int i=0;
    for(;i<tam;i++){
        printf("v[%d] = %d \n",i,vetor[i]);
    }
}
int menu(){
    int op;
    printf("-----INFORME A OPÇÃO DESEJADA-----\n");
    printf("1-CRESCENTE E DECRESCENTE \n");
    printf("2 -LER VETOR E PARAR A EXECUÇÃO QUANDO VALOR FOR NEGATIVO\n");
    printf("3 - Exercicio 3\n");
    scanf("%d",&op);
    return op;
}
int lerVetorInteiro(int *vetor){
    int tamanho= 0 ; 
    int leitura;
        do{
            printf("Informe o valor do V[%d] \n",tamanho +1);
            scanf("%d",&leitura);

            if(leitura < 0) break;
            vetor = realloc(vetor,(tamanho + 1 ) * sizeof(int));
            vetor[tamanho] = leitura;
            tamanho = tamanho + 1; 
        }while(1);

    return tamanho; 
}

