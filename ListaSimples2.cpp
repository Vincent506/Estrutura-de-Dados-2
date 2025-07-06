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
        novo->elemento = elemento;
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
        }
    }else{
        printf("Erro ao alocar memoria");
    }
}

void mostrar(No*lista){
    No *aux = lista;
    
    if (lista != NULL)
    {
        printf("Lista Simplesmente encadeada: \n");
        while (aux)
        {
        printf("%d - ", aux->elemento);
        aux = aux->proximo;
        }
        printf("FIM");
    }else{
        printf("Lista vazia!!");
    }
}

int main(){
    No *listasimples = NULL;
    int option = -1;
    int conteudo;

    while (option != 0)
    {
        printf("\t===MENU DE OPÇOES ===\n\n");
        printf("1 -  inserir no inicio;\n");
        printf("2 - inserir no final;\n");
        printf("3 - mostrar lista\n");
        printf("0 - sair e fechar o programa\n");
        printf("Digite a sua opção: ");
        scanf("%d", &option);
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
            mostrar(listasimples);
            break;
        default:
        system("clear");
            printf("Digite uma opção válida\n");
            break;
        }
    }
    
    return 0;
}
