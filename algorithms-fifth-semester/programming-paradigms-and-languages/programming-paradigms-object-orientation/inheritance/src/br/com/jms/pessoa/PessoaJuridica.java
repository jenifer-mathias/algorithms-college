package br.com.jms.pessoa;

public class PessoaJuridica extends Pessoa {
    String cnpj;

    public PessoaJuridica(Integer id, String nome, String cnpj) {
        super(id, nome);
        this.cnpj = cnpj;
    }
}
