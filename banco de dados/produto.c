#include <stdio.h>
#include <stdlib.h>

struct produto{
    char nome[50];
    char marca[50];
    char data_fabricacao[10];
    int codigo_barras;
    float preco_compra;
    float preco_venda;
};

typedef struct produto Produto;

int menu();

int main(){
    int op;
    int qtd_prod;
    printf("Informe a quantidade de Produto \n");
    scanf("%d",&qtd_prod);
    Produto *listaprod = NULL;

    do{
        op =menu();
        switch(op){

            case 'S':
            printf("Obrigado \n");
            break;

            case 1:{
                Produto novoprod;

                listaprod = malloc(qtd_prod*sizeof(Produto));

                printf("Nome: ");
                scanf("%s", novoprod.nome);
                printf("Marca: ");
                scanf("%s", novoprod.marca);
                printf("Data de fabricacao: ");
                scanf("%s", novoprod.data_fabricacao);
                printf("Codigo de barras: ");
                scanf("%d", &novoprod.codigo_barras);
                printf("Preco de compra: ");
                scanf("%f", &novoprod.preco_compra);
                printf("Preco de venda: ");
                scanf("%f", &novoprod.preco_venda);
             
                /*if(listaprod == NULL) listaprod = malloc(sizeof(Produto));
                else listaprod = realloc(listaprod,(qtd_prod+1)*sizeof(Produto));
                listaprod[qtd_prod-1] = novoprod;
                printf("Produto adicionado com sucesso\n\n");
                */
            }
            break;
            case 2:{
                int cod, achouprod = 0;
                printf("Digite o codigo de barras do produto a ser alterado: ");
                scanf("%d", &cod);
                for(int i=0;i<qtd_prod;i++){
                    if(listaprod[i].codigo_barras == cod){
                        printf("Novo nome: ");
                        scanf("%s", listaprod[i].nome);
                        printf("Nova marca: ");
                        scanf("%s", listaprod[i].marca);
                        printf("Nova data de fabricacao: ");
                        scanf("%s", listaprod[i].data_fabricacao);
                        printf("Novo codigo de barras: ");
                        scanf("%d", &listaprod[i].codigo_barras);
                        printf("Novo preco de compra: ");
                        scanf("%f", &listaprod[i].preco_compra);
                        printf("Novo preco de venda: ");
                        scanf("%f", &listaprod[i].preco_venda);
                        printf("Produto alterado com sucesso\n\n");
                        achouprod = 1;
                    }
                }
                if(!achouprod) printf("Produto nao encontrado\n\n");
            }
            break;
            case 3:{
                for(int i=0;i<qtd_prod;i++){
                    printf("Nome: %s\nMarca: %s\nData de fabricacao: %s\nCodigo de barras: %d\nLucro: %.2f\n\n", listaprod[i].nome, listaprod[i].marca, listaprod[i].data_fabricacao, listaprod[i].codigo_barras, listaprod[i].preco_venda-listaprod[i].preco_compra);
                }
            }
            break;
            case 0:{
                free(listaprod);
            }
            break;
            default: printf("Opcao invalida\n\n");
        }
    }while(op != 0);

    return 0;
}

int menu(){
    int op;
    printf("S - Para Sair \n");
    printf("1 - Adicionar Produto \n");
    printf("2 - Alterar Produto \n");
    printf("Mostrar Todos os Produtos \n");
    scanf("%d",&op);
    return op;
}