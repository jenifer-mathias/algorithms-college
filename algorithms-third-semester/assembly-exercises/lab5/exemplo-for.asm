# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# Exemplo de execução - exemplo da aula for usando slt

# add the powers of 2 from 1
# to 100
# int sum = 0;
# int i;
# for (i=1; i < 101; i = i*2) {
# sum = sum + i;
# }

.data

	i: .word 1
	sum: .word 0

.text 
	la $s0, i
	la $s1, sum

	addi $s1, $0, 0
	addi $s0, $0, 1
	addi $t0, $0, 101
	loop: slt $t1, $s0,$t0  # compara se o valor contido em s0 é menor que o valor contido em to, caso for, ele atribui 1 a t1, se não atribui 0
	beq $t1, $0, done       # testando se t1 é 0, se for, finaliza o loop
	add $s1, $s1, $s0
	sll $s0, $s0, 1   
	j loop
	done:
