
#include <stdio.h>
#include <stdlib.h>

void ler_vetor(float *vetor, int alunos);
float soma(float *vetor,int alunos);
float media(float *vetor,int alunos);
int main(){

int alunos;
float *vetor;
printf("Informe a quantidade de alunos \n");
scanf("%d",&alunos);
vetor = (float*)malloc(alunos *sizeof(float));
ler_vetor(vetor,alunos);
printf("A soma sera de %.2f\n",soma(vetor,alunos));
printf("O resultado da media sera de %.2f\n",soma(vetor,alunos)/alunos);

free(vetor);
 
return 0;
}

void ler_vetor(float *vetor, int alunos){
    int i =0;
    for(;i<alunos;i++){
        printf("Informe a nota do V[%d] \n",i+1);
        scanf("%f",&vetor[i]);
    }
}

float soma(float *vetor,int alunos){
    if(alunos==0)
    return vetor[0];
    else
    return vetor[alunos]+soma(vetor,alunos-1);
}