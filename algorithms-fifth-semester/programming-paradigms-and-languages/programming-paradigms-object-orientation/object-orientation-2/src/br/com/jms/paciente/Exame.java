package br.com.jms.paciente;

public class Exame {
    Medico medico;
    Paciente paciente;
    String descricao;
    String resultado;

    public Exame(Medico medico, Paciente paciente, String descricao, String resultado) {
        this.medico = medico;
        this.paciente = paciente;
        this.descricao = descricao;
        this.resultado = resultado;
    }

    public void imprimirExame() {
        System.out.println("\n============ Relatório médico ============\n");
        System.out.println("Médico responsável: " + medico.nome);
        System.out.println("CRM: " + medico.crm);
        System.out.println("Especialização: " + medico.especializacao);

        System.out.println("\nNome do paciente: " + paciente.nome);
        System.out.println("CPF : " + paciente.cpf);
        System.out.println("Idade do paciente: " + paciente.idade);

        System.out.println("\nDescrição: " + descricao);
        System.out.println("Resultado: " + resultado);
        System.out.println("\n==========================================\n");
    }
}
