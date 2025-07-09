#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void full(  int vetor[]){
    for (int i = 0; i < 8; i++)
    {
        vetor[i] = rand()%8;
    }
    printf("Vetor preenchido com sucesso!!");
}

void troca( int *vetor, int i, int j){
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}



void ShellSort(int tamanho,int numeros[]){
    int gap= tamanho/2;
    while (gap>0){
         for (int j = 0; j < tamanho; j++){
            for (int i = j; i + gap < tamanho; i+=gap)
            {
                if (numeros[i+gap]<numeros[i]){
                    troca(numeros, i, i+gap);
                }  
            }
        }
        gap = gap/2;
    }
}


int main()
{
    srand(time(NULL));
    //printf("Digite o tamanho do vetor que desejar.");
    //scanf("%d",&tamanho);
    int vetor[7];
    //full(vetor);
    vetor[0] = 29;
    vetor[1] = 12;
    vetor[2] = 45;
    vetor[3] = 22;
    vetor[4] = 6;
    vetor[5] = 38;
    vetor[6] = 15;
    printf("\nVetor Original\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",vetor[i]);
    }
    ShellSort(8,vetor);
    printf("\nVetor Ordenado com ShellSort\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
}
