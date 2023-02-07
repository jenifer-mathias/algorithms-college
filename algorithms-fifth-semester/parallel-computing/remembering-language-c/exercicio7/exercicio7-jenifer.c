/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

7. Faça um programa que crie um vetor de pessoas.
 Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct.
 O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas.
 A struct deve armazenar os dados de idade, peso e altura.
 */

#include <stdio.h>

typedef struct Aluno {
    char nome[30]; /** limitei a quantidade de caracteres para o nome */
    int idade;
    double peso;
    double altura;
} Aluno;

Aluno aluno[3];

void scanfNomeAlunos() {
    int i = 0;
    int contadorAlunos = 1;

    while (i < 3) {
        printf("\nDigite o nome do aluno %d: ", contadorAlunos);
        scanf("%s", aluno[i].nome);
        i++;
        contadorAlunos++;
    }
}

/** dados para idade, peso e altura previamente definidos */
void getValuesStructAlunos() {
    aluno[0].idade = 22;
    aluno[0].peso = 55;
    aluno[0].altura = 1.64;

    aluno[1].idade = 21;
    aluno[1].peso = 48.0;
    aluno[1].altura = 1.55;

    aluno[2].idade = 25;
    aluno[2].peso = 64.0;
    aluno[2].altura = 1.65;
}

void printAlunos() {
    getValuesStructAlunos();
    for (int i = 0; i <= 2; i++) {
        printf("\nNome: %s\n", aluno[i].nome);
        printf("Idade: %d\n", aluno[i].idade);
        printf("Peso: %.1f\n", aluno[i].peso);
        printf("Altura: %.2f\n\n", aluno[i].altura);
    }
}

main() {
    scanfNomeAlunos();
    printAlunos();
}
