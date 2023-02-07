package br.com.jms.contas;

public class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Operações em contas bancárias * * * *\n");

        ContaCorrente contaCorrente = new ContaCorrente("12345", "Maria", 2000.00f);
        ContaEspecial contaEspecial = new ContaEspecial("34567", "João", 1000.00f, 3000.00f);
        ContaPoupanca contaPoupanca = new ContaPoupanca("78910", "Laura", 5000.00f);

        contaCorrente.deposito(1000.00f);
        contaCorrente.saque(200.00f);

        contaCorrente.imprimeDadosDaConta();
        contaCorrente.imprimeSaldo();

        System.out.println("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");

        contaEspecial.deposito(200.00f);
        contaEspecial.saque(40000.00f);

        contaEspecial.imprimeDadosDaConta();
        contaEspecial.imprimeSaldo();

        System.out.println("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");

        contaPoupanca.deposito(6000.00f);
        contaPoupanca.saque(2000.00f);

        contaPoupanca.imprimeDadosDaConta();
        contaPoupanca.imprimeSaldo();
    }
}
