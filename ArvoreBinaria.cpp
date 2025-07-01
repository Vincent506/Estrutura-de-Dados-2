#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *direita;
    struct no *esquerda;
}No;

typedef struct 
{
    No *raiz;
    int quantidade;
}Tree;

void criar_arvore(Tree *arvore){
    arvore->quantidade = 0;
    arvore->raiz = NULL;
}

No *cria_no(){
    No *novo = new no;
    return novo;
}


void inserir(Tree *arvore, int num){
    No *novo = new No;
    No *aux = new No;
    if (novo)
    {
        novo->valor = num;
        if (arvore->raiz == NULL)
        {
            arvore->raiz = novo->direita;
        }else if (arvore->raiz != NULL && arvore->raiz->direita)
        {
            aux = arvore->raiz->direita;
            while (aux->direita != NULL)
            {
                if (aux->valor>num)
                {
                    aux = aux->direita;
                }else{
                    novo->direita = aux->direita;
                break;
                }
            }
        }else if (arvore->raiz != NULL && arvore->raiz->esquerda)
        {
            //verificação do numero menor na arvore terminar depois
        }
        
        arvore->quantidade++;
    }else{
        printf("\tErro ao alocar memoria\n");
    }
    
}

int main()
{
    Tree ArvoreBinaria;
    criar_arvore(&ArvoreBinaria);

    int option = -1;
    int elemento;
    while (option != 0)
    {
        printf("MENU DE OPÇOES\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Mostrar Arvore\n");
        printf("3 - Buscar\n");
        printf("0 - sair\n");
        printf("Digite a sua opção: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        system("clear");
            printf("Digite o elemento: ");
            scanf("%d",&elemento);
            inserir(&ArvoreBinaria, elemento);
            break;
        case 0:
        system("clear");
            printf("Saindo e fechando o programa....\n");
        break;
        default:
        printf("Digite uma opção valida");
            break;
        }
    }
    
    return 0;
}
