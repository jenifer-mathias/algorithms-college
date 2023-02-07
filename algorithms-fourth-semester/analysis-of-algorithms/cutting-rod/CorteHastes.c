/** Solução ingênua para o problema da haste */

#include <stdio.h>
#include <limits.h>

#define HASTE_SEM_CORTES 0

int cortaHaste(int preco[], int tamanhoCorteHaste) {
    int max;
    if (tamanhoCorteHaste == HASTE_SEM_CORTES) {                 /** Não houve cortes na haste */
        return HASTE_SEM_CORTES;
    } else {
        int maiorPreco = INT_MIN;                                /** Representação de menos infinito */
        for (int i = 0; i < tamanhoCorteHaste; i++) {
            int novoPreco = (preco[i] + cortaHaste(preco, tamanhoCorteHaste - i - 1));
            if (maiorPreco > novoPreco) {
                max = maiorPreco;
            } else max = novoPreco;
        }
        return max;
    }
}

/** Resolução do professor */
int cortaHasteProf(int n, int p[]) {
    if (n == 0) return 0;
    int i, maximo = -1;
    for (i = 1; i <= n; i++) {
        int temp = p[i] + cortaHasteProf(n - i, p);
        if (temp > maximo) maximo = temp;
    }
    return maximo;
}

int main() {
    int preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};                     /** Exemplo da aula */
    printf("\n********** Corte da haste - solução ingênua **********\n");
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Minha solução ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ");
    printf("\nMelhor preço de acordo com o corte da haste: R$ %.2f\n", (float) cortaHaste(preco, 10));

    int precoProf[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};            /** Exemplo prof */
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ Solução do prof ~ ~ ~ ~ ~ ~  ~ ~ ~ ~ ");
    printf("\nMelhor preço de acordo com o corte da haste: R$ %.2f\n", (float) cortaHasteProf(10, precoProf));
}