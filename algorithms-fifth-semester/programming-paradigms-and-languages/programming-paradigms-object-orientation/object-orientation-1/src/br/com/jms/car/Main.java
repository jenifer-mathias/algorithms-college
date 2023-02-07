package br.com.jms.car;

class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Controla combustível do carro * * * *");

        Carro carro = new Carro();

        carro.adicionarCombustivel(20.00f);

        carro.andar(80.00f);

        System.out.printf("\nLitros de combustível no tanque: \n%.2f", carro.obterCombustivel());
    }
}

