/**  Somatório de números

 Faça um programa que some todos os números de um vetor de tamanho 230. Garanta que os números neste vetor sejam sempre os mesmos para garantir o mesmo resultado final!

 Construa 2 versões em paralelo utilizando #pragma omp for que soma parcialmente os valores e:

 que utiliza uma variável compartilhada e #pragma omp critial para controle de seção crítica
 que utiliza #pragma omp ... reduction(...) para a somatória final
 Faça uma comparação de tempo de execução com 1, 2, 3, 4, 5 e 6 threads, para cada versão. Construa uma tabela contendo o tempo médio de 10 execuções para cada versão e sua respectiva quantidade de threads.

 Faça um gráfico que mostre a escalabilidade forte (mínimo de 228, com garantia de todos os dados em memória) e escalabilidade fraca (use 230 como quantidade máxima de dados) do Speedup para cada quantidade de threads utilizada.

 Entregue os códigos fontes e as tabelas no formato Excel, onde cada aba da planilha é relativa a uma versão diferente de código com sua respectiva tabela de execução e seu respectivo gráfico de speedup.

 Giulia Barbieri Quagliano TIA: 42013070
Jenifer Mathias dos Santos TIA: 32092946

 ~ ~ ~ ~ ~ ~ Solução 2 - que utiliza #pragma omp ... reduction(...) para a somatória final ~ ~ ~ ~ ~ ~

 */

#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#define MAX 100
#define SIZE_VET 1073741824 /** resultado da potencia 2 ^ 30 */

int vetor[SIZE_VET];

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
    printf("\n\nTempo (s): %f", tempo_gasto);
}


int main() {

    printf("\n* * * * * * Avaliação de desempenho * * * * * *\n\n");

    /** preenche o vetor com o valor 5 */
    int i;
    for (i = 0; i < SIZE_VET; i++) {
        vetor[i] = 5;
        printf("%d", vetor[i]);
    }

    /** soma valores do vetor usando reduction */
    int soma = 0;

#pragma omp parallel for num_threads(6) \
reduction(+: soma

    for (int j = 0; j < SIZE_VET; j++) {
        soma += vetor[j];
    }

    calculaTempo();

    printf("\n\nSoma: %d\n", soma);
}