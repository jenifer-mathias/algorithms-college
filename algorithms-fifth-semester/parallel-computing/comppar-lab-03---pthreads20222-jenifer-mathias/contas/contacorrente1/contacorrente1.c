#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAX 100

int thread_count;

float saldo;

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
    printf("tempo %f usecs\n", tempo_gasto);
}

float depositar() {
    return saldo += 5;
}

float debitar() {
    return saldo -= 2;
}

void *runnerDepositar(void *param) {
    thread_count = depositar((int) param);
    pthread_exit(0);
}

void *runnerDebitar(void *param) {
    thread_count = debitar((int) param);
    pthread_exit(0);
}

void joinThreads(long thread, pthread_t *thread_handles) {
    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
}

void gerenciaThreadDepositos(long thread, int thread_count, pthread_t *thread_handles) {

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, runnerDepositar, (void *) thread);
        printf("\nSaldo: %.2d\n", saldo);
    }

    printf("\nSaldo final: %.2d\n", saldo);

    calculaTempo();
}

void gerenciaThreadSaques(long thread, int thread_count, pthread_t *thread_handles) {

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, runnerDebitar, (void *) thread);
        printf("\nSaldo: %.2f\n", saldo);
    }

    printf("\nSaldo final: %.2f\n", saldo);

    calculaTempo();
}

int main() {

    printf("\n* * * * * * Conta corrente * * * * * *\n");

    saldo = 1000;
    long thread;
    pthread_t *thread_handles;
    thread_count = 500;

    gerenciaThreadDepositos(thread, thread_count, thread_handles);
    gerenciaThreadSaques(thread, thread_count, thread_handles);
    joinThreads(thread, thread_handles);

}