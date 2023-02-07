# NOme: Jenifer Mathias dos Santos
# TIA: 32092946
# Exercício i 
# a = b[12] + c
# a = 13 + 1 = 14

.data

a: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16

b: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26

c: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31

.text 
 	la $s0,a
  	la $s1,b             
    	la $s2,c

   	lw $t0, 48($s1)      # 4 * 12º posição = 48 (elemento 13) | 1 word = 4 bits
    	lw $t1, 0($s2)       # posição 0 do array c

    	add $s0, $t0 $t1     # faz a soma de b e c 

    	sw $s0, 0($s0)       # armazena o resultado da soma (b[12] + c) na posição 0 do array a



