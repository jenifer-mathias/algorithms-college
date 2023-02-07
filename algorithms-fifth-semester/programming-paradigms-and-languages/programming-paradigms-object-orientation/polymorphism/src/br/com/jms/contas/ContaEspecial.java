package br.com.jms.contas;

public class ContaEspecial extends Conta {
    Float limite;

    public ContaEspecial(String numeroConta, String nomeCorrentista, Float saldo, Float limite) {
        super(numeroConta, nomeCorrentista, saldo);
        this.limite = limite;
    }

    @Override
    public void deposito(float valor) {
        saldo += valor;
    }

    /**
     * permite que o saldo fique negativo até o limite estabelecido.
     */
    @Override
    public void saque(float valor) {
        if (limite > saldo) {
            saldo -= valor;
        }
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
