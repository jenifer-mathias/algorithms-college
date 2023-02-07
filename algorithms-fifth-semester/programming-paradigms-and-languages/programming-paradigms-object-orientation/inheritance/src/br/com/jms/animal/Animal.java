package br.com.jms.animal;

public class Animal {
    String nome;
    String cor;
    Integer numeroPatas;

    public Animal(String nome, String cor, Integer numeroPatas) {
        this.nome = nome;
        this.cor = cor;
        this.numeroPatas = numeroPatas;
    }

    public void exibirDados() {
        System.out.println(
                "\nNome do animal: " + nome +
                        "\nCor: " + cor +
                        "\nNúmero de patas: " + numeroPatas
        );
    }
}
