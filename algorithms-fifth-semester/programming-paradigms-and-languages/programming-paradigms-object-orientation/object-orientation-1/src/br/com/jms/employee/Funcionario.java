package br.com.jms.employee;

public class Funcionario {
    String nome;
    Double salario;

    public Funcionario(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public Double calculaPorcentagem(double percentual) {
        return percentual / 100;
    }

    public void aumentaSalario(Double percentual) {
        double addPercentualSalario = getSalario() * calculaPorcentagem(percentual);
        setSalario(getSalario() + addPercentualSalario);
    }
}
