/**

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946
 Turma: 5N

Alguns exercicios com processos

Memória Compartilhada

Crie um código-fonte que utilize fork() e shmget() entre 2 processos (pai e filho). Seu código deve garantir que:

o processo pai e o processo filho compartilhem uma variável simples (por exemplo, inteiro - valor 1)

o processo pai imprime o valor inicial dessa variável; em seguida, cria o processo filho e espera-o

o processo filho acessa esta variável, realiza uma operação (por exemplo, adição - valor 2, totalizando 3), modificando o valor; em seguida, o processo filho termina

o processo pai realiza uma outra operação (por exemplo, multiplicação - valor 4, totalizando 12), modificando novamente o valor, e imprime novamente a variável

Essa lógica de execução deve ser garantida no seu código-fonte em C.

 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <unistd.h>

pid_t childpid;
int shmID;
int *shmPtr;

void createMemorySegment() {
    shmID = shmget(IPC_PRIVATE, 4 * sizeof(int), IPC_CREAT | 0666); /** cria um segmento de memória compartilhada*/

    if (shmID < 0) {
        printf("shmget error\n");
        exit(1);
    }
}

void variableInitialValue() {
    *shmPtr = 1; /** atribui o valor inicial 1 a variável global */
    printf("\nValor inicial da variável compartilhada: %i\n", *shmPtr);
}

void attachProcess() {
    shmPtr = (int *) shmat(shmID, NULL, 0);

    if ((int) *shmPtr == -1) {
        printf("*** shmat error (server) ***\n");
        exit(1);
    }
}

void createChildProcess() {
    childpid = fork(); /** cria o processo filho */

    if (childpid == 0) {
        *shmPtr += 2; /** o processo filho altera o valor da variável */
        printf("\nValor da variável compartilhada ao realizar a soma: %i\n", *shmPtr);
    } else {
        wait(NULL); /** processo filho em espera */
        *shmPtr *= 4; /** o processo pai altera novamente o valor da variável */
        printf("\nValor da variável compartilhada ao realizar a multiplicação: %i\n", *shmPtr);
    }
}

int main() {

    printf("\n* * * * * Memória compartilhada * * * * *\n");

    createMemorySegment(); /** cria o segmento de memória compartilhada */

    attachProcess(); /** anexa um processo ao espaço de endereçamento de processo */

    variableInitialValue(); /** imprime valor da variável inicial */

    createChildProcess(); /** cria o processo filho */

    return 0;
}