#include <stdio.h>
#include <stdlib.h>


int main(){

 int **matriz;
 int i,j;
 int par = 0;
 matriz = (int**) malloc(sizeof(int*)*5); //alocando dimensao 1

 if(matriz!=NULL)
 printf("Matriz alocada com succeso\n");
 else
 printf("Não foi alocada \n");

 for (i = 0; i < 5;i++){
    matriz[i] = (int*) malloc(sizeof(int)*3);
   
 }

 for (i = 0;i < 5;i++){
    for (j = 0;j < 3;j++){
        matriz[i][j] = par;
        par=par+2;
        
    }
   
 }

  for (i = 0;i < 5;i++){
    for (j = 0; j < 3;j++){
        printf("[%d]",matriz[i][j]);
    }
    printf("\n");
 }
 
 for(i=4; i>=0;i--){
  free(p[i]);
  
  free(p);

    return 0;
}
