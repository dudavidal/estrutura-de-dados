#include <stdio.h>
#include <stdlib.h>

/*
 * Implementação de uma pilha utilizando lista encadeada.
 * A pilha segue a lógica LIFO (Last In, First Out).
 * As principais operações são:
 *  - empilhar (push): adiciona um elemento no topo
 *  - desempilhar (pop): remove o elemento do topo
 */

// Estrutura do nó da lista (cada elemento da pilha)
typedef struct no {
    int dado;
    struct no* proximo;
} No;

/**
 * Função para empilhar um novo valor.
 * Aloca dinamicamente um novo nó, atribui o valor e atualiza o topo.
 */
No* empilhar(No *topo, int valor) {
    No* novoNo = malloc(sizeof(No));
    if (novoNo) {
        novoNo->dado = valor;
        novoNo->proximo = topo;
        return novoNo;
    } else {
        printf("Erro ao alocar memória\n");
        return topo;
    }
}

/**
 * Função para desempilhar (remover) o elemento do topo da pilha.
 * Libera a memória do nó removido e retorna o novo topo.
 */
No* desempilhar(No* topo) {
    if (topo != NULL) {
        No* aux = topo;
        topo = topo->proximo;
        free(aux);
    }
    return topo;
}

/**
 * Função para exibir os elementos da pilha.
 * Percorre do topo até o final da pilha.
 *
 */
void mostrarNo(No* topo) {
    No* atual = topo;
    printf("Pilha: ");
    while (atual != NULL) {
        printf("%d  ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    No* topo = NULL;

    topo = empilhar(topo, 10);
    mostrarNo(topo);

    topo = empilhar(topo, 30);
    mostrarNo(topo);

    topo = desempilhar(topo);
    mostrarNo(topo);

    topo = desempilhar(topo);
    mostrarNo(topo);

    return 0;
}

