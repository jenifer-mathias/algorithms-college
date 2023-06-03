/**

 REPRESENTACAO DE GRAFOS - Versao 2023/1

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20

/**
 * Estrutura de dados para representar grafos
 */
typedef struct aresta { /** Celula de uma lista de arestas */
    int id;
    struct aresta *p;
} Aresta;

typedef struct vert { /** Cada vertice tem um ponteiro para uma lista de arestas
                         incidentes nele */
    int id;
    char nome[50];
    Aresta *prim;
} Vert;

typedef struct {
    int vertices[MAX_VERTICES];
    int count;
} VertexSet;

typedef struct {
    VertexSet panelinhas[MAX_VERTICES];
    int count;
} Panelinhas;

int maiorPanelinha;
Panelinhas M;

/**
 * Declaracoes das funcoes para manipulacao de grafos
 */
void criaGrafo(Vert **G, int ordem);

void destroiGrafo(Vert **G, int ordem);

int acrescentaAresta(Vert G[], int ordem, int v1, int v2);

void imprimeGrafo(Vert G[], int ordem);

int calculaGrau(Vert G[], int ordem, int v);

int calculaGrauMax(Vert G[], int ordem);

void retornaSemAmigos(Vert G[], int ordem);

void retornaUmAmigo(Vert G[], int ordem);

void retornaMaisAmigos(Vert G[], int ordem);

void addVertex(VertexSet *set, int vertex);

void removeVertex(VertexSet *set, int vertex);

void inicializaVertex(VertexSet *set);

void retornaQuantidadeAmigos(int v, Vert G[], int ordemG);

void bronKerbosch(Vert *G, int graph[MAX_VERTICES][MAX_VERTICES], VertexSet R, VertexSet P, VertexSet X);

void transformaGrafoMatriz(Vert *G, int graph[MAX_VERTICES][MAX_VERTICES], int ordemG);

void imprimeMaiorPanelinha(Panelinhas M, int maiorPanelinha, Vert *G);

void retornaPanelinha(Panelinhas M, Vert *G, int v);

/**
 * Criacao de um grafo com ordem predefinida (passada como argumento),
 *   e, inicilamente, sem nenhuma aresta
 */
void criaGrafo(Vert **G, int ordem) {
    int i;
    *G = (Vert *) malloc(sizeof(Vert) *
                         ordem); /** Alcacao dinamica de um vetor de vertices */

    for (i = 0; i < ordem; i++) {
        (*G)[i].id = i;
        (*G)[i].prim = NULL; /** Cada vertice sem nenua aresta incidente */
    }
}

/**
 * Deasaloca a memoria dinamica usada para armazenar um grafo.
 */
