package br.com.jms.imovel;

public class ImovelNovo extends Imovel {
    Double adicional;

    public ImovelNovo(String endereco, Double preco, Double adicional) {
        super(endereco, preco);
        this.adicional = adicional;
    }

    public Double calcularPreco() {
        return preco + adicional;
    }
}

