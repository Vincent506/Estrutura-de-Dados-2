#include<stdlib.h>
#include<stdio.h>


typedef struct no
{
    int valor;
    struct no *proximo;
}No;
typedef struct 
{
    No *inicio;
    int tam;
}Lista;

void criar_Lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;

}

void inserir_no_inicio(Lista *lista, int num){

    No *novo = (No*)malloc(sizeof(No));  
    if (novo)
    {
        
        novo->valor = num;
        
        novo->proximo = lista->inicio;
        
        lista->inicio = novo;
        lista->tam++;
    }else{
        printf("Erro ao alocar memoria");
    }
}
void inserir_no_meio(Lista *lista, int num, int ant){
    No *novo = (No*)malloc(sizeof(No));
    No *aux = (No*)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while (aux->valor!=ant && aux->proximo)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
        
    }else{
        system("clear");
        printf("Erro ao alocar memoria");
    }
    
}

void inserir_no_final(Lista *lista, int num){
    No *aux,*novo = (No*)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
        }else
        {
            aux = lista->inicio; 
            while (aux->proximo){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        lista->tam++;
        }
    }
}
void inserir_ordenado(Lista *lista, int num){
    No *novo = (No*)malloc(sizeof(No));
    No *aux = (No*)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }else if (novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else
        {
            aux = lista->inicio;
            while (aux->proximo && novo->valor> aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }else{
    system("clear");
        printf("Erro ao alocar memoria!!!\n");
    }
}

void mostrar(Lista lista){

    No *percorre = lista.inicio;
   
    if (percorre == NULL)
    {
        system("clear");
        printf("Lista vazia\n");
    }else{
    
    printf("Lista simplesmente encadeada de tamanho %d:\n",lista.tam);
        while (percorre != NULL)
        {
      
            printf("%d - ", percorre->valor);
            
            percorre = percorre->proximo;
        }
        printf("FIM\n");
    }
}

int main()
{

    Lista listasimples;
    criar_Lista(&listasimples);
    int elemento;
    int option = -1;
    while (option != 0)
    {
        printf("MENU DE OPÇÕES\n");
        printf("1 - Adicionar elemento no inicio da lista\n");
        printf("2 - Adicionar elemento no meio da lisata\n");
        printf("3 - Adicionar elemento no final da lista\n");
        printf("4 - Inserir elemento ordenado\n");
        printf("5 - Mostrar a Lista\n");
        printf("0 - Sair e fechar o programa\n");
        printf("O que deseja fazer? ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:
        system("clear");
            printf("Digite um numero inteiro: ");
            
            scanf("%d",&elemento);
           inserir_no_inicio(&listasimples, elemento);
            
            printf("\nValor %d adicionado com sucesso!!\n\n",elemento);
            break;
            case 2:
        system("clear");
            printf("Digite um numero inteiro: ");

            scanf("%d", &elemento);
            printf("Digite o elemento anterior: ");

            int anterior;
            scanf("%d", &anterior);
            inserir_no_meio(&listasimples,elemento, anterior);

            printf("\nValor %d adicionado com sucesso!!!\n\n",elemento);
            break;
            case 3:
        system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &elemento);
            inserir_no_final(&listasimples, elemento);
            printf("\nValor %d adicionado com sucesso!!\n\n",elemento);
            break;
            case 4:
            system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &elemento);
            inserir_ordenado(&listasimples, elemento);
            printf("\nValor %d adicionado com sucesso!!\n\n",elemento);
            break;

            case 5:
            system("clear");
            
            mostrar(listasimples);
            
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



