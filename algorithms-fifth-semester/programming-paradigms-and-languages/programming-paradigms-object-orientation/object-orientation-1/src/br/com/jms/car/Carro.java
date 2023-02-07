package br.com.jms.car;

public class Carro {
    Float quantidadeCombustivel;

    public Carro() {
        this.quantidadeCombustivel = 0.00f;
    }

    public Float getQtdCombustivel() {
        return quantidadeCombustivel;
    }

    public void setQtdCombustivel(float quantidadeCombustivel) {
        this.quantidadeCombustivel = quantidadeCombustivel;
    }

    public void adicionarCombustivel(float qtdCombustivel) {
        setQtdCombustivel(getQtdCombustivel() + qtdCombustivel);
    }

    public Float obterCombustivel() {
        return getQtdCombustivel();
    }

    public void andar(float distanciaKm) {
        setQtdCombustivel((getQtdCombustivel() - (distanciaKm * 0.20f)));
    }
}
