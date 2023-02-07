package br.com.jms.contas;

public class ContaPoupanca extends Conta {

    public ContaPoupanca(String numeroConta, String nomeCorrentista, Float saldo) {
        super(numeroConta, nomeCorrentista, saldo);
    }

    public void deposito(float valor) {
        saldo += valor;
    }

    @Override
    public void saque(float valor) {
        if (saldo == 0.00f) {
            System.out.println("Saldo insuficiente!");
        } else
            saldo -= valor;
    }

    @Override
    public void imprimeSaldo() {
        System.out.println("Saldo atual: " + saldo);
    }

    public void imprimeDadosDaConta() {
        System.out.println("Nome do correntista: " + nomeCorrentista +
                "\nNúmero da conta: " + numeroConta);
    }
}
