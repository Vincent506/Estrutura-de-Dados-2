#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
    int elemento;
    struct no *proximo;
    
}No;


void inserir_no_inicio(No **lista, int elemento){

    No *novo =  new No;

    if (novo)
    {
        novo->elemento = elemento;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria");
    }
}

void inserir_no_final(No **lista, int elemento){
    No *novo = new No;

    if (novo)
    {
        novo->elemento = NULL;
        novo->proximo =  NULL;
        if (*lista == NULL)
        {
            *lista = novo;
        }else{
            No *aux = *lista;
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            *lista = aux->proximo;
        }
    }else{
        printf("Erro ao alocar memoria");
    }
}

void mostrar(){
    //
}

int main(){
    No *listasimples = NULL;
    int option = -1;
    int conteudo;
    printf("\t===MENU DE OPÇOES ===\n\n");
    printf("1 -  inserir no inicio;\n");
    printf("2 - inserir no final;\n");
    printf("3 - mostrar lista");
    printf("0 - sair e fechar o programa\n");

    while (option != 0)
    {
        switch (option)
        {
        case 1:
        system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &conteudo);
            inserir_no_inicio(&listasimples,conteudo);
            break;
        case 2: 
        system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &conteudo);
            inserir_no_final(&listasimples,conteudo);
            break;
            case 3:
        system("clear");
            
            break;
        default:
            break;
        }
    }
    
    return 0;
}
