// Mariana Nunes Terol - UC22200554 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* criarNo(int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = valor;
    novoNo->next = NULL;
    return novoNo;
}

Node* inserirOrdenado(Node* cabeca, int valor) {
    Node* novoNo = criarNo(valor);

    if (cabeca == NULL || valor < cabeca->data) {
        novoNo->next = cabeca;
        return novoNo;
    }

    Node* atual = cabeca;
    while (atual->next != NULL && atual->next->data < valor) {
        atual = atual->next;
    }

    novoNo->next = atual->next;
    atual->next = novoNo;

    return cabeca;
}

void imprimirLista(Node* cabeca) {
    Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main(void) {
    int tamanho, valor;
    Node* cabeca = NULL;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    printf("Digite %d elementos para a lista ordenada:\n", tamanho);
    for (int i = 0; i < tamanho; ++i) {
        scanf("%d", &valor);
        cabeca = inserirOrdenado(cabeca, valor);
    }

    printf("Lista Ordenada: ");
    imprimirLista(cabeca);

    Node* atual = cabeca;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
