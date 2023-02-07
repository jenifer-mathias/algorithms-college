# Um pescador comprou um computador para controlar o rendimento diário de seu trabalho.
# Toda vez que ele traz um peso de peixes maior que o estabelecido pelo regulamento de pesca
# do Estado de São Paulo (50 quilos), deve pagar uma multa de R$ 4,00 por quilo excedente.
# Escreva um programa que leia o peso de peixes, e verifique se há excesso.
# Se houver, determine o peso excedente e o valor da multa.
# Caso contrário, mostrar “Dentro do regulamento”.
#
# Exercício 11 - pdf aula 5

print("\n *** Bem-vindo(a) ao cálculo do peso de peixes! *** ")

pesoPeixes = float(input("\n Digite a quantidade de peixes que você pescou em kg: "))

if pesoPeixes > 50.00:
    pesoExcedente = pesoPeixes - 50
    multa = pesoExcedente * 4.00
    print("\n O peso de peixes excedeu", pesoExcedente,
          "kg do regulamento de pesca do Estado de São Paulo e você receberá uma multa de: R$", multa)
elif pesoPeixes < 1:
    print("Opa, peso inválido! ")
else:
    print("\n", pesoPeixes, "kg está dentro do regulamento! ")
