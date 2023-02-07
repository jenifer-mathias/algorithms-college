package br.com.jms.carropneu;

class Main {
    public static void main(String[] args) {

        System.out.println("\n* * * * Verifica pneus do carro * * * *\n");

        Pneu p1 = new Pneu(32);
        Pneu p2 = new Pneu(32);
        Pneu p3 = new Pneu(36);
        Pneu p4 = new Pneu(36);

        Carro carro = new Carro(p1, p2, p3, p4);

        carro.ligar();
        carro.pneu3.furar();     // pneu furado
        carro.verificarPneu();   //exibir a pressão em cada pneu
        carro.desligar();
        carro.verificarPneu();   //exibir carro está desligado.
    }
}