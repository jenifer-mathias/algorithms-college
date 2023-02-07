package br.com.jms.paciente;

class Main {
    public static void main(String[] args) {
        Medico medico = new Medico("Ana Beatriz", "333431", "Clínico Geral");
        Paciente paciente = new Paciente("Marcelo Silva", "033444555-22", 26);
        Exame exame = new Exame(medico, paciente, "COVID-19", "Negativo");
        exame.imprimirExame();
    }
}
