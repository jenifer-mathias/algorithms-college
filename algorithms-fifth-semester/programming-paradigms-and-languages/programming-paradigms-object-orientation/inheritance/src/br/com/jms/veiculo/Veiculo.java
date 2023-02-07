package br.com.jms.veiculo;

public class Veiculo extends Motor {
    Integer ano;
    Float preco;

    public Veiculo(Integer cilindrada, Integer potencia, Integer ano, Float preco) {
        super(cilindrada, potencia);
        this.ano = ano;
        this.preco = preco;
    }

    public void exibirDados() {
        System.out.println(
                "\nAno de fabricação do veículo: " + ano +
                        "\nPreço: " + preco
        );
    }
}
