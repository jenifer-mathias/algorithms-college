"""
2º Problema - f91
McCarthy é um teórico famoso de ciência da computação. No seu trabalho, ele definiu uma função
recursiva chamada f91, que recebe como entrada um inteiro N e retorna um inteiro positivo definido
como a seguir:
Se N ≤ 100, então f91(N) = f91(f91(N + 11));
Se N ≥ 101, então f91(N) = N - 10.
Por exemplo:
Para N=500 temos: f91(500) = 490
Para N=91 temos: f91(91) = 91
Escreva uma função que computa a função f91 de McCarthy, a função recebe por parâmetro um valor
inteiro N, e tem como saída o cálculo de N conforme a definição acima, para testar sua função escreva
um programa que lê o valor de N e faz a chamada da função f91(), no final seu programa deve
imprimir o resultado calculado. """


def createF91(number):
    if number <= 100:
        return createF91(createF91(number + 11))
    else:
        return number - 10


def main():
    print("\n*** F91 *** \n")
    print("Digite um número inteiro para ser calculado segundo a função de McCarthy: ")
    number = int(input("N: "))
    print(createF91(number))

    return


if __name__ == "__main__":
    main()
