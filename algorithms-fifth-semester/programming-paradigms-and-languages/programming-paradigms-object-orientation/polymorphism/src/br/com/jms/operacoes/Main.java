package br.com.jms.operacoes;

public class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Operações matemáticas * * * *\n");

        Soma soma = new Soma();
        Subtracao sub = new Subtracao();
        Divisao div = new Divisao();
        Multiplicacao mult = new Multiplicacao();

        System.out.printf("Soma: %d\n", soma.calcular(10, 5)); // 15
        System.out.printf("Subtração: %d\n", sub.calcular(10, 5)); // 5
        System.out.printf("Divisão: %d\n", div.calcular(10, 5)); // 2
        System.out.printf("Multiplicação: %d\n", mult.calcular(10, 5)); // 50
    }
}
