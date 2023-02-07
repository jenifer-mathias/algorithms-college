package br.com.jms.moedas;

import java.util.ArrayList;

public class Cofre {
    ArrayList<Moeda> moedas;

    public Cofre() {
        this.moedas = new ArrayList<>();
    }

    void adicionar(Moeda moeda) {
        moedas.add(moeda);
    }

    Float calcularTotal() {
        float valorTotal = 0;
        for (Moeda m: moedas) {
            valorTotal += m.valor;
        }
        return valorTotal;
    }
}