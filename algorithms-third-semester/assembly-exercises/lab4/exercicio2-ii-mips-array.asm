# NOme: Jenifer Mathias dos Santos
# TIA: 32092946
# Exercício ii 
# b = a[5] - c[15]
# b = 6 - 16 = -10

.data

a: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16

b: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26

c: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31

.text
	la $s0,a
	la $s1,b             
	la $s2,c

	lw $t0, 20($s0)      # 4 * 5 = 20 = 20º posição do array a | 1 word = 4 bits
	lw $t1, 60($s2)      # 4 * 15 = 60 - posição 60 do array c

	sub $s1, $t0 $t1     # faz a subtração de a e c

	sw $s1, 0($s1)       # armazena o resultado da subtração (a[5] - c[15]) na posição 0 do array b
