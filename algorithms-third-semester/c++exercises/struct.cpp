#include <iostream>
#include <string>
using namespace std;

struct Produto {
    string marca;
    float preco;
};

struct Fruta {
    string nomeFruta;
    float preco;
};

struct Automovel {
    string cor;
    float preco;
};

struct Aluno {
    string nome;
    float matricula;
};

int main() {
    Produto mouse;
    mouse.marca = "Multilaser";
    mouse.preco = 60.0;
    cout << mouse.marca << '\n';

    Fruta fruta;
    fruta.nomeFruta = "morango";
    fruta.preco = 10.0;
    cout << fruta.nomeFruta << '\n';

    Automovel carro;
    carro.cor = "preto";
    carro.preco = 60.000;
    cout << carro.cor << '\n';

    Aluno aluno;
    aluno.nome = "Jenifer";
    aluno.matricula = 123456;
    cout << aluno.nome << '\n';
}
