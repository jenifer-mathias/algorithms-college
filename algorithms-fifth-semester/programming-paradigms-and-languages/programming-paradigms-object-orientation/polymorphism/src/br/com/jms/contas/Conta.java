package br.com.jms.contas;

public abstract class Conta {

    String numeroConta;
    String nomeCorrentista;
    Float saldo;

    public Conta(String numeroConta, String nomeCorrentista, Float saldo) {
        this.numeroConta = numeroConta;
        this.nomeCorrentista = nomeCorrentista;
        this.saldo = saldo;
    }

    public abstract void deposito(float valor);

    public abstract void saque(float valor);

    public abstract void imprimeSaldo();

    public abstract void imprimeDadosDaConta();
}
