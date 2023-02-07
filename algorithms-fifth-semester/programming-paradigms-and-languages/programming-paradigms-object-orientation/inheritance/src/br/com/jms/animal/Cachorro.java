package br.com.jms.animal;

public class Cachorro extends Animal {
    String raca;

    public Cachorro(String nome, String cor, Integer numeroPatas, String raca) {
        super(nome, cor, numeroPatas);
        this.raca = raca;
    }

    public void exibirDados() {
        System.out.println(
                "\nNome do animal: " + nome +
                        "\nCor: " + cor +
                        "\nNúmero de patas: " + numeroPatas +
                        "\nRaça: " + raca
        );
    }
}
