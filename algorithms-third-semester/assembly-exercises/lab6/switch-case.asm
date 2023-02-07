# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# Utilizando a estrutura aprendida para a criação do switch, implemente a seguinte instrução em
# assembly do MIPS, com as condicionais aprendidas no laboratório anterior com a seguinte
# definição:

# switch(x) {
# case 1: IF # rodar uma rotina que implemente um IF
# break;
# case 2: IF/Then/Else # Implemente uma versão do IF/Else
# break;
# case 3: while #implementar uma versão do while
# break;
# case 4: do/while #implementar uma versão do do/while
# break;
# case 5: for #implementar uma versão do for
# break;
# }

.data
	jTable: .word L0,L1,L2,L3
	a: .word 0
	b: .word 4
	c: .word 1
	x: .word 1
	y: .word 1
	pow: .word 1
	z: .word 0
	i: .word 1
	sum: .word 0
	

.text
	la $s0, a
	la $s1, b
	la $s2, c
	la $s3, x
	la $s4, y
	la $s5, pow
	la $s6, z
	la $s7, i
	la $t7, sum

li $s1, 15
# g = $s1 = 15
li $s2, 20 # h = $s2 = 20
li $s3, 10 # i = $s3 = 10
li $s4, 5 # j = $s4 = 5
li $s5, -1 # k = $s5 = 2
li $t6, 0 # t6 = i = 0
la $t4, jTable
# $t4 = base address of the jump table

# Verificando os limites de K
slt $t3, $s5, $zero
bne $t3, $zero, EXIT
slti $t3, $s5, 4
beq $t3, $zero, EXIT

# Calculando o endereço correto do Label
sll $t1, $s5, 2
add $t1, $t1, $t4
lw $t0, 0($t1)

# Seleção do Label
jr $t0

# Casos

# IF
L0:
	bne $s3, $s4, L0       # compara se o valor que está em s3 não é igual ao valor contido em s4
	add $s0, $s1, $s2      # se for diferente, ele soma os valores contidos em s1 e s2 e salva em s0
	j EXIT                 # jump de finalização
	
# IF/ ELSE
L1:
	bne $s3, $s4, L1       # compara se o valor que está em s3 não é igual ao valor contido em s4
	add $s0, $s1, $s2      # se for diferente, ele soma os valores contidos em s1 e s2 e salva em s0
	j EXIT                 # jump de finalização
	j L2
	
# WHILE
L2:
addi $s5, $0, 1           
	add $s6, $5, $0           
	addi $t0, $0, 128
	while: beq $s5, $t0, EXIT  # para quando o valor da potência for igual a 128
	sll $s5, $s5, 1            # faz a multiplicação pow * 2
	addi $s6, $s6, 1           # x = x + 1
	j while
	j EXIT
	
# DO WHILE
L3:
	loop:
 	addi $t6, $t6, 1          # soma 1 com o valor contido em $t6 e salva na posição 0 de $t6
 	blt $t6, 4, loop          # compara se 4 é menor que o valor contido em $t6

# FOR
L4:
	addi $t7, $0, 0
	addi $s7, $0, 1
	addi $t5, $0, 101
	loopFor: slt $t6, $s0,$t5  # compara se o valor contido em s0 é menor que o valor contido em to, caso for, ele atribui 1 a t1, se não atribui 0
	beq $t6, $0, done       # testando se t1 é 0, se for, finaliza o loop
	add $s1, $s7, $t7
	sll $t7, $t7, 1   
	j loopFor
	done:

EXIT:
#FIM
