package br.com.jms.imovel;

public class Main {
    public static void main(String[] args) {
        System.out.println("\n* * * * * *Calcula preço dos imóveis * * * * * *");

        Imovel imovel = new Imovel("Rua Silva, n° 123", 300000.0);
        ImovelNovo imovelNovo = new ImovelNovo("Rua Joaquim, n° 999", 250000.0, 20000.0);
        ImovelVelho imovelVelho = new ImovelVelho("Av. Brasil, n° 777", 500000.0, 35000.0);

        System.out.println("\nEndereço do imóvel: " + imovel.endereco); // Rua Silva, n° 123
        System.out.println("Preço: " + imovel.preco); // 300000.0

        System.out.println("\nEndereço do imóvel novo: " + imovelNovo.endereco); // Rua Joaquim, n° 999
        System.out.println("Preço: " + imovelNovo.preco); // 250000.0
        System.out.println("Preço atual: " + imovelNovo.calcularPreco()); // 270000.0

        System.out.println("\nEndereço do imóvel antigo: " + imovelVelho.endereco); // Av. Brasil, n° 777
        System.out.println("Preço: " + imovelVelho.preco); // 500000.0
        System.out.println("Preço atual: " + imovelVelho.calcularPreco()); // 465000.0
    }
}
