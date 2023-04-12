/**
 * REPRESENTACAO DE GRAFOS - Versao do Prof. 2023/1
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>


/**
 * Estrutura de dados para representar grafos
 */
typedef struct aresta { /** Celula de uma lista de arestas */
    int id;
    struct aresta *p;
} Aresta;

typedef struct vert {  /** Cada vertice tem um ponteiro para uma lista de arestas incidentes nele */
    int id;
    Aresta *prim;
} Vert;

/**
 * Declaracoes das funcoes para manipulacao de grafos
 */
void criaGrafo(Vert **G, int ordem);

void destroiGrafo(Vert **G, int ordem);

int acrescentaAresta(Vert G[], int ordem, int v1, int v2);

void imprimeGrafo(Vert G[], int ordem);

int calculaGrau(Vert G[], int ordem, int v);

int calculaGrauMin(Vert G[], int ordem);

int calculaGrauMax(Vert G[], int ordem);

int eRegular(Vert G[], int ordem); // todos os vertices tem o mesmo grau

int eSimples(Vert G[], int ordem); // sem lacos e sem arestas paralelas

/**
 * Criacao de um grafo com ordem predefinida (passada como argumento),
 *   e, inicilamente, sem nenhuma aresta
 */
void criaGrafo(Vert **G, int ordem) {
    int i;
    *G = (Vert *) malloc(sizeof(Vert) * ordem); /** Alcacao dinamica de um vetor de vertices */

    for (i = 0; i < ordem; i++) {
        (*G)[i].id = i;
        (*G)[i].prim = NULL;    /** Cada vertice sem nenhuma aresta incidente */
    }
}

/**
 * Deasaloca a memoria dinamica usada para armazenar um grafo.
 */
void destroiGrafo(Vert **G, int ordem) {
    int i;
    Aresta *a, *n;

    for (i = 0; i < ordem; i++) { /** Remove lista de adjacencia de cada vertice */
        a = (*G)[i].prim;
        while (a != NULL) {
            n = a->p;
            free(a);
            a = n;
        }
    }
    free(*G);
}

/**
 * Acrescenta uma nova aresta em um grafo previamente criado.
 *   Devem ser passados os extremos v1 e v2 da aresta a ser acrescentada
 * Como o grafo nao e orientado, para uma aresta com extremos i e j
 *   serao criadas, na estrutura de dados, arestas (i,j) e (j,i)
 */
int acrescentaAresta(Vert G[], int ordem, int v1, int v2) {
    Aresta *A1, *A2;

    if (v1 < 0 || v1 >= ordem) /** Testo se vertices sao validos */
        return 0;
    if (v2 < 0 || v2 >= ordem)
        return 0;

    /** Acrescento aresta na lista do vertice v1 */
    A1 = (Aresta *) malloc(sizeof(Aresta));
    A1->id = v2;
    A1->p = G[v1].prim;
    G[v1].prim = A1;

    /** Aresta e um laco */
    if (v1 == v2) return 1; // toda aresta é representada 2x exceto o laco

    /** Acrescento aresta na lista do vertice v2 se v2 != v1 */
    A2 = (Aresta *) malloc(sizeof(Aresta));
    A2->id = v1;
    A2->p = G[v2].prim;
    G[v2].prim = A2;

    return 1;
}

/**
 * Imprime um grafo com uma notacao similar a uma lista de adjacencia.
 */
void imprimeGrafo(Vert G[], int ordem) {
    int i;
    Aresta *aux;

    printf("\nOrdem: %d\n", ordem);
    printf("\nLista de Adjacencia:\n");

    for (i = 0; i < ordem; i++) {
        printf("\n    v%d: ", i);
        aux = G[i].prim;
        for (; aux != NULL; aux = aux->p)
            printf("  v%d", aux->id);
    }
    printf("\n\n");
}

/**
 * Retorna o grau de um vertice v de um grafo G.
 */
int calculaGrau(Vert G[], int ordem, int v) {
    int i;
    Aresta *aux;

    if (v < 0 || v >= ordem)
        return (-1);
    aux = G[v].prim;
    /** Percorre a lista de arestas que incidem em v, contando qtd. */
    for (i = 0; aux != NULL; aux = aux->p, i++)
        if (aux->id == v) i++;  /** Se for laco, conto 2 vezes */
    return (i);
}

/** EXERCICIOS */

// Grau: Numero de arestas que incidem no grafo

int calculaGrauMin(Vert G[], int ordem) {

}

int calculaGrauMax(Vert G[], int ordem) {

}

int eRegular(Vert G[], int ordem) {

}

int eSimples(Vert G[], int ordem) {

}

/**
 * Programinha simples para testar a representacao de grafo
 */
int main(int argc, char *argv[]) {
    int i, v;
    Vert *G;
    int ordemG = 6;

    criaGrafo(&G, ordemG); // quantidade de vertices

    acrescentaAresta(G, ordemG, 0, 0);
    acrescentaAresta(G, ordemG, 0, 1);
    acrescentaAresta(G, ordemG, 0, 2);
    acrescentaAresta(G, ordemG, 0, 3);
    acrescentaAresta(G, ordemG, 2, 4);
    acrescentaAresta(G, ordemG, 2, 5);
    acrescentaAresta(G, ordemG, 3, 5);
    acrescentaAresta(G, ordemG, 4, 5);

    imprimeGrafo(G, ordemG);

    for (v = 0; v < ordemG; v++) {
        i = calculaGrau(G, ordemG, v);
        printf("O grau do vertice %d é %d\n", v, i);
    }

    destroiGrafo(&G, ordemG);
    return 0;
}