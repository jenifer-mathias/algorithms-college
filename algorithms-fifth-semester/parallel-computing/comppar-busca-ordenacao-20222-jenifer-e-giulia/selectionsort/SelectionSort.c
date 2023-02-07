#include <stdio.h>
#include <stdlib.h>

struct Compara {
    int elemento;
    int indice;
};

#pragma omp declare reduction(min : struct Compara : omp_out = omp_in.elemento > omp_out.elemento ? omp_out : omp_in)

void swap(int *a, int *b);

void selectionSort(int *a, int n);

void selectionSort(int *a, int n) {

    for (int startpos = 0; startpos < n; startpos++) {
        int maxpos = startpos;

#pragma omp parallel for reduction(maximum:maxpos)

        for (int i = startpos + 1; i < n; ++i) {
            if (a[i] < a[maxpos]) {
                maxpos = i;
            }
        }
        swap(&a[startpos], &a[maxpos]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int number, iter = 0;
    int *Arr;

    Arr = (int *) malloc(number * sizeof(int));

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &number);

    for (; iter < number; iter++) {
        printf("\nDigite o número: ");
        scanf("%d", &Arr[iter]);
    }

    selectionSort(Arr, number);

    printf("\nSorted array :\n");
    for (int iter = 0; iter < number; iter++) {
        printf("%d ", Arr[iter]);
    }

    return 0;
}