package br.com.jms.compracarro;

public class Pessoa {
    String nome;
    Integer idade;
    Carro carro;

    public Pessoa(String nome, Integer idade) {
        this.nome = nome;
        this.idade = idade;
        this.carro = null;
    }

    void compraCarro(Carro carro) {
        this.carro = carro;
    }
}