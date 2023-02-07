// Giulia Barbieri Quagliano - TIA: 42013070
// Gabriela Lopes - TIA: 31744591
// Lucas Martins de Souza - TIA: 31943187
// Jenifer Mathias dos Santos - TIA: 32092946

#include <stdio.h>
#include <string.h>

#define _Rejeita_ 0
#define _Inteiro_ 1
#define _Ponto_Flutuante_ 2
#define _Inteiro_Negativo_ 3
#define _Ponto_Flutuante_Negativo_ 4

int scanner(char palavra[]) {
    int i = 0;
    int j = 0;
    char c;

    q0:
    c = palavra[i];
    i++;
    if (c == '0') goto q1;
    else if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
             c == '6' || c == '7' || c == '8' || c == '9')
        goto q4;
    else if (c == '-') goto q5;
    else if (c == '\0') return (_Rejeita_);
    else goto poco;

    q1:
    c = palavra[i];
    i++;
    if (c == '.') goto q2;
    else if (c == '\0') return (_Rejeita_);
    else goto poco;

    q2:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
        c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        goto q3;
    else if (c == '\0') return (_Rejeita_);
    else goto poco;

    q3:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
        c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        goto q3;
    else if (c == '\0') return (_Ponto_Flutuante_);
    else goto poco;

    q4:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
        c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        goto q4;
    else if (c == '.') goto q2;
    else if (c == '\0') return (_Inteiro_);
    else goto poco;

    q5:
    c = palavra[i];
    i++;
    if (c == '0') goto q7;
    else if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
             c == '6' || c == '7' || c == '8' || c == '9')
        goto q6;
    else if (c == '\0') return (_Rejeita_);
    else goto poco;

    q6:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
        c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        goto q6;
    else if (c == '.') goto q8;
    else if (c == '\0') return (_Inteiro_Negativo_);
    else goto poco;

    q7:
    c = palavra[i];
    i++;
    if (c == '.') goto q8;
    else if (c == '\0') return (_Rejeita_);
    else goto poco;

    q8:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
        c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        goto q9;
    else if (c == '\0') return (_Rejeita_);
    else goto poco;

    q9:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
        c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        goto q9;
    else if (c == '\0') return (_Ponto_Flutuante_Negativo_);
    else goto poco;

    poco:
    return (_Rejeita_);

}

int main() {
    char palavra[20];
    strcpy(palavra, "21");
    printf("\na palavra é: %s", palavra);

    int res = scanner(palavra);
    if (res == 1) {
        printf("\npalavra aceita\n");
        printf("Inteiro\n");
    } else if (res == 2) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante\n");
    } else if (res == 3) {
        printf("\npalavra aceita\n");
        printf("Inteiro Negativo\n");
    } else if (res == 4) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante Negativo\n");
    } else {
        printf("\npalavra recusada\n");
    }

    strcpy(palavra, "-21");
    printf("\na palavra é: %s", palavra);

    res = scanner(palavra);
    if (res == 1) {
        printf("\npalavra aceita\n");
        printf("Inteiro\n");
    } else if (res == 2) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante\n");
    } else if (res == 3) {
        printf("\npalavra aceita\n");
        printf("Inteiro Negativo\n");
    } else if (res == 4) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante Negativo\n");
    } else {
        printf("\npalavra recusada\n");
    }

    strcpy(palavra, "021");
    printf("\na palavra é: %s", palavra);

    res = scanner(palavra);
    if (res == 1) {
        printf("\npalavra aceita\n");
        printf("Inteiro\n");
    } else if (res == 2) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante\n");
    } else if (res == 3) {
        printf("\npalavra aceita\n");
        printf("Inteiro Negativo\n");
    } else if (res == 4) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante Negativo\n");
    } else {
        printf("\npalavra recusada\n");
    }

    strcpy(palavra, "2.1");
    printf("\na palavra é: %s", palavra);

    res = scanner(palavra);
    if (res == 1) {
        printf("\npalavra aceita\n");
        printf("Inteiro\n");
    } else if (res == 2) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante\n");
    } else if (res == 3) {
        printf("\npalavra aceita\n");
        printf("Inteiro Negativo\n");
    } else if (res == 4) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante Negativo\n");
    } else {
        printf("\npalavra recusada\n");
    }

    strcpy(palavra, "-2.1");
    printf("\na palavra é: %s", palavra);

    res = scanner(palavra);
    if (res == 1) {
        printf("\npalavra aceita\n");
        printf("Inteiro\n");
    } else if (res == 2) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante\n");
    } else if (res == 3) {
        printf("\npalavra aceita\n");
        printf("Inteiro Negativo\n");
    } else if (res == 4) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante Negativo\n");
    } else {
        printf("\npalavra recusada\n");
    }

    strcpy(palavra, "+0.34");
    printf("\na palavra é: %s", palavra);

    res = scanner(palavra);
    if (res == 1) {
        printf("\npalavra aceita\n");
        printf("Inteiro\n");
    } else if (res == 2) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante\n");
    } else if (res == 3) {
        printf("\npalavra aceita\n");
        printf("Inteiro Negativo\n");
    } else if (res == 4) {
        printf("\npalavra aceita\n");
        printf("Ponto Flutuante Negativo\n");
    } else {
        printf("\npalavra recusada\n");
    }
}