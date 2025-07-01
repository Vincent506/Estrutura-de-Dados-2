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

void criar_raiz(Tree *arvore, int valor){
    arvore->raiz->direita = NULL;
    arvore->raiz->esquerda = NULL;
    arvore->raiz->valor = valor;
    arvore->quantidade++;
}

int main()
{
    printf("hello word");
    return 0;
}
