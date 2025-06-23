/*
🏋️‍♂️ Organização das Anilhas na Academia - Pilha

Na pequena cidade de Manhumirim, há apenas uma academia, e o estande de anilhas vive desorganizado.
Para mostrar aos frequentadores a importância da organização, um professor pediu a criação de um sistema
que registre quantas anilhas precisam ser retiradas para se encontrar uma anilha com um peso específico.

📥 Entrada:
- Uma sequência de inteiros representando os pesos das anilhas inseridas na pilha (estande).
- O valor 0 indica o fim da entrada das anilhas.
- O próximo número inteiro representa o peso da anilha que se deseja encontrar.

📤 Saída:
- A quantidade de anilhas retiradas para se chegar até a anilha desejada.
- A listagem dos pesos das anilhas retiradas, na ordem em que foram removidas da pilha.

🧠 Conceito:
- Esse exercício simula o comportamento de uma pilha (estrutura LIFO), onde só é possível remover o item
  do topo. Para acessar uma anilha específica, é necessário retirar todas as que estão acima dela.

Exemplo de uso: organização de academias, empilhamento de objetos, ou qualquer sistema de acesso em ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

// ==== ESTRUTURA DE PILHS ====
typedef struct no {
    int peso;
    struct no* proximo;
} No;

// ==== EMPILHAR PILHA ====
No* empilhar(No* topo, int peso) {
    No* novo = malloc(sizeof(No));
    if (novo != NULL) {
        novo->peso = peso;
        novo->proximo = topo;
        return novo;
    } else {
        printf("Erro ao alocar memória.\n");
        return topo;
    }
}

// ==== LIBERAR MEMORIA ====
void liberarPilha(No* topo) {
    No* temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}

// ==== MOSTRAR ANILHAS ====
void mostrarAnilhasRetiradas(No* topo, int procurado) {
    int contagem = 0;
    int soma = 0;

    while (topo != NULL && topo->peso != procurado) {
        printf("Peso retirado: %d\n", topo->peso);
        soma += topo->peso;
        contagem++;
        topo = topo->proximo;
    }

    if (topo == NULL) {
        return;
    } else {
        printf("Anilhas retiradas: %d\n", contagem);
        printf("Peso retirado: %d\n", soma);
    }
}

// ==== FUNÇÃO PRINCIPAL ====
int main() {
    No* topo = NULL;
    int peso, procurado;

    while (1) {
        scanf("%d", &peso);
        if (peso == 0) break;
        topo = empilhar(topo, peso);
    }
    scanf("%d", &procurado);
    mostrarAnilhasRetiradas(topo, procurado);
    liberarPilha(topo);

    return 0;
}
