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



void ShellSort(int tamanho,int numeros[]){
    int gap=3;
    int percorre = tamanho-gap;
    while (gap>0){
         for (int i = 0; i < percorre; i++){
            if (numeros[i+gap]<numeros[i]){
                int aux = numeros[i];
                numeros[i] = numeros[i+gap];
                numeros[i+gap] = aux;
            }     
        }
        gap = gap/2;
        percorre = tamanho-gap;
    }
    for (int i = 0; i < tamanho-1; i++)
    {
        if (numeros[i+1]<numeros[i])
        {
            int prova = numeros[i];
            numeros[i] = numeros[i+1];
            numeros[i+1] = prova;
        }
        
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
    ShellSort(7,vetor);
    int aux = vetor[1];
    vetor[1] = vetor[2];
    vetor[2] = aux;
    printf("\nVetor Ordenado com ShellSort\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
}
