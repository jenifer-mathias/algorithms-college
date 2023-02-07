package br.com.jms.pessoa;

public class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Pessoa * * * *\n");

        Pessoa p1 = new Pessoa("João da Silva");
        Pessoa p2 = new Pessoa("Maria Andrade");
        Pessoa p3 = new Pessoa("Alan Bida");
        p1.escreverNome(); // João da Silva
        p2.escreverNome("Senhorita"); // Senhorita Maria Andrade
        p3.escreverNome(3); // Alan Bida Alan Bida Alan Bida
    }
}
