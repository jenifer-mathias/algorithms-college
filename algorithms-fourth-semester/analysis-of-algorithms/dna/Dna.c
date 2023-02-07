/** ******************************************************************

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Giulia Barbieri Quagliano
 TIA: 42013070

 Nome: Lucas Martins de Souza
 TIA: 31943187

****************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** constante que representa que os arquivos estarão disponíveis somente para leitura */
#define FILE_MODE "r"

/** define variáveis globais para armazenar o conteúdo dos arquivos de texto */
char conteudoArquivo1[] = "";
char conteudoArquivo2[] = "";

/** definição das funções do programa */

int lcs(char *string1, char *string2);

void removeEspacosEmBrancoDaString(char *string);

int maiorElemento(int string1, int string2);

/** implementação das funções */

int lcs(char *string1, char *string2) {
    char matriz[strlen(string1) + 1][strlen(string2) + 1];
    int x, y, i, j;

    /** zera a primeira linha da matriz */
    for (i = 0; i <= strlen(string1); i++) {
        matriz[i][0] = 0;
    }

    /** zera a primeira coluna da matriz */
    for (j = 0; j <= strlen(string2); j++) {
        matriz[0][j] = 0;
    }

    /** percorre a matriz e verifica se o elemento atual da linha corresponde ao elemento atual da coluna
     * se corresponder, pega o elemento anterior e soma 1 e adiciona na matriz
     * se não corresponder, compara o elemento anterior da linha e da coluna e retorna o maior elemento
     * para a posição atual da matriz */
    for (i = 1; i <= strlen(string1); i++) {
        for (j = 1; j <= strlen(string2); j++) {
            if (string1[i] == string2[j]) {
                matriz[i][j] = matriz[i - 1][j - 1] + 1;
            } else {
                matriz[i][j] = maiorElemento(matriz[i][j - 1], matriz[i - 1][j]);
            }
        }
    }

/** imprime o lcs de dois filamentos x e y */
    int contador = maiorElemento(strlen(string1), strlen(string2)) + 1;
    char lcs[contador + 1];

    for (i = 0; i <= contador; i++) {
        lcs[i] = ' ';
    }

    x = i, y = j;

    /** caso o filamento x e y estiverem vazios, a condição para
     * se o conteúdo do filamento x corresponder com o conteúdo do filamento y,então significa que houve uma semelhança
     * e que o emento do filamento x foi guardado
     * se o conteúdo do filamento x for maior que conteúdo do filamento y, então procura o próximo elemento de x
     * se o conteúdo do filamento y for maior que conteúdo do filamento y, então procura o próximo elemento de y
     * depois remove os espaços em branco do lcs
     * imprime o conteúdo do lcs */
    while (x > 0 && y > 0) {
        if (string1[x - 1] == string2[y - 1]) {
            lcs[contador - 1] = string1[x - 1];
            x--, y--, contador--;
        } else if (matriz[x - 1][y] > matriz[x][y - 1]) {
            x--;
        } else {
            y--;
        }
    }
    removeEspacosEmBrancoDaString(lcs);
    printf("\nLCS: %s\n", lcs);
    return matriz[strlen(string1)][strlen(string2)];
}

/** se o conteúdo da string na posição atual não estiver 'em branco', o valor será retornado */
void removeEspacosEmBrancoDaString(char *string) {
    int contador = 0;
    for (int i = 0; string[i]; i++) {
        if (string[i] != ' ') {
            string[contador++] = string[i];
        }
    }
    string[contador] = 0;
}

/** dado dois elementos, se o primeiro elemento for maior que o segundo, ele será retornado,
 * se não, o segundo elemento será retornado */
int maiorElemento(int string1, int string2) {
    if (string1 > string2) {
        return string1;
    } else {
        return string2;
    }
}

/** verifica se o arquivo existe e caso existir, percorre o arquivo e adiciona 1 ao contador cada vez que
 * encontra um elemento no arquivo. Depois fecha o arquivo */
int devolveTamanhoConteudoArquivo(FILE* arquivoString, char *nomeArquivo) {
    arquivoString = fopen(nomeArquivo, FILE_MODE);

    int tamanhoConteudoArquivo = 0;

    if (arquivoString == NULL) {
        printf("\nArquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    } else {
        while (!feof(arquivoString)) {
            fgetc(arquivoString);
            tamanhoConteudoArquivo++;
        }
    }
    fclose(arquivoString);
    return tamanhoConteudoArquivo;
}

void manipulaArquivos() {
    FILE *arquivoString1 = NULL;
    FILE *arquivoString2 = NULL;

    /** Mude o path para corresponder aos seus arquivos de texto */
    char *pathArquivo1 = "/Users/jenifer.santos/algorithms-fourth-semester/analysis-of-algorithms/dna/string1.txt";
    char *pathArquivo2 = "/Users/jenifer.santos/algorithms-fourth-semester/analysis-of-algorithms/dna/string2.txt";

    conteudoArquivo1[devolveTamanhoConteudoArquivo(arquivoString1, pathArquivo1) + 1];
    conteudoArquivo2[devolveTamanhoConteudoArquivo(arquivoString2, pathArquivo2) + 1];

    /** abre os arquivos */
    arquivoString1 = fopen(pathArquivo1, FILE_MODE);
    arquivoString2 = fopen(pathArquivo2, FILE_MODE);

    /** percorre os arquivos e lê o conteúdo deles */
    while ((fscanf(arquivoString1, "%s", conteudoArquivo1)) != EOF);
    while ((fscanf(arquivoString2, "%s", conteudoArquivo2)) != EOF);

    /** fecha os arquivos */
    fclose(arquivoString1);
    fclose(arquivoString2);
}

int main() {
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ Determina LCS entre duas cadeias de DNA ~ ~ ~ ~ ~ ~ ~ ~ ~\n");

    manipulaArquivos();
    printf("\nPrimeira cadeia de DNA: %s\n", conteudoArquivo1);
    printf("\nSegunda cadeia de DNA: %s\n", conteudoArquivo2);
    lcs(conteudoArquivo1, conteudoArquivo2);

    EXIT_SUCCESS;
}