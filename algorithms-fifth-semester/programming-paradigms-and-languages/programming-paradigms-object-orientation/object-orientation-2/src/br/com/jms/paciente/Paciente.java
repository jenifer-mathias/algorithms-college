package br.com.jms.paciente;

public class Paciente {
    String nome;
    String cpf;
    Integer idade;

    public Paciente(String nome, String cpf, Integer idade) {
        this.nome = nome;
        this.cpf = cpf;
        this.idade = idade;
    }
}
