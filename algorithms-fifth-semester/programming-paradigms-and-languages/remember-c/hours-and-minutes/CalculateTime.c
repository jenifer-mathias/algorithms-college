/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

 Escreva uma função que receba dois parâmetros, um número inteiro
 representando um tempo em minutos e um tempo armazenado na estrutura
 typedef struct tempo representando um tempo em horas:minutos.

 A função calcula a soma tempo em minuto (parâmetro inteiro) com o tempo armazenado na estrutura,
 ao final o tempo atualizado é devolvido pela função.
 Por exemplo se for informado 71 minutos e 3hs:15min a função deve devolver o tempo na estrutura de 4hs:26min.

 */

#include  <stdio.h>

#define ONE_HOUR_EQUIVALENT_IN_MINUTES 60

typedef struct {
    int horas;
    int minutos;
} tempo;

void calculateTime(int timeInMinutes, tempo time) {
    int minutes = timeInMinutes + time.minutos;

    int hour = time.horas + (minutes / ONE_HOUR_EQUIVALENT_IN_MINUTES);
    int min = minutes % ONE_HOUR_EQUIVALENT_IN_MINUTES;

    printf("\nTempo: %ihs:%imin\n", hour, min);
}

int main() {

    printf("\n* * * * * Calcula horas e minutos * * * * *\n");

    int addMinutes;
    tempo time;

    printf("\nDigite a quantidade de minutos para adicionar ao tempo: ");
    scanf("%i", &addMinutes);

    printf("\nDigite a quantidade de minutos atuais: ");
    scanf("%i", &time.minutos);

    printf("\nDigite a hora atual: ");
    scanf("%i", &time.horas);

    calculateTime(addMinutes, time);

    return 0;
}