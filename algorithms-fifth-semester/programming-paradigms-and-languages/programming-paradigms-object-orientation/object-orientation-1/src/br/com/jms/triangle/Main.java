package br.com.jms.triangle;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("\n* * * * Calcula perímetro do triângulo * * * *");

        System.out.println("\nDigite o valor do lado A do triângulo: ");
        double ladoA = scanner.nextDouble();

        System.out.println("\nDigite o valor do lado B do triângulo: ");
        double ladoB = scanner.nextDouble();

        System.out.println("\nDigite o valor do lado C do triângulo: ");
        double ladoC = scanner.nextDouble();

        Triangulo triangulo = new Triangulo(ladoA, ladoB, ladoC);

        System.out.println("\nCálculo do perímetro: \n" + triangulo.calculaPerimetro(triangulo));

    }
}
