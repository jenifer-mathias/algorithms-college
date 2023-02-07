package br.com.jms.carropneu;

public class Carro {
    Boolean ligado;
    Pneu pneu1;
    Pneu pneu2;
    Pneu pneu3;
    Pneu pneu4;

    public Carro(Pneu pneu1, Pneu pneu2, Pneu pneu3, Pneu pneu4) {
        this.ligado = false;
        this.pneu1 = pneu1;
        this.pneu2 = pneu2;
        this.pneu3 = pneu3;
        this.pneu4 = pneu4;
    }

    public void ligar() {
        this.ligado = true;
    }

    public void desligar() {
        this.ligado = false;
    }

    public void verificarPneu() {
        if (ligado) {
            System.out.println("Pressão pneu 1: " + pneu1.pressao);
            System.out.println("Pressão pneu 2: " + pneu2.pressao);
            System.out.println("Pressão pneu 3: " + pneu3.pressao);
            System.out.println("Pressão pneu 4: " + pneu4.pressao);
        } else {
            System.out.println("\nCarro desligado!\n");
        }
    }
}

