package br.com.jms.triangle;

class Triangulo {
    Double ladoA;
    Double ladoB;
    Double ladoC;

    public Triangulo(Double ladoA, Double ladoB, Double ladoC) {
        this.ladoA = ladoA;
        this.ladoB = ladoB;
        this.ladoC = ladoC;
    }

    public Double calculaPerimetro(Triangulo triangulo) {
        return triangulo.ladoA + triangulo.ladoB + triangulo.ladoC;
    }
}
