/*
    Programa: Organizador de Roupas em Pilha
    Contexto:
    
    Em Manhumirim, um estudante de computação muito preguiçoso empilhava todas as roupas em sua cadeira
    ao chegar em casa. Quando sua mãe viu a bagunça, mandou ele arrumar tudo.

    Porém, como bom programador procrastinador, ele decidiu criar um programa que simulasse a organização
    das roupas na gaveta. O programa deve mostrar a ordem correta de armazenamento (na ordem em que foram
    colocadas na cadeira) e também calcular o tempo total necessário para guardar todas as roupas.

    Entrada:
    - Diversas linhas no formato: <tipo> <cor> <tempo>
    - Exemplo: camisa branca 3
    - A entrada é finalizada com a palavra: end

    Saída:
    - A lista de roupas na ordem em que foram inseridas
    - O total de roupas guardadas
    - O tempo total em minutos necessário para dobrar todas
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// ==== ESTRUTURA NÓ ====
typedef struct no {
    char tipoRoupa[51];
    char corRoupa[51];
    int tempoUso;
    struct no* proximo;
} No;

// ==== EMPILHAR ROUPA ====
No* adicionarRoupa(No* topo, char* tipo, char* cor, int tempo) {
    No* novo_no = malloc(sizeof(No));

    if (novo_no) {
        strcpy(novo_no->tipoRoupa, tipo);
        strcpy(novo_no->corRoupa, cor);
        novo_no->tempoUso = tempo;
        novo_no->proximo = topo;
        return novo_no;
    }
    else {
        printf("Erro ao alocar memoria\n");
        return topo;
    }
}
// ==== MOSTRAR ROUPAS ====
void MostrarPilha(No* topo) {
    No* atual = topo;
    int contador = 0;
    int soma = 0;
    int numero;
    while (atual != NULL) {
        printf("Tipo: %s Cor: %s\n", atual->tipoRoupa, atual->corRoupa);
        numero = atual->tempoUso;
        soma += numero;
        contador ++;
        atual = atual->proximo;
    }
    printf("Total de roupas = %d\n", contador);
    printf("Total de tempo = %d\n", soma);
}



// ==== LIBERAR MEMÓRIA ====
void liberarPilha(No* topo) {
    No* temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}

// ==== FUNÇÃO PRINCIPAL ====
int main() {
    No* topo = NULL;
    char entrada[100];

    while (1) {
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }

        size_t len = strlen(entrada);
        if (len > 0 && entrada[len - 1] == '\n') {
            entrada[len - 1] = '\0';
        }

        if (strcmp(entrada, "end") == 0) {
            break;
        }

        char* tipo = strtok(entrada, " \t\n");
        char* cor = strtok(NULL, " \t\n");
        char* numeroStr = strtok(NULL, " \t\n");

        if (tipo && cor && numeroStr) {
            int tempo = atoi(numeroStr);
            topo = adicionarRoupa(topo, tipo, cor, tempo);
        }
    }

    MostrarPilha(topo);
    liberarPilha(topo);

    return 0;
}
