/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

Escreva um programa que leia um arquivo texto com o nome, a idade e a altura de um conjunto de pessoa.
Coloque os dados em um vetor de Structs e ordene o vetor por altura.
No final, gere um novo arquivo com os dados ordenados.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_READ_MODE "r"
#define FILE_WRITE_MODE "w"

typedef struct Pessoa {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

Pessoa pessoa[4];

/** replace with your path */
char inputFilePath[] = "/Users/jenifer.santos/algorithms-college-classes/algorithms-fifth-semester/parallel-computing/remembering-language-c/read-file/input-file.txt";

int comparaAltura(const void *a, const void *b) {
    Pessoa arg1 = *(const Pessoa *) a;
    Pessoa arg2 = *(const Pessoa *) b;

    if (arg1.altura < arg2.altura)
        return -1;

    if (arg1.altura > arg2.altura)
        return 1;

    return 0;
}

int readDataPerson(FILE *file) {
    int result = fscanf(file, "%s\n", pessoa->nome);

    if (result == EOF)
        return 0;

    result = fscanf(file, "%d\n", &pessoa->idade);
    if (result == EOF)
        return 0;

    result = fscanf(file, "%f\n", &pessoa->altura);
    if (result == EOF)
        return 0;

    return 1;
}

void writeOutputFile() {
    /** replace with your path */
    char outputFilePath[] = "/Users/jenifer.santos/algorithms-college-classes/algorithms-fifth-semester/parallel-computing/remembering-language-c/read-file/output-file.txt";

    FILE *file;
    file = fopen(outputFilePath, FILE_WRITE_MODE);
    if (file == NULL) {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    } else {
        int i;
        for (i = 1; i <= 4; i++) {
            fprintf(file, "%s\n%d\n%.2f\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].altura);
        }
        fclose(file);
    }
}

void readFile() {

    FILE *file;

    file = fopen(inputFilePath, FILE_READ_MODE);
    if (file == NULL) {
        printf("Erro, nao foi possivel abrir o arquivo\n");
        fclose(file);
    } else {
        int i;
        while (!feof(file)) {
            readDataPerson(file);
            for (i = 0; i < 1; i++) {
                printf("%s\n", pessoa[i].nome);
                printf("%d\n", pessoa[i].idade);
                printf("%.2f\n", pessoa[i].altura);
                printf("\n");
                i++;
            }

            /** funcao quicksort para ordenar os elementos em ordem crecente de altura */
            qsort(pessoa, 5, sizeof(struct Pessoa), comparaAltura);
        }

        /** imprime vetor apos ordenar */
        printf("Vetor após fazer a ordenação:\n");
        for (i = 1; i <= 4; i++) {
            printf("\n%s\n%d\n%.2f\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].altura);
        }
    }
    fclose(file);
}

int main() {

    /** le arquivo de entrada */
    readFile();

    /** escreve em arquivo de saida */
    writeOutputFile();

    return 0;
}

