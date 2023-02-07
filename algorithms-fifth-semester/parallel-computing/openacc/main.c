// Giulia Barbieri Quagliano - TIA:42013070
// Jenifer Mathias dos Santos - TIA:32092946

#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENACC
#include <openacc.h>
#endif

int linearSearch(int *A, int n, int tos);

int main() {

    int number, iter = 0, find;
    int *Arr;

    printf("\nDigite o tamanho do vetor: \n");
    scanf("%d", &number);
    Arr = (int *) malloc(number * sizeof(int));

    printf("\nDigite os números do vetor: \n");
    for (; iter < number; iter++) {
        scanf("%d", &Arr[iter]);
    }

    printf("\nDigite o número que você deseja encontrar: \n");
    scanf("%d", &find);
    printf("\nTo find: %d\n", find);

    int indx = linearSearch(Arr, number, find);

    if (indx == -1)
        printf("Not found");
    else
        printf("Found at %d\n", indx);

    return 0;
}

int linearSearch(int *A, int n, int tos) {
    int num = -1;
# pragma acc parallel loop
    for (int iter = 0; iter < n; iter++) {
        if (A[iter] == tos) {
            num = iter;
        }
    }
    return num;
}