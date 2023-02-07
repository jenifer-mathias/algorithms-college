package br.com.jms.animal;

public class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * * * * Animal * * * * * * *");

        Animal animal = new Animal("Passarinho", "Azul", 2);
        animal.exibirDados();

        Cachorro cachorro = new Cachorro("Rex", "Marrom", 4, "Vira lata");
        cachorro.exibirDados();
    }
}
