package br.com.jms.pedidoproduto;

public class Produto {
    String nome;
    Float preco;
    Integer quantidade;

    public Produto(String nome, Float preco, Integer quantidade) {
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }
}
