#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordem crescente
int compararCrescente(const void* n1, const void* n2) {
    if (*(int*)n1 == *(int*)n2)
        return 0;
    else if (*(int*)n1 < *(int*)n2)
        return -1; // n1 vem antes
    else
        return 1; // n1 vem depois
}

int compararDecrescente(const void* n1, const void* n2){
    if (*(int*)n1 == *(int*)n2)
        return 0;
    else
        if (*(int*)n1 > *(int*)n2)
            return -1;
        else
            return 1;
}
int main() {
    int i;

    // Correção: inicialização de vetor com chaves {}
    int vetor[10] = {5,3,2,1,7,8,9,10,11,102};

    // qsort: ordena o vetor
    qsort(vetor, 10, sizeof(int), compararCrescente);

    printf("\n numeros em ordem crescente:");
    for (i = 0; i < 10; i++) {
        printf(" %d ", vetor[i]);
    }


    // qsort: ordena o vetor decrescente
    qsort(vetor, 10, sizeof(int), compararDecrescente);
     printf("\n numeros em ordem decrescente: ");
    //
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
