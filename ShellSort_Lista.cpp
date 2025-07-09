#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct No
{
    int valor;
    struct No *proximo;
}no;


typedef struct lista
{
    int tamanho;
    no *inicio;
}LS;

void inserir_no_final(LS *lista, int num){
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
        lista->tamanho++;
        }
    }
}

void preencher(LS *lista, int tamanho){
    int valor;
    for (int i = 0; i < tamanho; i++)
    {
        valor= rand()%tamanho;
        inserir_no_final(lista,valor);
    }
}

void mostrar(LS *lista){
    no *exibir = new no;
    exibir = lista->inicio;

    printf("\nLista Simples\n");
    while (exibir)
    {
        printf("%d - ", exibir->valor);
        exibir = exibir->proximo;
    }
    printf("FIM\n\n");
}

void swap(LS *lista, no *a, no *b){
    no *aux = new no;
    if (lista->inicio == a)
    {
        aux = a;
        a = lista->inicio;
        lista->inicio = aux;
    }else if (lista->inicio == b)
    {
        aux = b;
        b = lista->inicio;
        lista->inicio = aux;
    }else{
        aux = a;
        a = b;
        b = aux;
    }
}

No* passar(no *aux, int tam){
    tam = tam -1;
    if (aux != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            aux = aux->proximo;
        }
        return aux;
    }else{
        return NULL;
    }
}

void ShellSort(LS *lista){
    int gap = lista->tamanho/2;
    no *normal = new no;
    no *sub = new no;
    normal = lista->inicio;
    while (gap>0)
    {
        for (int i = 0; i < lista->tamanho; i++)
        {
            for (int j = i; j+gap < lista->tamanho; i++)
            {
                if (normal!= NULL && sub != NULL)
                {
                    if (normal->valor>sub->valor)
                    {
                    swap(lista, normal,sub);
                    }
                    normal = passar(normal, j); 
                    sub = passar(normal, j+gap);
                }
            }
        }
        gap = gap/2;
    }
}


int main()
{
    srand(time(NULL));
    LS *ListaSimples = new LS;
    int tam;
    printf("\nDigite o tamanho da sua lista: ");
    scanf("%d", &tam);
    preencher(ListaSimples,tam);
system("clear");
    
    mostrar(ListaSimples);
    
    //ShellSort(ListaSimples);
    printf("\nqual numero quer trocar?: ");
    
    
    mostrar(ListaSimples);
    return 0;
}
