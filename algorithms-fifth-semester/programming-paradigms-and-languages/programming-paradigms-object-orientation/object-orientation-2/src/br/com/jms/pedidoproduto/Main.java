package br.com.jms.pedidoproduto;

class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Produtos e pedidos * * * *\n");

        Produto cafe = new Produto("Café solúvel", 5.50f, 1);
        Produto arroz = new Produto("Arroz integral", 4.90f, 2);
        Produto feijao = new Produto("Feijão preto", 2.80f, 2);

        Pedido meuPedido = new Pedido();

        meuPedido.adicionarProduto(cafe);
        meuPedido.adicionarProduto(arroz);
        meuPedido.adicionarProduto(feijao);

        System.out.printf("Total: %.2f\n", meuPedido.calcularValorTotal());
    }
}
