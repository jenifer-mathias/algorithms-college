package br.com.jms.funcionario;

public class Assistente extends Funcionario {

    public Assistente(String nome, String matricula, Float salarioBase) {
        super(nome, matricula, salarioBase);
    }

    @Override
    public float calcularSalario() {
        return salarioBase;
    }
}
