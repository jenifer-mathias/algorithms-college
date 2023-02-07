/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

 Implemente uma calculadora de fração utilizando a linguagem C no paradigma imperativo,
 use os conceitos vistos nas aulas, ou seja,
 para representar uma fração você pode definir um novo tipo fração com typedef struct.

 As operações definidas para fração devem ser representadas como funções
 que recebem como parâmetro duas estruturas do tipo fração e retorna uma
 nova fração, isso para as operações de soma, multiplicação e divisão.

 A operação de igualdade pode retornar verdadeiro (=1) ou falso (=0) na linguagem C.

 */

#include  <stdio.h>
#include <stdbool.h>

typedef struct {
    int numerator;
    int denominator;
} fraction;

int mdc(int numerator, int denominator) {
    if (numerator == 0) return denominator;
    return mdc(denominator % numerator, numerator);
}

void simplifyFraction(int *numerator, int *denominator) {
    int resultMdc = mdc(*numerator, *denominator);
    *numerator = *numerator / resultMdc;
    *denominator = *denominator / resultMdc;
    if (*denominator < 0) {
        *denominator *= -1;
        *numerator *= -1;
    }
}

void sum(fraction firstFraction, fraction secondFraction) {
    int newNumerator = (firstFraction.numerator * secondFraction.denominator) +
                       (secondFraction.numerator * firstFraction.denominator);
    int newDenominator = firstFraction.denominator * secondFraction.denominator;
    simplifyFraction(&newNumerator, &newDenominator);
    printf("\n%i/%i", newNumerator, newDenominator);
}

void multiply(fraction firstFraction, fraction secondFraction) {
    int newNumerator = firstFraction.numerator * secondFraction.numerator;
    int newDenominator = firstFraction.denominator * secondFraction.denominator;
    simplifyFraction(&newNumerator, &newDenominator);
    printf("\n%i/%i", newNumerator, newDenominator);
}

void div(fraction firstFraction, fraction secondFraction) {
    int newNumerator = firstFraction.numerator * secondFraction.denominator;
    int newDenominator = firstFraction.denominator * secondFraction.numerator;
    simplifyFraction(&newNumerator, &newDenominator);
    printf("\n%i/%i", newNumerator, newDenominator);
}

bool eq(fraction firstFraction, fraction secondFraction) {
    int firstDiv = firstFraction.numerator / firstFraction.denominator;
    int secondDiv = secondFraction.numerator / secondFraction.denominator;
    if (firstDiv == secondDiv) {
        return true;
    } else {
        return false;
    }
}

void choiceFraction(fraction *firstFraction, fraction *secondFraction) {
    printf("\nDigite o numerador da primeira fração: ");
    scanf("%i", &firstFraction->numerator);

    printf("\nDigite o denominador da primeira fração: ");
    scanf("%i", &firstFraction->denominator);

    printf("\nDigite o numerador da segunda fração: ");
    scanf("%i", &secondFraction->numerator);

    printf("\nDigite o denominador da segunda fração: ");
    scanf("%i", &secondFraction->denominator);
}

int main() {
    fraction firstFraction;
    fraction secondFraction;

    choiceFraction(&firstFraction, &secondFraction);

    int choice;
    do {
        printf("\n\n* * * * * Calcula frações * * * * *\n");
        printf("\n* * * * * * MENU * * * * * *\n");
        printf("\nDigite um número correspondente a opção desejada: \n");
        printf("\n1 - calcular a soma");
        printf("\n2 - calcular a multiplicação");
        printf("\n3 - calcular a divisão");
        printf("\n4 - comparar se duas frações são iguais");
        printf("\n5 - escolher outra fração para fazer os cálculos");
        printf("\n0 - sair\n\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sum(firstFraction, secondFraction);
                break;

            case 2:
                multiply(firstFraction, secondFraction);
                break;

            case 3:
                div(firstFraction, secondFraction);
                break;

            case 4:
                printf("\n%s", eq(firstFraction, secondFraction) ? "\ntrue\n" : "\nfalse\n");
                break;

            case 6:
                choiceFraction(&firstFraction, &secondFraction);
                break;

            case 0:
                printf("\nFim dos cálculos, obrigada!\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (choice != 0);

    return 0;
}