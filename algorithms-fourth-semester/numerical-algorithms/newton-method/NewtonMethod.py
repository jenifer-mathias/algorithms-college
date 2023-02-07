""" *********************************

 MÉTODO DE NEWTON
 Algorítmos Numéricos - 4N

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Lucas Martins de Souza
 TIA: 31943187

********************************* """

from math import e, cos, sin, log
from sympy import Symbol, diff


def definePrimeiroCriterioParada(funcao, proximaIteracao, epsilon):
    if abs(funcao(proximaIteracao)) < epsilon:
        return proximaIteracao


def defineSegundoCriterioParada(proximaIteracao, epsilon):
    if proximaIteracao > 0:
        resultado = abs(proximaIteracao - (proximaIteracao - 1) / proximaIteracao) < epsilon
        return resultado


def defineTerceiroCriterioParada(proximaIteracao, epsilon):
    if abs(proximaIteracao - (proximaIteracao - 1)) < epsilon:
        return proximaIteracao


def calculaMetodoDeNewton(funcao, pontoInicial, epsilon, criteiroParada, numeroMaximoIteracoes):
    i = 1
    while i <= numeroMaximoIteracoes:
        pontoInicialDer = Symbol('pontoInicial')
        proximaIteracao = pontoInicial - funcao(pontoInicial) / diff(pontoInicialDer)
        print("\n%d \t\t %e\t\t %e" % (i, proximaIteracao, funcao(proximaIteracao)))
        if criteiroParada == 1:
            definePrimeiroCriterioParada(funcao, proximaIteracao, epsilon)
        if criteiroParada == 2:
            defineSegundoCriterioParada(proximaIteracao, epsilon)
        if criteiroParada == 3:
            defineTerceiroCriterioParada(proximaIteracao, epsilon)
        pontoInicial = proximaIteracao
        i = i + 1
    print("\nNumero máximo de iterações atingidas!\n"
          "Quantidade de iterações permitidades: ", numeroMaximoIteracoes)


tolerancia = 1e-5


def funcaoA(x): return (e ** x) + (2 * cos(x)) - 6


def funcaoB(x): return log(x - 1) + cos(x - 1)


def funcaoC(x): return (2 * x) * cos(2 * x) - ((x - 2) ** 2)


def funcaoD(x): return x - 2 ** 2 - log(x)


def funcaoE(x): return (e ** x) - 3 * x ** 2


def funcaoF(x): return sin(x) - (e ** - x)


def main():
    print("\n************ MÉTODO DE NEWTON ************\n")
    print(" ~ ~ ~ ~ ~ ~ ~ Exercício 2a ~ ~ ~ ~ ~ ~ ~\n")

    print(" ~ ~ ~ ~ ~ 1° critério de parada ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoA, pontoInicial=1, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=2)
    print("\n ~ ~ ~ ~ ~ 2° critério de parada ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoA, pontoInicial=1, epsilon=tolerancia, criteiroParada=2, numeroMaximoIteracoes=2)
    print("\n ~ ~ ~ ~ ~ 3° critério de parada ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoA, pontoInicial=1, epsilon=tolerancia, criteiroParada=3, numeroMaximoIteracoes=2)

    print("\n ~ ~ ~ ~ ~ ~ ~ Exercício 2b ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoB, pontoInicial=1.3, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=2)

    print("\n ~ ~ ~ ~ ~ ~ ~ Exercício 2c ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoC, pontoInicial=2, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=3)
    print("\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoC, pontoInicial=3, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=4)

    print("\n ~ ~ ~ ~ ~ ~ ~ Exercício 2d ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoD, pontoInicial=1, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=2)
    print("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoD, pontoInicial=e, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=4)

    print("\n ~ ~ ~ ~ ~ ~ ~ Exercício 2e ~ ~ ~ ~ ~ ~ ~")

    calculaMetodoDeNewton(funcao=funcaoE, pontoInicial=0, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=1)
    print("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoE, pontoInicial=0, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=5)

    print("\n ~ ~ ~ ~ ~ ~ ~ Exercício 2f ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoF, pontoInicial=0, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=1)
    print("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoF, pontoInicial=3, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=4)
    print("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~")
    calculaMetodoDeNewton(funcao=funcaoF, pontoInicial=6, epsilon=tolerancia, criteiroParada=1, numeroMaximoIteracoes=7)

    print("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n")
    print("Já no exercício 2a, percebe-se que os três critérios de parada utilizados convergiram rapidamente. "
          "\nPor isso, qualquer critério de parada que for usado, para estes exercícios, convergirá do mesmo modo.")
    print("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n")


if __name__ == "__main__":
    main()
