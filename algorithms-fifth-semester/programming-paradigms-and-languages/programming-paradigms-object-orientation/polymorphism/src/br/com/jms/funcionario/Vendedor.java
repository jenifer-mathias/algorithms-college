package br.com.jms.funcionario;

public class Vendedor extends Funcionario {

    public Vendedor(String nome, String matricula, Float salarioBase) {
        super(nome, matricula, salarioBase);
    }

    @Override
    public float calcularSalario() {
        return salarioBase * 0.10f;
    }
}
