#include<stdlib.h>
#include<stdio.h>

//esturtura de uma lista encadeada simples
typedef struct no
{
    int valor;
    struct no *proximo;
}No;

//procedimento para inserir no inicio
void inserir_no_inicio(No **lista, int num){

    No *novo = (No*)malloc(sizeof(No));  
    if (novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria");
    }
}

void mostrar(No *cabeca){

    No *percorre = cabeca;
    
    if (cabeca == NULL)
    {
        system("clear");
        printf("Lista vazia");
    }
        while (percorre != NULL)
        {
            printf("%d - ", percorre->valor);
            percorre = percorre->proximo;
        }
        printf("\n");
    }

//testando as funções
int main()
{
    No *listaSimples = NULL;
    int option = -1;
    while (option != 0)
    {
        printf("MENU DE OPÇÕES\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - Mostrar a Lista\n");
        printf("0 - Sair e fechar o programa\n");
        printf("O que deseja fazer? ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:
        system("clear");
            printf("Digite um numero inteiro: ");
            int elemento;
            scanf("%d",&elemento);
            inserir_no_inicio(&listaSimples, elemento);
            
            printf("\nValor %d adicionado com sucesso!!\n\n",elemento);
            break;

            case 2:
            system("clear");
            printf("Lista simplesmente encadeada:\n");
            mostrar(listaSimples);
            break;
            case 0:
            system("clear");
            printf("fechando o programa....\n");
            break;
        
        default:
        system("clear");
            printf("Digite uma opção valida!!\n");
            break;
        }
    }
    return 0;
}



