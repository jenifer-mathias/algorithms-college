""" Muita Sort

Para essa atividade você deve implementar um programa de ordenação muito simples, baseado na
ordenação pelo método bolha.
Serão informados ao programa N números inteiros positivos e um inteiro positivo M, e em seguida, o
seu programa deve ordenar estes N números em ordem crescente do valor do seu módulo utilizando
o inteiro M. Se houver um empate entre um número ímpar e um número par (para os quais o seu
módulo M dá o mesmo valor) então o número ímpar irá preceder o número par. Se houver um
empate entre dois números ímpares (para os quais o seu módulo M dá o mesmo valor), então o maior
número ímpar irá preceder o menor número ímpar. Se houve um empate entre dois números pares
(para os quais o seu módulo M dá o mesmo valor), então o menor número par irá preceder o maior
número par.
Ao final o seu programa apresenta os N números ordenados de acordo com as regras acima
mencionadas.

Exemplo de Entrada
N=15 M=3
N números inteiros

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Exemplo de Saída
15 9 3 6 12 13 7 1 4 10 11 5 2 8 14
"""


def outputVector(list):
    for position1 in list:
        print(f'{position1} ', end="")
    print('\n')
    return


def bubbleSort(list, n, m):
    for i in range(n):
        for j in range(n - i - 1):
            if list[j] % m > list[j + 1] % m:
                swapPositions(list, j, j + 1)
            if list[j] % m == list[j + 1] % m:
                if (list[j] % 2 == 0) and (list[j + 1] % 2 == 1):
                    swapPositions(list, j, j + 1)
                elif (list[j] % 2 == 1) and (list[j + 1] % 2 == 1) and (list[j + 1] > list[j]):
                    swapPositions(list, j, j + 1)
    return list


def swapPositions(list, position1, position2):
    list[position1], list[position2] = list[position2], list[position1]
    return list


def main():
    print("\n*** Algoritmo Muita Sort *** \n")
    print("Informações para realizar a ordenação:\n"
          "N - representa qualquer número inteiro positivo\n"
          "M - módulo utilizando o inteiro N escolhido\n")
    n = int(input('N: '))
    m = int(input('M: '))
    print('Digite uma lista de números para serem ordernados: \n'
          'OBS: Digite cada número da lista separado com espaços, '
          'sem utlizar pontuações para separá-lo! \nEx: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15')
    list = []

    for i in range(n):
        aux = input()
        if ' ' in aux:
            numbers = aux.strip().replace(',', ' ').split()
            if len(numbers) != n:
                print('Erro: quantidade de números maior do que o previsto')
                exit()
            for number in numbers:
                list.append(int(number))
            break
        else:
            list.append(int(aux))
    bubbleSort(list, n, m)
    outputVector(list)

    return


if __name__ == "__main__":
    main()
