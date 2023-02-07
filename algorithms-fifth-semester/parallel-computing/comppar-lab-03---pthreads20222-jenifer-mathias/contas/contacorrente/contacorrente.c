#include<stdio.h>
#include <time.h>
#include <sys/time.h>

#define MAX 100

int thread_count;

int saldo = 1000;

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

int depositar() {
    return saldo += 5;
}

int debitar() {
    return saldo -= 2;
}

int main() {

    printf("\n* * * * * * Conta corrente * * * * * *\n");

    int j = 500;
    int i = 0;
    while (i < 500) {
        printf("\nSaldo: %.2d\n", depositar());
        printf("\nSaldo: %.2d\n", debitar());
        i++;
        j--;
    }

    printf("\nSaldo final: %.2f\n", saldo);

    calculaTempo();
}
