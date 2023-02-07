/**

Grupo:

 Nome: Gabriela Lopes Francisco
 TIA: 31744591

 Nome: Giulia Barbieri Quagliano
 TIA: 42013070

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Lucas Martins de Souza
 TIA: 31943187

 */

#include<stdio.h>

/**
 N={ I,S, K, T, Z, F, N }
 T={ +, -, *, /, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }

 I -> S$
 S -> T K
 K -> + T K
 K -> - T K
 K -> e
 T -> F Z
 Z -> * F Z
 Z -> / F Z
 Z -> e
 F -> (S)
 F -> N
 F -> -N
 N -> 0N|1N|2N|3N|4N|5N|6N|7N|8N|9N
 N -> 0|1|2|3|4|5|6|7|8|9
 */

/** declara interfaces */

int I(char palavra[], int *pos);

int S(char palavra[], int *pos);

int K(char palavra[], int *pos);

int T(char palavra[], int *pos);

int Z(char palavra[], int *pos);

int F(char palavra[], int *pos);

int N(char palavra[], int *pos);

void trataErro(char palavra[], int *pos);

char lookahead;   /** Excepcionalmente variavel global */

int match(char t, char palavra[], int *pos) {
    if (lookahead == t) {
        lookahead = palavra[++(*pos)];
        return (1);
    }
    return (0);
}

/** I -> S$ */
int I(char palavra[], int *pos) {
    if (S(palavra, pos) && match('$', palavra, pos))
        return (1);
    else
        return (0);
}

/** S -> TK */
int S(char palavra[], int *pos) {
    if (T(palavra, pos) && K(palavra, pos))
        return (1);
    else
        return (0);
}

/** K -> +TK  ,   K -> -TK , K-> e  */
int K(char palavra[], int *pos) {
    if (lookahead == '+') {
        if (match('+', palavra, pos) && T(palavra, pos) && K(palavra, pos))
            return (1);
        else
            return (0);
    } else if (lookahead == '-') {
        if (match('-', palavra, pos) && T(palavra, pos) && K(palavra, pos))
            return (1);
        else
            return (0);
    } else
        return (1);
}

/** T -> FZ */
int T(char palavra[], int *pos) {
    if (F(palavra, pos) && Z(palavra, pos))
        return (1);
    else
        return (0);
}

/** Z -> * FZ  Z -> / FZ Z -> e  */
int Z(char palavra[], int *pos) {
    if (lookahead == '*') {
        if (match('*', palavra, pos) && F(palavra, pos) && Z(palavra, pos))
            return (1);
        else
            return (0);
    } else if (lookahead == '/') {
        if (match('/', palavra, pos) && F(palavra, pos) && Z(palavra, pos))
            return (1);
        else
            return (0);
    } else
        return (1);
}

/** F -> (S) F -> -X F -> X */
int F(char palavra[], int *pos) {
    if (lookahead == '(') {
        if (match('(', palavra, pos) && S(palavra, pos) && match(')', palavra, pos))
            return (1);
        else
            return (0);
    } else if (lookahead == '-') {
        if (match('-', palavra, pos) && N(palavra, pos))
            return (1);
    } else
        N(palavra, pos);
    return (1);
}

/**
 N -> 1D|2D|3D|4D|5D|6D|7D|8D|9D
 N -> 0|1|2|3|4|5|6|7|8|9 */
int N(char palavra[], int *pos) {
    if (lookahead >= '1' && lookahead <= '9' ||
        lookahead >= '0' && lookahead <= '9') {
        if (match(lookahead, palavra, pos) && N(palavra, pos))
            return (1);
        else
            return (0);
    } else
        return (0);
}


void trataErro(char palavra[], int *pos) {
    if (match(palavra[*pos], palavra, pos) == 1) {
        printf("\nERRO DE SINTAXE\n");
        printf("\nOcorreu um erro na leitura do caractere: %c\n", palavra[*pos]);
        printf("\nPosição do erro: %d\n", *pos);
    }
}

int main() {
    char palavra[] = "-+a(9234c";
    int pos = 0;

    lookahead = palavra[pos];

    if (I(palavra, &pos))
        printf("\nPalavra %s reconhecida!\n", palavra);
    else
        trataErro(palavra, &pos);
    return (0);
}