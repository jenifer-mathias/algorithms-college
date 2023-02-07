#include <iostream>
#include "No.h"
#include "ArvoreAVL.h"

using namespace std;

ArvoreAVL::ArvoreAVL() {
    raiz = nullptr;
}

void ArvoreAVL::inserir(int chave) {
    raiz = inserir(raiz, chave);
}

/** insere recursivamente um novo no */
No *ArvoreAVL::inserir(No *no, int chave) {
    if (no == nullptr) {
        /** seta que alterou a subarvore e é para testar o Fator de Balanceamento */
        fatorBalanceamento = 1;
        return new No(chave);
    }
    /** se for menor, então insere à esquerda */
    if (chave < no->getChave()) {
        /** percorre recursivamente a subarvore da esquerda */
        no->setEsq(inserir(no->getEsq(), chave));

        /** testa o fator de  balanceamento após a inserção na subarvore da esquerda */
        if (fatorBalanceamento) {
            switch (no->getFB()) {
                case 1: /** se o nó estava maior para direita e inseriu à esquerda */
                    no->setFB(0); /** seta que ficou balanceado */
                    fatorBalanceamento = 0; /** tudo ficou normalizado, não precisa atualizar mais a arvore */
                    break;
                case 0: /** se estava balanceado e como adicionou à esquerda */
                    no->setFB(-1);
                    break;
                case -1: /** á estava desbalanceado para esquerda */
                    no = insereAEsquerdaDeP(no); /** no=p, vamos ver qual rotacao usar */
                    fatorBalanceamento = 0; /** tudo ficou normalizado, não precisa atualizar mais a arvore */
                    break;
            }
        }
    }
        /** se for maior, entao insere a direita */
    else if (chave > no->getChave()) {

        /** percorre recursivamente a subarvore da direita */
        no->setDir(inserir(no->getDir(), chave));
        /** testa o fator de  balanceamento apos a insercao na subarvore da esquerda */
        if (fatorBalanceamento) {
            switch (no->getFB()) {
                case -1: /** se o nó estava maior para esquerda e inseriu a direita */
                    no->setFB(0); /** seta que agora ficou balanceado */
                    fatorBalanceamento = 0; /** tudo ficou normalizado, nao precisa atualizar mais a arvore */
                    break;
                case 0:/** se estava balanceado e como adicionou a direita */
                    no->setFB(1);
                    break;
                case 1: /** ja estava desbalanceado para direita */
                    no = insereADireitaDeP(no); /** no=p, vamos ver qual rotacao usar */
                    fatorBalanceamento = 0; /** tudo ficou normalizado, nao precisa atualizar mais a arvore */
                    break;
            }
        }
    }
/** caso no->chave = chave retorna o proprio n. Nao pode existir 2 chaves iguais */
    return no;
}

No *ArvoreAVL::insereAEsquerdaDeP(No *p) {
    No *u, *v;

/** filho a esquerda de p */
    u = p->getEsq();
/** inseriu na subarvore esquerda de u */
/** fazer uma rotacao simples a direita */
    if (u->getFB() == -1) {
        p->setEsq(u->getDir());
        u->setDir(p);
        /** ajusta o novo balanceamento de p pois ele passa ser uma T1 - T2 = 0 */
        p->setFB(0);
        p = u; /** p passa ser o u */
        cout << " => realizada uma rotacao simples a direita \n";
    }
        /** inseriu na subarvore direita de u. Fazer uma rotacao dupla a direita */
    else {
        v = u->getDir();           /** aqui poderia ser o q caso T2 e T3 sejam nulos */
        u->setDir(v->getEsq());
        p->setEsq(v->getDir());
        v->setEsq(u);
        v->setDir(p);
        if (v->getFB() == -1) { /** se inseriu na subarvore esquerda de v*/
            p->setFB(1);
            u->setFB(0);
        } else if (v->getFB() == 1) { /** se inseriu na subarvore direita de v */
            p->setFB(0);
            u->setFB(-1);
        } else { /** v = q */
            p->setFB(0);
            u->setFB(0);
        }
        p = v; /** p passa ser o v */
        cout << " => realizada uma rotacao dupla a direita \n";
    }
    p->setFB(0);
    return p;
}

No *ArvoreAVL::insereADireitaDeP(No *p) {
    No *z, *y;

/** filho a direita de p */
    z = p->getDir();
/** inseriu na subarvore direita de z. Fazer uma rotacao a esquerda */
    if (z->getFB() == 1) {
        p->setDir(z->getEsq());
        z->setEsq(p);
        /** ajusta o novo balanceamento de p pois ele passa ser uma T1 - T2 = 0 */
        p->setFB(0);
        p = z;
        cout << " => realizada uma rotacao simples a esquerda \n";
    }
        /** inseriu na subarvore direita de z. Fazer uma rotacao dupla a esquerda */
    else {
        y = z->getEsq();
        z->setEsq(y->getDir());
        p->setDir(y->getEsq());
        y->setEsq(p);
        y->setDir(z);

        if (y->getFB() == 1) { /** se inseriu na subarvore direita y */
            p->setFB(-1);
            z->setFB(0);
        } else if (y->getFB() == -1) { /** se inseriu na subarvore esquerda de y */
            p->setFB(0);
            z->setFB(1);
        } else { /** y == q */
            z->setFB(0);
            p->setFB(0);
        }
        p = y;
        cout << " => realizada uma rotacao dupla a esquerda \n";
    }
    p->setFB(0);
    return p;
}

/** polimorfismo de sobrecarga */
void ArvoreAVL::emOrdem() {
    emOrdem(raiz);
}

void ArvoreAVL::emOrdem(No *no) {
    if (no != nullptr) {
        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
    }
}

void ArvoreAVL::DesenhaArvore() {
    DesenhaArvore(raiz, 0);
}

void ArvoreAVL::desenhaArvore(No *no, int espacos) {
    if (no != nullptr) {
        DesenhaArvore(no->getDir(), espacos + 4);

        for (int i = 0; i < espacos; i++)
            cout << " ";

        cout << no->getChave() << "[" << no->getFB() << "]\n";

        DesenhaArvore(no->getEsq(), espacos + 4);
    }
}