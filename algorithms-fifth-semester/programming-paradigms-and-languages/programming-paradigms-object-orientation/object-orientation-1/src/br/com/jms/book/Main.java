package br.com.jms.book;

class Main {
    public static void main(String[] args) {

        Livro livro1 = new Livro("Harry Potter e a Pedra Filosofal", "J. K. Rowling", 264);

        Livro livro2 = new Livro("Poeira em alto mar", "Alan Bida", 133);

        System.out.println("\n* * * * Lista de livros * * * *");

        System.out.println("\nLivro 1: \n" + livro1.titulo + livro1.autor + livro1.numeroPaginas);

        System.out.println("\nLivro 2: \n" + livro2.titulo + livro2.autor + livro2.numeroPaginas);
    }
}
