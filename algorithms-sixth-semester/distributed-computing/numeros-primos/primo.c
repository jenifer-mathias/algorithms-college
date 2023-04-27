#include <stdio.h>
#include <math.h>
#include <time.h>
#include <mpi.h>

#define LIMITE 5000000

int primo(int numero) {
    int raiz, fator;
    raiz = (int) sqrt((double) numero);
    for (fator = 2; fator <= raiz; fator++)
        if (numero % fator == 0)
            return 0;
    return 1;
}

int main(int argc, char **argv) {
    int quantidade = 0, numero, total;
    double dif;    /** tomada de tempo */
    int rank, num_procs, meu_inicio, meu_fim, intervalo;
    clock_t inicio, fim;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    /** Divide o intervalo de números entre os processos */
    intervalo = LIMITE / num_procs;
    meu_inicio = 2 + rank * intervalo;
    meu_fim = meu_inicio + intervalo - 1;
    if (rank == num_procs - 1) meu_fim = LIMITE - 1;
    inicio = clock();

    /** Conta os números primos no intervalo atribuído aos processos */
    for (numero = meu_inicio; numero <= meu_fim; numero++) {
        int p = primo(numero);
        quantidade += p;
    }
    fim = clock();

    MPI_Reduce(&quantidade, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        dif = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("\nTotal de numeros primos ate %d: %d\n", LIMITE, total);
        printf("Tempo de execucao: %f segundos\n\n", dif);
    }

    MPI_Finalize();

    return 0;
}