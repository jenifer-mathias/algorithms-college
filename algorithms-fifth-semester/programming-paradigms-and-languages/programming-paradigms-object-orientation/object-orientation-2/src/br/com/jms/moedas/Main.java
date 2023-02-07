package br.com.jms.moedas;

class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * * Cofre * * * * *\n");

        Moeda moeda1 = new Moeda(0.25f);
        Moeda moeda2 = new Moeda(0.50f);
        Moeda moeda3 = new Moeda(1.00f);

        Cofre cofre = new Cofre();

        cofre.adicionar(moeda1);
        cofre.adicionar(moeda2);
        cofre.adicionar(moeda3);

        System.out.println("O valor total é: " + cofre.calcularTotal());

    }
}
