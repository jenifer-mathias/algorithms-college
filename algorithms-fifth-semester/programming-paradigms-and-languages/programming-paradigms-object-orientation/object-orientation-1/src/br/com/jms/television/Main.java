package br.com.jms.television;

class Main {
    public static void main(String[] args) {

        Televisao tv = new Televisao();

        tv.alterarCanal(6);
        tv.aumentarVolume();
        tv.aumentarVolume();
        tv.aumentarVolume();
        tv.diminuirVolume();

        System.out.println("\n* * * * Controla TV * * * *");

        System.out.printf("\nA TV está no canal %d\n", tv.canal); // A tv está no canal 6

        System.out.printf("\nA TV está no volume %d\n", tv.volume); // A tv está no volume 2
    }
}

