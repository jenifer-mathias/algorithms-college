package br.com.jms.funcionario;

public class Gerente extends Funcionario {

   public Gerente(String nome, String matricula, Float salarioBase) {
       super(nome, matricula, salarioBase);
   }

    @Override public float calcularSalario() {
       return salarioBase * 2;
    }

}
