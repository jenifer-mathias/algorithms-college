#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int linearSearch(int *A, int n, int tos);

int main() {

    int number, iter = 0, find;
    int *Arr;

    scanf("%d", &number);
    Arr = (int *) malloc(number * sizeof(int));

    for (; iter < number; iter++) {
        scanf("%d", &Arr[iter]);
    }

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
    omp_set_num_threads(n);
    int num = -1;
# pragma omp parallel for
    for (int iter = 0; iter < n; iter++) {
        if (A[iter] == tos) {
            num = iter;
        }
    }
    return num;
}
