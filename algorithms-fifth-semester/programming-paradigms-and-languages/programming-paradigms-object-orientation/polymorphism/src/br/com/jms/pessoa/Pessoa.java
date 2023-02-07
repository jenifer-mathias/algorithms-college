package br.com.jms.pessoa;

public class Pessoa {
    String nome;

    public Pessoa(String nome) {
        this.nome = nome;
    }

    public void escreverNome() {
        System.out.println(nome);
    }

    public void escreverNome(String titulo) {
        System.out.println(titulo + " " + nome);
    }

    public void escreverNome(Integer vezes) {
        int i = 0;
        while (i < vezes) {
            System.out.print(nome + " ");
            i++;
        }
        System.out.println();
    }
}
