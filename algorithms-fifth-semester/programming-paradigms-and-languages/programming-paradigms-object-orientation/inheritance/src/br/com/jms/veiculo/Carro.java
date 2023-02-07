package br.com.jms.veiculo;

public class Carro extends Veiculo {
    String cor;
    String modelo;

    public Carro(Integer ano, Float preco, Motor motor, String cor, String modelo) {
        super(motor.cilindrada, motor.potencia, ano, preco);
        this.cor = cor;
        this.modelo = modelo;
    }

    public void exibirDados() {
        System.out.println(
                "\n~ ~ ~ ~ ~ Carro ~ ~ ~ ~ ~  \n" +
                        "\nAno: " + ano +
                        "\nPreço: " + preco +
                        "\nCilindrada do motor: " + cilindrada +
                        "\nPotência: " + potencia +
                        "\nCor do carro: " + cor +
                        "\nModelo: " + modelo
        );
    }
}
