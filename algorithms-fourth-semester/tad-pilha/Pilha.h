//Arquivo de cabeçalho (Interface)

using namespace std;

class Pilha {

private: //atributos visiveis somente na classe onde é utilizado. Por default já são privados!
    int *itens;
    int topo;
    int maximo;

public: //visiveis a todas as classes do projeto
//declaracao da assinatura dos metodos
    Pilha();
    Pilha(int n);
    bool empty();
    bool full();
    bool push(int);
    int pop();
    void print(Pilha &pilha);
    int qtdElementos();
    int localizaPosicao(int num);
    int contabilizaAcima(int num);
    void repetidos(int num);
};
