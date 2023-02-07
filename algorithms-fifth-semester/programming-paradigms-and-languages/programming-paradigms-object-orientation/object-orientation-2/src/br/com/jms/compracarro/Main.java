package br.com.jms.compracarro;

class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Compra de carros * * * *\n");

        Carro golzinho = new Carro("Volkswagem", "Gol", "AAA-1111", 2015);
        Pessoa pessoa = new Pessoa("João", 25);

        pessoa.compraCarro(golzinho);
        System.out.println("Nome: " + pessoa.nome);
        System.out.println("Modelo do carro: " + pessoa.carro.modelo);
        System.out.println("Placa do carro: " + pessoa.carro.placa);

        Carro hondaCivic = new Carro("Honda", "Honda Civic", "JMS-1234", 2022);
        Pessoa eu = new Pessoa("Jenifer", 22);

        eu.compraCarro(hondaCivic);
        System.out.println("\nNome: " + eu.nome);
        System.out.println("Modelo do carro: " + eu.carro.modelo);
        System.out.println("Ano: " + eu.carro.ano);
        System.out.println("Placa do carro: " + eu.carro.placa);
    }
}

