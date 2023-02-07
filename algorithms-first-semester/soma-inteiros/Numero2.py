# Faça um programa que calcule e apresente a soma dos inteiros existentes
#  entre dois valores lidos. Considere que o segundo número lido deve ser maior
#  que o primeiro número lido.
#
#  Exercício Semanal

print("\n *** CÁLCULO - SOMA DE INTEIROS *** \n")

numero1 = int(input(" Insira o primeiro número inteiro para a realização do cálculo: "))
numero2 = int(input(" Insira o segundo número inteiro: "))
total = 0

while numero2 <= numero1:
  numero2 = int(input("OPS, NÚMERO INVÁLIDO! \n"
                      "Por favor, digite novamente o segundo número inteiro para que seja maior que o primeiro: "))
  total = numero1 + numero2

for i in range(numero1, numero2):
  total = numero1 + numero2

if numero2 > numero1:
  print("A soma de", numero1, "+", numero2, "=", total)




