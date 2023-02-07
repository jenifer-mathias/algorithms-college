#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAX 100

int thread_count;

float saldo;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
}

float depositar() {
    saldo += 5;
    return 0;
}

float debitar() {
    saldo -= 2;
    return 0;
}

void *runnerDepositar(void *param) {
    pthread_mutex_lock(&mutex);
    thread_count = depositar((int) param);
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

void *runnerDebitar(void *param) {
    thread_count = debitar((int) param);
    pthread_exit(0);
}

void gerenciaThreadDepositos(long thread, int thread_count, pthread_t *threads) {

    threads = malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&threads[thread], NULL, runnerDepositar, (void *) thread);
        printf("\nSaldo: %.2f\n", saldo);
    }

}

void gerenciaThreadSaques(long thread, int thread_count, pthread_t *threads) {

    threads = malloc(thread_count * sizeof(pthread_t));


    for (thread = 0; thread < thread_count; ++thread) {
        printf("\nSaldo: %.2f\n", saldo);
        pthread_create(&threads[thread], NULL, runnerDebitar, NULL);
    }
}

void joinThreads(long thread, pthread_t *threads) {
    for (thread = 0; thread < thread_count; ++thread) {
        pthread_join(threads[thread], NULL);
    }
}

int main() {

    printf("\n* * * * * * Conta corrente * * * * * *\n");

    saldo = 1000.0f;
    long thread;
    thread_count = 500;

    pthread_t threads[thread_count];

    gerenciaThreadDepositos(thread, thread_count, threads);
    gerenciaThreadSaques(thread, thread_count, threads);
    joinThreads(thread, threads);

    calculaTempo();

    printf("\nSaldo final: %.2f\n", saldo);

    pthread_mutex_destroy(&mutex);

    exit(EXIT_SUCCESS);
}
