package br.com.jms.employee;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("\n* * * * Calcula salário dos funcionários * * * *");

        System.out.println("\nDigite o nome do funcionário: ");
        String nome = scanner.next();

        System.out.println("\nDigite o salário atual do funcionário: ");
        double salario = scanner.nextDouble();

        Funcionario funcionario = new Funcionario(nome, salario);

        System.out.println("\nDigite o percentual de aumento: ");
        double percentual = scanner.nextDouble();

        funcionario.aumentaSalario(percentual);

        System.out.println(funcionario.getNome() + "\n");

        System.out.println("Novo salário do funcionário: \nR$ " + funcionario.getSalario());
    }
}

