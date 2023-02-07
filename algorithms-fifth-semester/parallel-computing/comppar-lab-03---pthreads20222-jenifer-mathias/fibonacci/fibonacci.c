#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAX 100

int thread_count;

void calculaTempo() {
    int i, j;
    int n = MAX;

    struct timeval tv;
    double start_t, end_t, tempo_gasto;

    gettimeofday(&tv, NULL);
    start_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            gettimeofday(&tv, NULL);

    end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
    tempo_gasto = end_t - start_t;
    printf("\ntempo %f usecs\n", tempo_gasto);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciTradicional(int n) {
    calculaTempo();
    return fibonacci(n);
}

void *runner(void *param) {
    thread_count = fibonacci((int) param);
    pthread_exit(0);
}

void manageThreadsToFibonacci(int numero, char *argv[]) {
    long thread;
    pthread_t *thread_handles;

    thread_count = 4;

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, runner, (void *) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    calculaTempo();

    printf("\nResultado do cálculo: %d\n", fibonacci(numero));

    free(thread_handles);
}

int main(int argc, char *argv[]) {
    printf("\n* * * * * * Calcula Fibonacci * * * * * *\n");

    int numero;

    printf("\nDigite um número para calcular o Fibonacci: \n");
    scanf("%d", &numero);

    printf("\n~ ~ ~ ~ ~ Fibonacci tradicional ~ ~ ~ ~ ~\n");

    printf("\nResultado do cálculo: %d\n", fibonacciTradicional(numero));

    printf("\n~ ~ ~ ~ ~ Fibonacci usando threads ~ ~ ~ ~ ~\n");

    manageThreadsToFibonacci(numero, argv);

    return 0;
}