package br.com.jms.funcionario;

public abstract class Funcionario {
    String nome;
    String matricula;
    Float salarioBase;

    public Funcionario(String nome, String matricula, Float salarioBase) {
        this.nome = nome;
        this.matricula = matricula;
        this.salarioBase = salarioBase;
    }

    public abstract float calcularSalario();
}
