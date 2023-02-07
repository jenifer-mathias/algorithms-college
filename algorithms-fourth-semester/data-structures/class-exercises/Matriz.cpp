/** 3) Escreva um programa que aloque dinamicamente uma matriz m e a preencha com m[i][j] = i+j,
sendo que o número de linhas e colunas são lidos do teclado. A área de memória alocada deve ser definida em
 função do tamanho da matriz **/

#include <iostream>
using namespace std;

int main() {
    cout << "\nExercicio 3" << endl;

    int **mat; //mat[n][m]
    int l,c,n,m;

    cout << "\nDigite a qde de linhas: ";
    cin >> n;

    cout << "\nDigite a qde de colunas: ";
    cin >> m;

    cout << "\nLinhas: " << n << "\nColunas: " << m << endl;

    cout << endl;

    //alocar o vetor de ptrs
    mat = new int *[n];

    //alocar cada uma das linhas
    for(l=0; l<n; l++)
        mat[l] = new int[m];

    for(l=0; l<n; l++){
        for(c=0; c<m; c++){
            mat[l][c] = l+c;
            cout << mat[l][c] << "\t";
        }
        cout << endl;
    }

    //liberar mem�ria. Primeiro: as linhas
    for(l=0; l<n; l++)
        delete[] mat[l];

    //liberar o vetor de ptrs
    delete[] mat;

    //atribuir NULL ao ptr mat
    mat = nullptr;

    return 0;
}