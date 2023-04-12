#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define FILE_READ_MODE "r"
#define GO_OUT 2
#define MAX_NUMBERS 1000

char firstFilePath[] = "/Users/jenifer.santos/algorithms-college/algorithms-sixth-semester/distributed-computing/busca-elemento-mpi/vetor1.csv";
char secondFilePath[] = "/Users/jenifer.santos/algorithms-college/algorithms-sixth-semester/distributed-computing/busca-elemento-mpi/vetor2.csv";

int main(int argc, char **argv) {

    int numeroProcurado;
    int rank, size;
    int numbers[MAX_NUMBERS];
    int num_count;
    int i;
    int index = -1;
    FILE *fp;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        fp = fopen(secondFilePath, FILE_READ_MODE);
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        /** Le os números do arquivo e salvar no vetor */
        num_count = 0;
        while (fscanf(fp, "%d", &numbers[num_count]) == 1) {
            num_count++;
            if (num_count == MAX_NUMBERS) {
                break;
            }
        }
        fclose(fp);

        printf("\nDigite um número inteiro a ser encontrado: ");
        fflush(stdout);
        scanf("%d", &numeroProcurado);
    }

    /** Broadcast do número de elementos e do número a ser encontrado */
    MPI_Bcast(&num_count, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&numeroProcurado, 1, MPI_INT, 0, MPI_COMM_WORLD);

    /** Divide o vetor em partes iguais entre os processos */
    int local_num_count = num_count / size;
    int *local_numbers = (int *) malloc(local_num_count * sizeof(int));
    MPI_Scatter(numbers, local_num_count, MPI_INT, local_numbers, local_num_count, MPI_INT, 0,
                MPI_COMM_WORLD);

    /** Buscar o elemento no vetor */
    for (i = 0; i < local_num_count; i++) {
        if (local_numbers[i] == numeroProcurado) {
            index = i + rank * local_num_count;
            break;
        }
    }

    /** Reduzir o resultado para o processo 0 */
    MPI_Reduce(&index, &i, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        if (index == -1) {
            printf("\nNúmero não encontrado no vetor!\n\n");
        } else {
            printf("\nNúmero encontrado no índice %d.\n\n", index);
        }
    }

    MPI_Finalize();
    return 0;
}
