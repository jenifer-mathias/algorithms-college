package br.com.jms.carropneu;

public class Pneu {
    Integer pressao;

    public Pneu(Integer pressao) {
        this.pressao = pressao;
    }

    public void furar() {
        this.pressao = 0;
    }
}
