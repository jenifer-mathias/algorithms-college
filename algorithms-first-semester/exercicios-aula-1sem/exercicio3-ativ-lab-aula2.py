salario = float(input("Digite o seu salário: "))

qtdAguaConsumida = float(input("Digite a quatidade de água consumida neste mês: "))

percentual = 0.02 * (qtdAguaConsumida / 1000)

contaAgua = percentual * salario

contaComDesconto = contaAgua * 0.85

print("O valor da conta de água é de: R$" , contaAgua)

print("O valor a ser pago com desconto de 15% é de: R$" , contaComDesconto)



    
    
    




