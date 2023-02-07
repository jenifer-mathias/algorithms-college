/** ******************************************************************
 TAD Árvore BST
 Estrutura de Dados II

 GRUPO

 Nome: Gabriela Lopes Francisco
 TIA: 31744591

 Nome: Giulia Barbieri Quagliano
 TIA: 42013070

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Lucas Martins de Souza
 TIA: 31943187
****************************************************************** */

#include <iostream>
#include "No.cpp"
#include "ArvoreAVL.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    ArvoreAVL arv;

    // insere as chaves
    arv.inserir(8);
    arv.inserir(15);
    arv.inserir(18);
    arv.inserir(25);
    arv.inserir(19);


    // percorre em ordem iniciando da raiz
    cout << "\nPercorrendo em ordem crescrente...\n";
    arv.emOrdem();
    cout << "\nDenhando a arvore deitada...\n";
    arv.DesenhaArvore();
    return 0;
}


