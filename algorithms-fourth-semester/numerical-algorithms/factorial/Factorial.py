def mostraResultado(valor, iteracao):
    vetor = []
    constCasasDecimais = 4
    const = 1 + valor
    fim = 1
    mudaValor = 2
    vetor.append(float(const))

    while fim <= iteracao:
        potencia = valor ** mudaValor
        expressao = float(potencia / (calculaFat(mudaValor)))
        vetor.append(expressao)

        fim += 1
        mudaValor += 1

    resultado = 0
    for numero in vetor:
        resultado += numero

    print(round(resultado, constCasasDecimais))  # garante a tolerância de 4 casas decimais (0.0001)


def calculaFat(valorX):
    fat = 1
    i = 2
    while i <= valorX:
        fat = fat * i
        i = i + 1
    return fat


def main():
    mostraResultado(4, 5)
    mostraResultado(4, 10)


if __name__ == '__main__':
    main()
