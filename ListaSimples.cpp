#include<stdlib.h>
#include<stdio.h>

//Esturtura de uma lista encadeada simples
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
//Função para inserir no inicio
//dentro da nossa struct nos temos um endereço de memoria, e
//para acessa-lo usaremos ponteiro pra ponteiro (No **lista)
//e o valor que iremos adicionar(int num)
void inserir_no_inicio(Lista *lista, int num){
//cria se um ponteiro que vamos usar como um espaço vazio
//utilizamos a função malloc para reservar esse espaço de memoria
    No *novo = (No*)malloc(sizeof(No));  
    if (novo)
    {
        //Dentro da nossa condição de criação desse ponteiro
        //vamos preenche-lo. Conlocamos o "num" do paramentro 
        //da função na variavel dentro de "valor".
        novo->valor = num;
        //O ponteiro de "novo" vai apontar para o ponteiro da
        //"lista" que foi parametro da nossa função
        novo->proximo = lista->inicio;
        //por fim o endereço da estrutura do parametro vai receber o 
        //espaço de memoria que nos haviamos separado. Agora preenchido 
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
//função para mostrar a lista encadeada
void mostrar(Lista lista){
//criar um ponteiro que percorre a nossa lista
    No *percorre = lista.inicio;
    //se a lista estiver vazia imprime uma mensagem 
    if (percorre == NULL)
    {
        system("clear");
        printf("Lista vazia\n");
    }else{
    //se não, usamos uma estrutura de repetição while para percorrer a lista
    //ate o ponteiro "percorre" ou seja o fim da nossa lista 
    printf("Lista simplesmente encadeada de tamanho %d:\n",lista.tam);
        while (percorre != NULL)
        {
            //exibe o valor inteiro
            printf("%d - ", percorre->valor);
            //percorre recebe ele mesmo apontando para o proximo
            percorre = percorre->proximo;
        }
        printf("FIM\n");
    }
}

//Dentro desse programa nos temos uma lista encadeada onde so adicionamos 
//elementos no topo, no final da lista e exibimos.
int main()
{
    //No *listaSimples = NULL;
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
        printf("4 - Mostrar a Lista\n");
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



