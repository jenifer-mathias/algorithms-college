package br.com.jms.funcionario;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        System.out.println("\n* * * * Calcula salário dos funcionários * * * *\n");

        Gerente gerente = new Gerente("Maria", "123456", 4500.00f);
        Assistente assistente = new Assistente("João", "789101", 1200.00f);
        Vendedor vendedor = new Vendedor("Marcelo", "121314", 3000.00f);

        ArrayList<Funcionario> listaFuncionario = new ArrayList<>();

        listaFuncionario.add(gerente);
        listaFuncionario.add(assistente);
        listaFuncionario.add(vendedor);

        for (Funcionario funcionario : listaFuncionario) {
            System.out.println(funcionario.calcularSalario());
        }
    }
}
