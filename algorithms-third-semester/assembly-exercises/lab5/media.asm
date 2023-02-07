# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# Apresente, em assembly do MIPS, uma solução para calcular a média de um vetor de 10 posições. 
# Utilize as instruções BNE, SLT e suas variações. 
# O valor de saída deve ser armazenado em uma variável denominada saida, correspondendo ao primeiro endereço de memória. 

.data
	array: .word 2, 2, 3, 4, 3, 6, 2, 4, 2, 4
	tamanho: .word 10
	soma: .word 0
	saida: .word 0
	dois: .word 2

.text 

main:

    la $t0, array  
    li $t1, 0       # i = 0 
    la $t2, dois
    li $t3, 0       #soma = 0
    lw $t5, tamanho  #$t2 = tamanho
    lw $t6, saida
    
    loop:
        lw $t4, ($t0)   #$t4 = array[i]
        add $t3, $t3, $t4   #soma = soma + array[i]

        add $t1, $t1, 1 # i = i + 1
        add $t0, $t0, 4 # Atualiza o endereço do array
        blt $t1, $t5, loop   # if i < 10 então permanece no topo
        sw $t3, soma

        # Calcula a média
        div $t6, $t3, $t2   
        sw $t6, saida
        
exit:


