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

void inserir_no_meio(No **lista,int anterior, int elemento){
    No *novo = new No;
    if (novo)
    {
        novo->elemento = elemento;
        if (lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }else{
            No *aux = new No;
            aux = *lista;
            while (aux->proximo != NULL && aux->elemento != anterior)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;   
        }
    }else{
        printf("Erro ao alocar memoria");
    }
}

void inserir_ordenado(No **lista, int elemento){
    No *novo = new No;
    No *aux = new No;
    aux = *lista;
    if (novo)
    {
        novo->elemento = elemento;
        if (lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }else if (novo->elemento > aux->proximo->elemento)
        {
            novo->proximo = aux->proximo;
            inserir_no_inicio(lista, novo->elemento);
        }else{
            while (aux->proximo != NULL && novo->elemento > aux->elemento )
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }else{
    system("clear");
        printf("Erro ao alocar memoria");
    }
}

No* buscar(No **lista, int busca){
    No *pesquisa =  new No;
    No *aux = new No;
    aux = *lista;
    pesquisa = NULL;
    if (aux != NULL)
    {
        if (aux->elemento == busca)
        {
            pesquisa = aux->proximo;
        }else{
            while (aux->proximo != NULL && aux->proximo->elemento != busca)
            {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            {
                pesquisa = aux->proximo;
            }
        }
    }
    return pesquisa;
}

No* remover(No **lista, int lixo){
    No *lixeira = new No;
    lixeira = NULL;
    No *aux = new No;
    aux = *lista;
    if (aux != NULL)
    {
        if (aux->elemento == lixo)
        {
            lixeira = *lista;
            *lista = lixeira->proximo;
        }else{
            while (aux->proximo != NULL && aux->proximo->elemento != lixo)
            {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            {
                lixeira = aux->proximo;
                aux->proximo = lixeira->proximo;
            }   
        }
    }
    return lixeira;
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
        printf("FIM\n\n");
    }else{
        printf("\nLista vazia!!\n");
    }
}

int main(){
    No *listasimples = NULL;
    int option = -1;
    int conteudo;
    int referencia;
    No *search = new No;

    while (option != 0)
    {
        printf("\n\t===MENU DE OPÇOES ===\n\n");
        printf("1 - inserir no inicio;\n");
        printf("2 - inserir no meio;\n");
        printf("3 - inserir no final;\n");
        printf("4 - inserir ordenado;\n");
        printf("5 - mostrar lista\n");
        printf("6 - buscar elemento;\n");
        printf("7 - remover elemento;\n");
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
            printf("\nElemento adicionado com sucesso!!\n\n");
            break;
            case 2:
        system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &conteudo);
        system("clear");
            mostrar(listasimples);
            printf("Digite um numero anterio para inserir %d: ", conteudo);
            scanf("%d", &referencia);
            inserir_no_meio(&listasimples, referencia, conteudo);
            printf("\nElemento adicionado com sucesso!!\n\n");
            break;
        case 3: 
        system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &conteudo);
            inserir_no_final(&listasimples,conteudo);
            printf("\nElemento adicionado com sucesso!!\n\n");
            break;
            case 4:
        system("clear");
            printf("Digite um numero inteiro: ");
            scanf("%d", &conteudo);
            inserir_ordenado(&listasimples, conteudo);
            printf("\nElemento adicionado com sucesso!!\n\n");
            break;
            case 5:
        system("clear");
            mostrar(listasimples);
            break;
            case 6:
        system("clear");
            printf("Digite o elemento que esta procurando: ");
            scanf("%d", &conteudo);
            search = buscar(&listasimples, conteudo);
            
            if (search != NULL)
            {
                printf("Elemento encontrado");
            }else{
                printf("Elemento inexistente");
            }
            break;
            case 7:
        system("clear");
            mostrar(listasimples);
            printf("Digite o elemento que deseja remover: ");
            scanf("%d", &conteudo);
            search = remover(&listasimples, conteudo);
            if (search != NULL)
            {
                free(search);
            }else{
                printf("Elemnto não encontrado");
            }
            break;
            case 0:
        system("clear");
            printf("Saindo e fechando o programa....\n\n");
            break;
        default:
        system("clear");
            printf("Digite uma opção válida\n");
            break;
        }
    }
    
    return 0;
}
