#include<stdlib.h>
#include<stdio.h>

//esturtura de uma lista encadeada simples
typedef struct no
{
    int valor;
    struct no *proximo;
}No;

//Função para inserir no inicio
//dentro da nossa struct no temos um endereço de memoria
//para acessa-lo usaremos ponteiro pra ponteiro (No **lista)
//e o valor que iremos adicionar(int num)
void inserir_no_inicio(No **lista, int num){
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
        novo->proximo = *lista;
        //por fim o endereço da estrutura do parametro vai receber o 
        //espaço de memoria que nos haviamos separado. Agora preenchido 
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria");
    }
}

void inserir_no_final(No **lista, int num){
    No *novo,*aux = (No*)malloc(sizeof(No));
    if (*lista == NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
        *lista = novo;
    }else{
        while (aux->proximo!=NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}
//função para mostrar a lista encadeada
void mostrar(No *cabeca){
//criar um ponteiro que percorre a nossa lista
    No *percorre = cabeca;
    //se a lista estiver vazia imprime uma mensagem 
    if (cabeca == NULL)
    {
        system("clear");
        printf("Lista vazia");
    }
    //se não, usamos uma estrutura de repetição while para percorrer a lista
    //ate o ponteiro "percorre" ou seja o fim da nossa lista 
        while (percorre != NULL)
        {
            //exibe o valor inteiro
            printf("%d - ", percorre->valor);
            //percorre recebe ele mesmo apontando para o proximo
            percorre = percorre->proximo;
        }
        printf("\n");
    }

//Dentro desse programa nos temos uma lista encadeada onde so adicionamos 
//elementos no topo da lista e exibimos.
int main()
{
    No *listaSimples = NULL;
    int elemento;
    int option = -1;
    while (option != 0)
    {
        printf("MENU DE OPÇÕES\n");
        printf("1 - Adicionar elemento no inicio da lista\n");
        printf("2 - Adicionar elemento no final da lista\n");
        printf("3 - Mostrar a Lista\n");
        printf("0 - Sair e fechar o programa\n");
        printf("O que deseja fazer? ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:
        system("clear");
            printf("Digite um numero inteiro: ");
            
            scanf("%d",&elemento);
            inserir_no_inicio(&listaSimples, elemento);
            
            printf("\nValor %d adicionado com sucesso!!\n\n",elemento);
            break;
            case 2:
        system("clear");
            printf("Digite um numero inteiro");
            scanf("%d", &elemento);
            inserir_no_final(&listaSimples, elemento);
            break;

            case 3:
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



