// Mariana Nunes Terol - UC22200554 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    struct Produto* proximo;
};

typedef struct Produto Produto;

Produto* criarProduto(char nome[], float preco) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->preco = preco;
    novoProduto->proximo = NULL;
    return novoProduto;
}

Produto* inserirOrdenado(Produto* cabeca, char nome[], float preco) {
    Produto* novoProduto = criarProduto(nome, preco);

    if (cabeca == NULL || strcmp(nome, cabeca->nome) < 0) {
        novoProduto->proximo = cabeca;
        return novoProduto;
    }

    Produto* atual = cabeca;
    while (atual->proximo != NULL && strcmp(nome, atual->proximo->nome) > 0) {
        atual = atual->proximo;
    }

    novoProduto->proximo = atual->proximo;
    atual->proximo = novoProduto;

    return cabeca;
}

void imprimirListaDeProdutos(Produto* cabeca) {
    Produto* atual = cabeca;
    while (atual != NULL) {
        printf("%s - R$%.2f\n", atual->nome, atual->preco);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(void) {
    int tamanho;
    char nome[50];
    float preco;
    Produto* listaDeProdutos = NULL;

    printf("Digite o numero de produtos: ");
    scanf("%d", &tamanho);

    printf("Digite %d produtos para a lista ordenada:\n", tamanho);
    for (int i = 0; i < tamanho; ++i) {
        printf("Digite o nome do produto: ");
        scanf(" %[^\n]s", nome); 
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Digite o preco do produto: ");
        scanf("%f", &preco);

        listaDeProdutos = inserirOrdenado(listaDeProdutos, nome, preco);
    }

    printf("Lista de Produtos Ordenada:\n");
    imprimirListaDeProdutos(listaDeProdutos);

    Produto* atual = listaDeProdutos;
    while (atual != NULL) {
        Produto* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
