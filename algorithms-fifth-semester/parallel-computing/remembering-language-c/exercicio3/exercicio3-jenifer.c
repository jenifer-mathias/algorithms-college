/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

3. Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9).
 Este número deve ser sempre ímpar.

1 2 3 4 5 6 7 8 9
  2 3 4 5 6 7 8
    3 4 5 6 7
      4 5 6
        5
 */

#include <stdio.h>

int main() {
    int numero;

    printf("\nDigite um número maximo impar para obter a imidadem correspondente: \n");
    scanf("%d", &numero);

    /** verifica se o número é impar **/
    while (numero % 2 == 0) {
        printf("\nO número digitado não é ímpar, por favor, digite um número impar: \n");
        scanf("%d", &numero);
    }

    printf("\n");

    int i, j;
    int maiorParteNumero = (numero / 2) + 1;

    for (i = 0; i <= maiorParteNumero; i++) {

        /** imprime a linha de elementos */
        for (j = i + 1; j <= numero - i; j++) {
            printf("%d ", j);
        }

        /** pula linha apos finalizar os numeros de cada linha */
        printf("\n");

        /** imprime espacos para obter formato imidadem */
        for (j = 0; j < (i + 1) * 2; j++) {
            printf(" ");
        }
    }
}