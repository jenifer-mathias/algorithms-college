package br.com.jms.pedidoproduto;

import java.util.ArrayList;

public class Pedido {
    ArrayList<Produto> listaProdutos;

    public Pedido() {
        this.listaProdutos = new ArrayList<>();
    }

    public void adicionarProduto(Produto produto) {
        this.listaProdutos.add(produto);
    }

    public Float calcularValorTotal() {
        float precoTotal = 0;
        for (Produto p : listaProdutos) {
            precoTotal += p.preco;
        }
        return precoTotal;
    }
}