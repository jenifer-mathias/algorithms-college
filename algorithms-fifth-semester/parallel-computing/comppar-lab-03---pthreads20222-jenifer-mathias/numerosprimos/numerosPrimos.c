#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

int limiteInferior;
int limiteSuperior;
int n;

void encontraNumerosPrimos(int limiteSuperior, int limiteInferior) {
    int k;
    int numeroPrimo;
    for (n = limiteInferior; n <= limiteSuperior; n++) {
        numeroPrimo = 1;
        for (k = 2; k < n; k++) {
            if ((n % k) == 0) {
                numeroPrimo = 0;
                break;
            }
        }
        if (numeroPrimo) {
            pthread_mutex_lock(&mutex);
            printf("\n");
            printf(" %u ", n);
            printf("\n");
            pthread_mutex_unlock(&mutex);
        }
    }
}

void *runnerEncontraNumerosPrimos(void *param) {
    encontraNumerosPrimos(limiteSuperior, limiteInferior);
    pthread_exit(0);
}

int main() {
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    long threads;

    printf("\n* * * * * * Verifica números primos * * * * * *\n");

    printf("\nDigite o limite mínimo para visualizar números primos: \n");
    scanf("%d", &limiteInferior);

    printf("\nDigite o limite máximo dos números primos: \n");
    scanf("%d", &limiteSuperior);

    pthread_create(&thread, NULL, runnerEncontraNumerosPrimos, (void *) threads);
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}