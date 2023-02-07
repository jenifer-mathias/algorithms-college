# Faça um programa que calcule e apresente a soma dos inteiros existentes
#  entre dois valores lidos. Considere que o segundo número lido deve ser maior
#  que o primeiro número lido.
#
#  Exercício Semanal

while True:
    print("\n *** CÁLCULO - SOMA DE INTEIROS *** \n")
    print("Instruções para o cálculo: \n"
          "- Os dois números devem ser inteiros; \n"
          "- O segundo número deve ser maior que o primeiro.\n \n"
          "Demais instruções: \n"
          "- Digite IR para começar o cálculo \n"
          "- Digite SAIR para encerrar o cálculo \n"
          "Vamos começar? \n")

    escolha = input("Digite a PALAVRA correspondente a ação que deseja seguir: ")

    if escolha == "IR" or escolha == "ir":
        numero1 = int(input(" Digite um número inteiro: "))
        numero2 = int(input(" Digite outro número inteiro: "))

        if numero1 < numero2:
            soma = numero1 + numero2
            print("\n Resposta: a soma de", numero1, "+", numero2, "é:", soma)

        while numero2 <= numero1:
            print("OPS, NÚMERO INVÁLIDO! \n Por favor, digite um número maior que o segundo número digitado")
            numero1 = int(input(" Digite um número inteiro: "))
            numero2 = int(input(" Digite outro número inteiro: "))
            soma = numero1 + numero2
            print("\n Resposta: a soma de", numero1, "+", numero2, "é:", soma)

    elif escolha == "SAIR" or escolha == "sair":
        print("\n Revisão: a soma de", numero1, "+", numero2, "é:", soma)
        print("\n Agradecemos a participação!")
        break

