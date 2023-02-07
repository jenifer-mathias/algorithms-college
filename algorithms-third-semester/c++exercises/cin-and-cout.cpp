#include <iostream>
using namespace std;

int vetor[10];
int main() {
  float nota1, nota2, media;
  int count = 0;
  cout << "Digite sua 1° nota: ";
  cin >> nota1;
  cout << "Digite sua 2° nota: ";
  cin >> nota2;

  vetor[0] = 10;
  media = (nota1 + nota2) / 2;
  cout << "Média: " << media << endl;
  cout << "Vetor[0] = " << vetor[0] << endl;
  return 0;
}