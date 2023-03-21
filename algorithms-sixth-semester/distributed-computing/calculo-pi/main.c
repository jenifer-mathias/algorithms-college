/**
 * Jenifer Mathias dos Santos
 * TIA: 32092946
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mpi.h>

#define NUMTHR 10  // Numero total de threads
#define FILE_READ_MODE "r"

int num_ptos[10]; // Total de pontos da thread
int num_ptos_cir[10]; // Pontos no circulo
int numinter = 1000;
double quad;

void *calculatePi(void *param); // sorteia e verifica os pontos pela thread

void *readFile(int data[], int numinter, int myid);

/** comandos MPI:
 * mpicc -g -Wall -o main main.c
 * mpiexec -n 4 ./main */

int main(int argc, char *argv[]) {
    int j;
    int i;
    double pi = 0;  // contem o valor de pi
    int totalp = 0; // total de pontos
    int totalc = 0; // pontos no circulo
    int numprocs, myid;
    int data[numinter];

    pthread_t tid[10];  // ID das threads

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    readFile(data, numinter, myid);

    MPI_Bcast(data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (argc == 1) {
        numinter = 1000;
    } else {
        numinter = atoi(argv[1]);
    }

    // Para todas as threads
    for (i = 0; i < NUMTHR; i++) {
        // http://stackoverflow.com/a/19233025
        int *j = malloc(sizeof(int));
        *j = i;
        // cria a i-esima thread
        pthread_create(&tid[i], NULL, calculatePi, (void *) j);
    }

    // Para cada thread
    for (i = 0; i < NUMTHR; i++) {
        // espera que as threads terminem
        pthread_join(tid[i], NULL);
    }

    for (i = 0; i < NUMTHR; i++) {
        totalp += num_ptos[i];  // totalp = totalp + num_ptos[i]
        totalc += num_ptos_cir[i]; // totalc = totalp + num_ptos[i]
    }

    // Calcula o valor de pi e imprime na tela
    pi = 4.0 * (((double) totalc) / ((double) totalp)); // transforma totalp
    // e totalc em double

    MPI_Reduce(&quad, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    printf("Valor de pi: %f\n", pi);

    MPI_Finalize();

    return 0;
}

void *readFile(int data[], int numinter, int myid) {
    FILE *fp;
    char outputFilePath[] = "/Users/jenifer.santos/algorithms-college/algorithms-sixth-semester/distributed-computing/calculo-pi/rand.txt";

    if (myid == 0) {
        if ((fp = fopen(outputFilePath, FILE_READ_MODE)) == NULL) {
            printf("Can't open the input file: %s\n\n", outputFilePath);
            exit(1);
        }

        for (int i = 0; i < numinter; i++) fscanf(fp, "%d\n", &data[i]);

    }
}

void *calculatePi(void *param) {
    int i;
    unsigned int thrnum = *((unsigned int *) param); // O número da thread ()
    double x, y;
    num_ptos[thrnum] = 0;
    num_ptos_cir[thrnum] = 0;

    for (i = 0; i < numinter; i++) {

        x = drand48(); // sorteia um número de 0 a 1
        y = drand48(); // sorteia um número de 0 a 1
        quad = ((x * x) + (y * y));
        // Se a soma dos quadrados for menor que R = 1
        // então caiu no círculo
        if (quad <= 1) {
            num_ptos_cir[thrnum]++; // conta pontos no círculo
        }

        num_ptos[thrnum]++; // incrementa os pontos totais da thread N (0 a 9)
    }

    pthread_exit(0);
}
