/*
 * 📦 Separação de frase em duas pilhas usando PONTEIROS
 *
 * Descrição:
 *   Implementação de pilhas usando ponteiros e alocação dinâmica de memória
 *   ao invés de vetores estáticos. Cada nó da pilha é criado dinamicamente.
 *
 * Conceitos utilizados:
 *   - Ponteiros para estruturas
 *   - Alocação dinâmica (malloc/free)
 *   - Lista ligada implementando pilha
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ====Estruturas de nos====
typedef struct noPalavra{
    char palavra[100];
    struct noPalavra* proximo;
}NoPalavra;

typedef struct noNumero{
    int numero;
    struct noNumero* proximo;
}NoNumero;

// ====Estrutura de pilha====
NoPalavra* empilharPalavra(NoPalavra* topoPalavra, char palavra[100]){
    NoPalavra* novo_no = malloc(sizeof(NoPalavra));
    if (novo_no){
        strcpy(novo_no->palavra, palavra);
        novo_no->proximo = topoPalavra;
        return novo_no;
    }
    else{
        printf("Erro ao alocar memoria!");
        return topoPalavra;
    }
}

NoNumero* empilharNumero(NoNumero* topoNumero, int numero){
    NoNumero* novo_no = malloc(sizeof(NoNumero));
    if (novo_no){
        novo_no->numero = numero;
        novo_no->proximo = topoNumero;
        return novo_no;
    }
    else{
        printf("Erro ao alocar memoria!");
        return topoNumero;
    }
}

// ==== Verifica se é numero ===
int ehNumero(char* str) {
    if (str == NULL || str[0] == '\0') {
        return 0;
    }

    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
        if (str[i] == '\0') {
            return 0;
        }
    }

    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

//==== Mostrar pilhas ====
void mostrarPilhaPalavra(NoPalavra* topoPalavra){
    if (topoPalavra == NULL) return;

    printf("Palavras:\n");
    NoPalavra* atual = topoPalavra;
    while(atual != NULL){
        printf("%s\n", atual->palavra);
        atual = atual->proximo;
    }
}

void mostrarPilhaNumero(NoNumero* topoNumero){
    if (topoNumero == NULL) return;
    printf("Numeros:\n");
    NoNumero* atual = topoNumero;
    while(atual != NULL){
        printf("%d\n", atual->numero);
        atual = atual->proximo;
    }
}


// ==== Liberar Memoria ====
void liberarPalavra(NoPalavra* topo) {
    NoPalavra* temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}

void liberarNumero(NoNumero* topo) {
    NoNumero* temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}

//==== Função Principal ====
int main()
{
    NoPalavra* topoPalavra = NULL;
    NoNumero* topoNumero = NULL;
    char token[100];
    char frase[1000];
    int numero;

    while(1){
        if (fgets(frase, 1000, stdin) == NULL) {
            break;
        }

        size_t len = strlen(frase);
        if (len > 0 && frase[len-1] == '\n') {
            frase[len-1] = '\0';
        }

        if (strcmp(frase, "end") == 0) {
            break;
        }

        char* verifica = strtok(frase, " \t\n");
        while(verifica != NULL){
            strcpy(token, verifica);
            if(ehNumero(token)){
                numero = atoi(token);
                topoNumero = empilharNumero(topoNumero, numero);
            }
            else{
                topoPalavra = empilharPalavra(topoPalavra, token);
            }
            verifica = strtok(NULL, " \t\n");
        }
    }

    mostrarPilhaPalavra(topoPalavra);
    mostrarPilhaNumero(topoNumero);

    liberarPalavra(topoPalavra);
    liberarNumero(topoNumero);

    return 0;
}
