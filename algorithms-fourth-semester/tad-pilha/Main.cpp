/** ******************************************************************
 TAD Pilha
 Estrutura de Dados I
****************************************************************** */

#include <iostream>
// #include <conio.h> // Uso para Windows
#include <ncurses.h> // Uso para Linux
#include "Pilha.h" //Header com declaracao dos metodos/operacoes

using namespace std;

int main() {

    cout << "\n              Iniciando a execução ... \n\n\n";
    cout << "Antes de tudo, qual o tamanho da pilha que deseja criar? ";
    int tam;
    cin >> tam;
    int opc;
    Pilha p(tam); //criando uma Pilha de tamanho tam

    cout << "\n\n\n";
    cout << "\n---------------------------------------------------------------";
    cout << "\n                        TAD PILHA";
    cout << "\n (esta pilha só aceita números inteiros maiores do que zero)";
    cout << "\n---------------------------------------------------------------";

    do {
        cout << "\n\n________________________   MENU   _____________________________\n";
        cout << "\n0 - sair\n";
        cout << "\n1 - quantidade de elementos na pilha\n";
        cout << "\n2 - inserir um elemento na pilha\n";
        cout << "\n3 - remover um elemento da pilha (retorna o elemento removido)\n";
        cout << "\n4 - verifica se determinado elemento está na pilha ";
        cout << "\n    e retorna sua posição em relação ao topo\n";
        cout << "\n5 - quantidade elementos acima de um determinado valor\n";
        cout << "\n6 - imprime os elementos da pilha e a quantidade";
        cout << "\n    de ocorrências do número escolhido\n";
        cout << "\n7 - imprimir a pilha\n";
        cout << "\n\n_______________________________________________________________\n";

        cout << "\n\nInforme sua opção: ";
        cin >> opc;

        switch (opc) {
            case 0: {
                cout << "\n Agradecemos a participação!";
                cout << "\n\n ~~~~ Fim da execucao! ~~~~\n\n";
                break;
            }

            case 1: {
                int x = p.qtdElementos();
                cout << "\nA pilha contém " << x << " elemento";
                if (x > 1) cout << "s";
                break;
            }

            case 2: {
                int valor;
                cout << "\nValor do elemento a ser inserido: ";
                cin >> valor;
                if (p.push(valor)) {
                    cout << "\nElemento " << valor << " inserido com sucesso.";
                }
                break;
            }

            case 3: {
                int x = p.pop();
                if (x > -1) {
                    cout << "\nElemento " << x << " foi removido.";
                } else {
                    cout << "\nA pilha está vazia.";
                }
                break;
            }

            case 4: {
                cout << "\nInforme o elemento que deseja procurar: ";
                int opc4;
                cin >> opc4;
                int x = p.localizaPosicao(opc4);
                if (x == -1) {
                    cout << "\nA pilha está vazia!";
                    break;
                }
                if (x > -1) {
                    cout << "\nElemento localizado na posição (em relação ao topo): " << x;
                }
                if (x == -2) {
                    cout << "\nElemento não localizado!";
                }
                break;
            }

            case 5: {
                cout << "\nInforme o valor: ";
                int opc5;
                cin >> opc5;
                int x = p.contabilizaAcima(opc5);
                if (p.empty()) {
                    cout << "\nA pilha está vazia!";
                    break;
                }
                cout << x;
                break;
            }

            case 6: {
                cout << "\nInforme um número: ";
                int opc6;
                cin >> opc6;
                p.repetidos(opc6);
                break;
            }

            case 7: {
                p.print(p);
                break;
            }

            default: {
                cout << "\n Opção inválida.";
                break;
            }
        }
    } while (opc != 0);
}
