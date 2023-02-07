package br.com.jms.book;

class Livro {
    String titulo;
    String autor;
    Integer numeroPaginas;

    public Livro(String titulo, String autor, int numeroPaginas) {
        this.titulo = titulo;
        this.autor = autor;
        this.numeroPaginas = numeroPaginas;
    }
}