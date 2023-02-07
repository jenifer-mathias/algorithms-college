#include<stdio.h>
#include<stdlib.h>

void merge(int *vetor, const int *esquerda, int a, const int *direita, int b) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while(i < a && j < b) {
        if(esquerda[i] < direita[j])
            vetor[k++] = esquerda[i++];
        else vetor[k++] = direita[j++];
    }

    while(i < a)
        vetor[k++] = esquerda[i++];

    while(j < b)
        vetor[k++] = direita[j++];
}

void mergeSort(int *vetor, int total) {
    const int METADE = 2;
    int *primeiraParte,*segundaParte, meio, i;
    if(total < 2) return;
    meio = total / METADE;
    primeiraParte = (int*) malloc(meio* sizeof(int));
    segundaParte = (int*) malloc(meio* sizeof(int));   // uso do malloc para alocar espaço na memória

    for(i = 0; i < meio; i++)
        primeiraParte[i] = vetor[i];

    for(i = meio; i < total; i++)
        segundaParte[i - meio] = vetor[i];

    mergeSort(primeiraParte, meio);
    mergeSort(segundaParte,total - meio);
    merge(vetor, primeiraParte, meio, segundaParte,total - meio);
    free(primeiraParte);
    free(segundaParte);     // uso do free para liberar este bloco na memória
}

int main() {
    const int TAMANHO_VETOR = 6;
    int vetor[6] = { 7, 5, 15, 12, 19, 27 };
    int i;

    printf("\n******* Ordenação por intercalação *******");

    printf("\n\nAntes da ordenação:\n");

    for(i = 0; i < TAMANHO_VETOR; i++)
        printf("%d ",vetor[i]);

    printf("\n\nDepois da ordenação:\n");

    mergeSort(vetor, TAMANHO_VETOR);

    for(i = 0; i < TAMANHO_VETOR; i++)
        printf("%d ",vetor[i]);
    printf("\n");
}
