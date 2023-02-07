# NOme: Jenifer Mathias dos Santos
# TIA: 32092946
# Exercício ii 
# c = b - a[13]
# c = 1 - 14 = -13

.data

a: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16

b: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26

c: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31

.text
	la $s0,a
	la $s1,b             
	la $s2,c

	lw $t1, 0($s1)       # posição 0 do array b
	lw $t0, 52($s0)      # 4 * 13 = 52 = 52º posição do array a | 1 word = 4 bits

	sub $s2, $t1 $t0     # faz a subtração de b e a

	sw $s2, 0($s2)       # armazena o resultado da subtração (b - a[13]) na posição 0 do array c
