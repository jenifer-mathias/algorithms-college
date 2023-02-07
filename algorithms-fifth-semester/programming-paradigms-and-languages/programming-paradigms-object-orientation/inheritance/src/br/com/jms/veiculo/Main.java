package br.com.jms.veiculo;

public class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * * * * Dados dos veículos * * * * * * *");

        Motor motorCarro = new Motor(1000, 500);
        Carro carro = new Carro(2010, 20000f, motorCarro, "branca", "gol");

        Motor motorCaminhao = new Motor(8000, 900);
        Caminhao caminhao = new Caminhao(2015, 80000f, motorCaminhao, 10f);

        carro.exibirDados();

        caminhao.exibirDados();
    }
}
