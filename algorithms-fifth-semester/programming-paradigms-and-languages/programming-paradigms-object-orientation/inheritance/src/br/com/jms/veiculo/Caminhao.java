package br.com.jms.veiculo;

public class Caminhao extends Veiculo {
    Float comprimento;

    public Caminhao(Integer ano, Float preco, Motor motor, Float comprimento) {
        super(motor.cilindrada, motor.potencia, ano, preco);
        this.comprimento = comprimento;
    }

    public void exibirDados() {
        System.out.println(
                "\n~ ~ ~ ~ Caminhão ~ ~ ~ ~  \n" +
                        "\nAno: " + ano +
                        "\nPreço: " + preco +
                        "\nCilindrada do motor: " + cilindrada +
                        "\nPotência: " + potencia +
                        "\nComprimento do caminhão em metros: " + comprimento
        );
    }
}
