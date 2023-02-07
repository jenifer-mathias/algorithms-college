# Nome: Jenifer Mathias dos Santos
# TIA: 32092946

# Implementar em assembly MIPS o cálculo de média de um vetor utilizando as intruções de ponto flutuante.
# Imprimir o valor resultante utilizando as syscalls.

.data
	array: .float 2.1, 2.1, 4.2, 2.2  # soma: 10.6 / 4 = 2.65
	tamanho: .word 10
	soma: .word 0
	saida: .word 0
	dois: .word 2
	inicial: .word 1
	endereco: .word 4
	contador: .word 0

.text 

main:

    la $a0, array  
    la $t1, contador        # i = 0 
    la $t2, dois
    l.s $f3, soma        #soma = 0
    la $t5, tamanho 
    l.s $f6, saida
    l.s $f7, inicial
    l.s $f8, endereco
    
    loop:
        l.s $f4, ($a0)   #$f4 = array[i]
        add.s $f3, $f3, $f4   #soma = soma + array[i]

        add.s $f1, $f1, $f7 # i = i + 1
        l.s $f9, ($a0)
        add.s $f9, $f9, $f8 # Atualiza o endereço do array
        blt $t1, $t5, loop   # if i < 4 então permanece no topo
        l.s  $f3, soma

        # Calcula a média
        div.s $f6, $f3, $f2   
        lwc1 $f6, saida
        
        li $v0, 2     # Isso fala q vai printar uma float
	mov.s $f12, $f6 # move os dados de $f4 para o $f12 (registrador usado para syscall)
	syscall 
        
exit:



