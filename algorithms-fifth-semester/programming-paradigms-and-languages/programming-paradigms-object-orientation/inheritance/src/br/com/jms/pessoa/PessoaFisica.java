package br.com.jms.pessoa;

public class PessoaFisica extends Pessoa {
    String rg;
    String cpf;

    public PessoaFisica(Integer id, String nome, String rg, String cpf) {
        super(id, nome);
        this.rg = rg;
        this.cpf = cpf;
    }
}