void destroiGrafo(Vert **G, int ordem) {
    int i;
    Aresta *a, *n;

    for (i = 0; i < ordem;
         i++) { /** Remove lista de adjacencia de cada vertice */
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

    if (v1 < 0 || v1 >= ordem) /** Testa se os vertices sao validos */
        return 0;
    if (v2 < 0 || v2 >= ordem)
        return 0;

    /** Acrescento aresta na lista do vertice v1 */
    A1 = (Aresta *) malloc(sizeof(Aresta));
    A1->id = v2;
    A1->p = G[v1].prim;
    G[v1].prim = A1;

    if (v1 == v2)
        return 1; /* Aresta e� um laco */

    /** Acrescenta aresta na lista do vertice v2 se v2 != v1 */
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

    printf("\nOrdem: %d", ordem);

    for (i = 0; i < ordem; i++) {
        printf("\n\nAmigos de %s: ", G[i].nome);
        aux = G[i].prim;
        for (; aux != NULL; aux = aux->p)
            printf("\n%s", G[aux->id].nome);
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
        if (aux->id == v)
            i++; /** Se for laco, conta 2 vezes */
    return (i);
}

int calculaGrauMax(Vert G[], int ordem) {
    int max = 0;
    for (int i = 0; i < ordem; i++) {
        int g = calculaGrau(G, ordem, i);
        if (g > max) {
            max = g;
        }
    }
    return max;
}

void retornaSemAmigos(Vert G[], int ordem) {
    printf("Usuários sem amigos:\n");
    for (int i = 0; i < ordem; i++) {
        int g = calculaGrau(G, ordem, i);
        if (g == 0) {
            printf("%s\n", G[i].nome);
        }
    }
}

void retornaUmAmigo(Vert G[], int ordem) {
    printf("\nUsuários com apenas um amigo:\n");
    for (int i = 0; i < ordem; i++) {
        int g = calculaGrau(G, ordem, i);
        if (g == 1) {
            printf("%s\n", G[i].nome);
        }
    }
}

void retornaMaisAmigos(Vert G[], int ordem) {
    printf("\nUsuários com a maior quantidade de amigos:\n");
    int max = calculaGrauMax(G, ordem);
    for (int i = 0; i < ordem; i++) {
        if (calculaGrau(G, ordem, i) == max) {
            printf("%s\n", G[i].nome);
        }
    }
}

void retornaQuantidadeAmigos(int v, Vert G[], int ordemG) {
    for (v = 0; v < ordemG; v++) {
        int i = calculaGrau(G, ordemG, v);
        printf("\n%s tem %d amigos", G[v].nome, i);
    }
    printf("\n");
}

void inicializaVertex(VertexSet *set) {
    set->count = 0;
}

void addVertex(VertexSet *set, int vertex) {
    set->vertices[set->count++] = vertex;
}

void removeVertex(VertexSet *set, int vertex) {
    int i, j;
    for (i = 0; i < set->count; i++) {
        if (set->vertices[i] == vertex) {
            for (j = i; j < set->count - 1; j++) {
                set->vertices[j] = set->vertices[j + 1];
            }
            set->count--;
            return;
        }
    }
}

void bronKerbosch(Vert *G, int graph[MAX_VERTICES][MAX_VERTICES], VertexSet R, VertexSet P, VertexSet X) {
    if (P.count == 0 && X.count == 0) {
        if (R.count >= 3) { /** Condição para "panelinhas" */
            printf("\nPanelinha encontrada: \n");
            int i;
            for (i = 0; i < R.count; i++) {
                if (R.count < M.panelinhas[M.count].count) {
                    maiorPanelinha = M.panelinhas[M.count].count;
                } else {
                    maiorPanelinha = R.count;
                }
                printf("%s \n", G[R.vertices[i]].nome);
                M.panelinhas[M.count].vertices[i] = G[R.vertices[i]].id;
                M.panelinhas[M.count].count = R.count;
            }
            printf("\n");
            M.count++;
        }
        return;
    }

    VertexSet Pcopy = P;
    int pivotVertex = Pcopy.vertices[0];
    int i;
    for (i = 0; i < Pcopy.count; i++) {
        int vertex = Pcopy.vertices[i];
        if (graph[pivotVertex][vertex]) {
            continue;
        }

        VertexSet Rnew = R;
        addVertex(&Rnew, vertex);
        VertexSet Pnew;
        inicializaVertex(&Pnew);
        VertexSet Xnew;
        inicializaVertex(&Xnew);

        int j;
        for (j = 0; j < P.count; j++) {
            int v = P.vertices[j];
            if (graph[vertex][v]) {
                addVertex(&Pnew, v);
            }
        }

        for (j = 0; j < X.count; j++) {
            int v = X.vertices[j];
            if (graph[vertex][v]) {
                addVertex(&Xnew, v);
            }
        }

        bronKerbosch(G, graph, Rnew, Pnew, Xnew);

        removeVertex(&P, vertex);
        addVertex(&X, vertex);
    }
}

void transformaGrafoMatriz(Vert *G, int graph[MAX_VERTICES][MAX_VERTICES], int ordemG) {
    int i, j;
    Aresta *aux;

    for (i = 0; i < ordemG; i++) {
        for (j = 0; j < ordemG; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < ordemG; i++) {
        aux = G[i].prim;
        while (aux != NULL) {
            j = aux->id;
            graph[i][j] = 1;
            aux = aux->p;
        }
    }
}

void imprimeMaiorPanelinha(Panelinhas M, int maiorPanelinha, Vert *G) {
    int i, j;
    printf("\nMaior(es) Panelinha(s):\n");
    for (i = 0; i < M.count; i++) {
        if (M.panelinhas[i].count == maiorPanelinha) {
            for (j = 0; j < M.panelinhas[i].count; j++) {
                printf("%s\n", G[M.panelinhas[i].vertices[j]].nome);
            }
            printf("\n");
        }
    }
}

void retornaPanelinha(Panelinhas M, Vert *G, int v) {
    int i, j, k;
    int amigosEncontrados = 0;

    printf("Panelinha(s) com %s:\n", G[v].nome);
    for (i = 0; i < M.count; i++) {
        for (j = 0; j < M.panelinhas[i].count; j++) {
            if (M.panelinhas[i].vertices[j] == v) {
                amigosEncontrados = M.panelinhas[i].count;
                for (k = 0; k < amigosEncontrados; k++) {
                    printf("%s\n", G[M.panelinhas[i].vertices[k]].nome);
                }
            }
        }
    }
    if (amigosEncontrados == 0) {
        printf("O usuário ainda não possui amigos!\n");
    }
}

/**
 * Programa simples para testar a representacao do grafo
 */
int main(int argc, char *argv[]) {
    int v = 0;
    Vert *G;
    int ordemG = 20;

    criaGrafo(&G, ordemG);

    acrescentaAresta(G, ordemG, 1, 9);
    acrescentaAresta(G, ordemG, 2, 7);
    acrescentaAresta(G, ordemG, 2, 13);
    acrescentaAresta(G, ordemG, 2, 14);
    acrescentaAresta(G, ordemG, 3, 15);
    acrescentaAresta(G, ordemG, 4, 6);
    acrescentaAresta(G, ordemG, 4, 19);
    acrescentaAresta(G, ordemG, 6, 19);
    acrescentaAresta(G, ordemG, 7, 13);
    acrescentaAresta(G, ordemG, 8, 9);
    acrescentaAresta(G, ordemG, 8, 11);
    acrescentaAresta(G, ordemG, 9, 15);
    acrescentaAresta(G, ordemG, 9, 16);
    acrescentaAresta(G, ordemG, 9, 18);
    acrescentaAresta(G, ordemG, 10, 11);
    acrescentaAresta(G, ordemG, 11, 12);
    acrescentaAresta(G, ordemG, 11, 17);
    acrescentaAresta(G, ordemG, 11, 0);
    acrescentaAresta(G, ordemG, 13, 14);
    acrescentaAresta(G, ordemG, 13, 15);
    acrescentaAresta(G, ordemG, 13, 17);
    acrescentaAresta(G, ordemG, 13, 0);
    acrescentaAresta(G, ordemG, 15, 16);

    strcpy(G[0].nome, "Bernardo");
    strcpy(G[1].nome, "José");
    strcpy(G[2].nome, "Jenifer");
    strcpy(G[3].nome, "Matheus");
    strcpy(G[4].nome, "Richard");
    strcpy(G[5].nome, "João");
    strcpy(G[6].nome, "Maria");
    strcpy(G[7].nome, "Ana");
    strcpy(G[8].nome, "Mario");
    strcpy(G[9].nome, "Leandro");
    strcpy(G[10].nome, "Carolina");
    strcpy(G[11].nome, "Ana Elisa");
    strcpy(G[12].nome, "Mariana");
    strcpy(G[13].nome, "Geovanne");
    strcpy(G[14].nome, "Kaio");
    strcpy(G[15].nome, "Henrique");
    strcpy(G[16].nome, "Laura");
    strcpy(G[17].nome, "Denise");
    strcpy(G[18].nome, "Douglas");
    strcpy(G[19].nome, "Daniela");

    imprimeGrafo(G, ordemG);

    retornaSemAmigos(G, ordemG);

    retornaUmAmigo(G, ordemG);

    retornaMaisAmigos(G, ordemG);

    retornaQuantidadeAmigos(v, G, ordemG);

    VertexSet R, P, X;
    inicializaVertex(&R);
    inicializaVertex(&P);
    inicializaVertex(&X);

    M.count = 0;
    int a;
    for (a = 0; a < MAX_VERTICES; a++) {
        inicializaVertex(&M.panelinhas[a]);
    }

    int graph[MAX_VERTICES][MAX_VERTICES];

    transformaGrafoMatriz(G, graph, ordemG);

    int i;
    for (i = 0; i < ordemG; i++) {
        addVertex(&P, i);
    }

    bronKerbosch(G, graph, R, P, X);

    imprimeMaiorPanelinha(M, maiorPanelinha, G);

    retornaPanelinha(M, G, 5);

    destroiGrafo(&G, ordemG);

    return 0;
}