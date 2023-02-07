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

using namespace std;

class ArvoreAVL {

private:
    No *raiz;
    int fatorBalanceamento;

public:
    ArvoreAVL();

    No *getRaiz();

    void inserir(int chave);

    No * inserir(No *no, int chave);

    No* insereAEsquerdaDeP(No *no);

     No* insereADireitaDeP(No *no);

    void emOrdem();

    void emOrdem(No *no);

    void DesenhaArvore();

    void DesenhaArvore(No* no, int espacos);
};
