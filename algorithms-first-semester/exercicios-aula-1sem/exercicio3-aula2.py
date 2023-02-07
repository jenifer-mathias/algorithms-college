salarioFuncionario = float(input("Digite o seu salário: "))
aumentoPercentual = int(input("Digite o percentual de aumento sobre o salário: "))
calculoAumento = (salarioFuncionario * aumentoPercentual) / 100

print("O valor do aumento é:  R$ %.2f", calculoAumento)

# opção: função format
