package br.com.jms.operacoes;

public class Soma extends Operacao {

    @Override
    int calcular(int x, int y) {
       return x + y;
    }
}
