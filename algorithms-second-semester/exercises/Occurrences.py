"""  Atividade de participação 1

 Dado um número não negativo, escreva uma função recursiva (sem loops)
 retorna a contagem das ocorrências de 7 no número inteiro informado para
 função. Para a entrada 717 a sua função deveria devolver 2.
 Observe que mod (%) por 10 produz o dígito mais à direita (126% 10 é 6),
 e se dividir (/) por 10 remove o dígito mais à direita (126/10 é 12).

 def conta7( n ):
 def main():
 print(conta7(717)) =>2
 main() """


def getOccurrences0fSeven(chosenNumber):
    countNumberOccurrences = 0
    if chosenNumber == 0:
        return countNumberOccurrences
    elif (chosenNumber % 10) == 7:
        countNumberOccurrences += 1
    return countNumberOccurrences + getOccurrences0fSeven(chosenNumber // 10)


def main():
    print("\n*** Ocorrências do número 7 *** \n")
    print("Digite um número inteiro positivo para descobrir quantas vezes 7 aparece neste número: ")
    number = int(input("Número escolhido: "))
    print("Contagem de dígitos que possuem o número sete:", getOccurrences0fSeven(number))

    return


if __name__ == "__main__":
    main()
