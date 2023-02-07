#include <stdio.h>
#include <stdlib.h>

void mergeSort(int a[], int i, int j);

void merge(int a[], int i1, int j1, int i2, int j2);

int main() {
    int *a, num, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &num);

    a = (int *) malloc(sizeof(int) * num);
    for (i = 0; i < num; i++) {
        printf("\nDigite um número: ");
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, num - 1);

    printf("\nSorted array: \n");
    for (i = 0; i < num; i++)
        printf("%d ", a[i]);

    return 0;
}

void merge(int a[], int i1, int j1, int i2, int j2) {
    int i, iSai;
    int inicio = i1;
    int aOut[j2];
    for (iSai = i1; iSai <= j2; iSai++) {
        if (i1 > j1) {
            aOut[iSai] = a[i2++];
        } else if (i2 > j2) {
            aOut[iSai] = a[i1++];
        } else if (a[i1] < a[i2]) {
            aOut[iSai] = a[i1++];
        } else {
            aOut[iSai] = a[i2++];
        }
    }
    for (i = inicio; i <= j2; i++) {
        a[i] = aOut[i];
    }
}

void mergeSort(int a[], int i, int j) {
    int meio;
#pragma omp parallel shared(meio)
    {
        if (i < j) {
            meio = (j + i) / 2;
#pragma omp sections
            {
#pragma omp section
                {
                    mergeSort(a, i, meio);
                }
#pragma omp section
                {
                    mergeSort(a, meio + 1, j);
                }
            }
#pragma omp barrier
            {
                merge(a, i, meio, meio + 1, j);
            }
        }
    }
}