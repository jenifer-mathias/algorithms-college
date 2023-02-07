# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# Exemplo de execução - exemplo da aula while

# int pow = 1;
# int x = 0;
# while (pow != 128) {
# pow = pow * 2;
# x = x + 1;
# }

.data

	pow: .word 1
	x: .word 0

.text 
	la $s0, pow
	la $s1, x

	addi $s0, $0, 1           
	add $s1, $0, $0           
	addi $t0, $0, 128
	while: beq $s0, $t0, done  # para quando o valor da potência for igual a 128
	sll $s0, $s0, 1            # faz a multiplicação pow * 2
	addi $s1, $s1, 1           # x = x + 1
	j while
	done:
