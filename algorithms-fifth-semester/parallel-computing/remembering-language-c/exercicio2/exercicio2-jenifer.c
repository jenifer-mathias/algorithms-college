/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

 2. Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele.
 Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média,
 informar o conceito de acordo com a tabela:
 maior ou igual a 9	A
 maior ou igual a 7.5 e menor que 9	B
 maior ou igual a 6 e menor que 7.5	C
 maior ou igual a 4 e menor que 6	D
 menor que 4	E
 */

#include <stdio.h>
#include <stdlib.h>

/** Funcao padrao para calcular a media */
float calculaNota(float nota1, float nota2, float nota3, float mediaExercicios) {
    return (nota1 + nota2 * 2 + nota3 * 3 + mediaExercicios) / 7;
}

/** Funcao padrao para verificar as condicoes e saber a media */
void getCondicoesAprovacao(float resultado) {
    if (resultado >= 9) {
        printf("\nA\n");
    } else if (resultado >= 7.5 && resultado < 9) {
        printf("\nB\n");
    } else if (resultado >= 6.0 && resultado <= 7.5) {
        printf("\nC\n");
    } else if (resultado >= 4.0 && resultado < 6.0) {
        printf("\nD\n");
    } else if (resultado < 4.0) {
        printf("\nE\n");
    }
}

/***** MINHA VERSAO 1 USANDO VETOR *****/

float vetNotas[4];

void scanfNotasVet() {
    int i = 0;
    int contadorNotas = 1;

    while (i < 3) {
        printf("\nDigite a nota %d: ", contadorNotas);
        scanf("%f", &vetNotas[i]);
        i++;
        contadorNotas++;
    }

    printf("\nDigite a média dos exercícios: ");
    scanf("%f", &vetNotas[i]);
}

/** MINHA VERSAO 2 USANDO STRUCT */

typedef struct {
    float nota1, nota2, nota3, mediaExercicios;
} Nota;

Nota *nota;

void scanfNotasStruct() {
    printf("\nDigite a nota 1: ");
    scanf("%f", &nota->nota1);

    printf("\nDigite a nota 2: ");
    scanf("%f", &nota->nota2);

    printf("\nDigite a nota 3: ");
    scanf("%f", &nota->nota3);

    printf("\nDigite a média dos exercícios: ");
    scanf("%f", &nota->mediaExercicios);
}

void getVersaoBasica() {
    float nota1, nota2, nota3, mediaExercicios;
    printf("\nDigite a nota 1: ");
    scanf("%f", &nota1);

    printf("\nDigite a nota 2: ");
    scanf("%f", &nota2);

    printf("\nDigite a nota 3: ");
    scanf("%f", &nota3);

    printf("\nDigite a média dos exercícios: ");
    scanf("%f", &mediaExercicios);

    float aprovacao = calculaNota(nota1, nota2, nota3, mediaExercicios);
    getCondicoesAprovacao(aprovacao);
}

void getVersaoVetor() {
    /** usuario digita as notas */
    scanfNotasVet();

    /** usa a formula para calcular o resultado */
    float resultadoV1 = calculaNota(vetNotas[0], vetNotas[1], vetNotas[2], vetNotas[3]);
    getCondicoesAprovacao(resultadoV1);
}

void getVersaoStruct() {
    /** aloca espaço na memória para armazenar as notas */
    nota = malloc(sizeof(nota));

    /** usuario digita as notas */
    scanfNotasStruct();

    /** usa a formula para calcular o resultado */
    float resultadoV2 = calculaNota(nota->nota1, nota->nota2, nota->nota3, nota->mediaExercicios);

    /** retorna a media do aluno com base nas notas */
    getCondicoesAprovacao(resultadoV2);
}

main() {
    /** ~ ~ ~ ~ USO DA MINHA VERSAO BASICA ~ ~ ~ ~ */
    getVersaoBasica();

    /** ~ ~ ~ ~ USO DA MINHA VERSAO USANDO VETOR ~ ~ ~ ~ */
    getVersaoVetor();

    /** ~ ~ ~ ~ USO DA MINHA VERSAO COM STRUCT  ~ ~ ~ ~ */
    getVersaoStruct();
}
