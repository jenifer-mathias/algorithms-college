"""
1º Problema - Multiplicação Russa
A multiplicação Russa consiste em usar duas colunas de números que desejamos multiplicar, a
primeira coluna representa o número A e a segunda coluna o número B:
a. Escrever os números A e B, que se deseja multiplicar na parte superior das colunas.
b. Dividir A por 2, sucessivamente, ignorando o resto até chegar à 1, escrever os resultados da
coluna A.
c. Multiplicar B por 2 tantas vezes quantas se tenha dividido A por 2, escrever os resultados
sucessivos na coluna B.
d. Somar todos os números da coluna B que estejam ao lado de um número ímpar da coluna A.
Exemplo: 27 × 82 = 2214, calculando através da Multiplicação Russa temos:
A B Parcelas
27 82 82
13 164 164
6 328 -
3 656 656
1 1312 1312
 Soma: 2214
Escreva uma função que recebe dois números inteiros por parâmetro (A,B) em seguida sua função
calcula a Multiplicação Russa conforme o algoritmo acima, para testar sua função escreva um
programa que lê dois valores inteiros e faz a chamada da função recursiva que implem. """


def multiply(a, b, result):
    if a != 0:
        print(a, end='\t')
        print(b)
    if (a == 0 or b == 0) and result == 0:
        return 0
    elif a == 1 and result == 0:
        return b
    elif a >= 1:
        if a % 2 == 0:
            return multiply(int(a / 2), b * 2, result)
        else:
            result += b
            return multiply(int(a / 2), b * 2, result)
    return result


def main():
    print("\n*** Multiplicação Russa *** \n")
    a = int(input('Digite o primeiro número: '))
    b = int(input('Digite o segundo número: '))

    print(f'Resultado: {multiply(a, b, 0)}')
    return


if __name__ == "__main__":
    main()
