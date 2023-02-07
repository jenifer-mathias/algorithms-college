package br.com.jms.pessoa;

public class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Pessoa física e jurídica * * * *");

        Pessoa pessoa = new Pessoa(1, "Ana");

        PessoaJuridica pessoaJuridica = new PessoaJuridica(2, "ABC", "45.678.910/0001-10");

        PessoaFisica pessoaFisica = new PessoaFisica(3, "José", "12.345.678-X", "987.654.321.00");

        System.out.printf("\nId: %d\n", pessoa.id);
        System.out.println("Nome: " + pessoa.nome);

        System.out.printf("\nId: %d\n", pessoaJuridica.id);
        System.out.println("Nome: " + pessoaJuridica.nome);
        System.out.println("CNPJ: " + pessoaJuridica.cnpj);

        System.out.printf("\nId: %d\n", pessoaFisica.id);
        System.out.println("Nome: " + pessoaFisica.nome);
        System.out.println("RG: " + pessoaFisica.rg);
        System.out.println("CPF: " + pessoaFisica.cpf);
    }
}
