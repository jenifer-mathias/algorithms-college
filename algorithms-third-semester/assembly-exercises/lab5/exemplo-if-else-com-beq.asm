# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# Exemplo de execução - exemplo da aula IF/ELSE com beq

# if ( x != y ) go to L2;
# a = b + c;
# L2 : a = b - c;

# considere: a = $s0, b = $s1, c = $s2, x = $s3, y = $s4 

.data

	a: .word 0
	b: .word 4
	c: .word 1
	x: .word 1
	y: .word 1

.text 
	la $s0, a
	la $s1, b
	la $s2, c
	la $s3, x
	la $s4, y
	

	beq $s3, $s4, L1        # compara se o valor que está em s3 é igual ao valor contido em s4
	add $s0, $s1, $s2       # se for, ele soma os valores contidos em s1 e s2 e salva em s0
	j done                  # jump de finalização
	L1: sub $s0, $s0, $s3   # se não, então cai em L1 e subtrai o valor contido em s0 com s3
	done:

# neste exemplo, como os valores são iguais, ele executa a soma 

