def calculaAproximacao(arr):
    for i in range(len(arr)):
        print("x%s: %.5f\t" % (i + 1, arr[i]), end=' ')
    print("\n")


def calculaMetodoDeJacobi(matrizAumento, resultadoAumento, tamanho, aproximacao=None, numeroMaximoIteracoes=100,
                          tolerancia=1e-3):
    if aproximacao is None:
        aproximacao = [0 for _ in range(tamanho)]

    segundaAproximacao = [0 for _ in range(tamanho)]

    for i in range(tamanho):
        p = matrizAumento[i][i]
        for j in range(tamanho):
            if p != 0:
                matrizAumento[i][j] = -(matrizAumento[i][j] / float(p))
            if i == j:
                matrizAumento[i][j] = 0
        resultadoAumento[i] = resultadoAumento[i] / float(p)

    sucesso = False
    for x in range(numeroMaximoIteracoes):
        print("E(%d)" % (x + 1))
        if x % 2 == 0:
            for i in range(tamanho):
                soma = 0
                for j in range(tamanho):
                    soma += matrizAumento[i][j] * segundaAproximacao[j]
                segundaAproximacao[i] = soma + resultadoAumento[i]
            calculaAproximacao(segundaAproximacao)

            if (max(aproximacao) != 0) and \
                    (abs(max(segundaAproximacao) - max(aproximacao)) / abs(max(aproximacao))) < tolerancia:
                print("O processo foi concluído com sucesso! ")
                sucesso = True
                break

            else:
                for i in range(tamanho):
                    soma = 0
                    for j in range(tamanho):
                        soma += matrizAumento[i][j] * segundaAproximacao[j]
                    aproximacao[i] = soma + resultadoAumento[i]
                calculaAproximacao(aproximacao)

            if (max(aproximacao) != 0) and \
                    abs(max(aproximacao) - max(segundaAproximacao)) / abs(max(segundaAproximacao)) < tolerancia:
                print("O processo foi bem-sucedido")
                sucesso = True
                break

    if not sucesso:
        print("O processo excedeu o número máximo de iterações possíveis!")


def main():
    matriz = [[10, -1, 2, 0],
              [-1, 11, -1, 3],
              [2, -1, 10, -1],
              [0, 3, -1, 8]]

    resultadoArray = [5, 20, -10, 13]
    tamanho = len(resultadoArray)
    aproximacaoInicial = [0 for _ in range(tamanho)]

    calculaMetodoDeJacobi(matriz, resultadoArray, tamanho, aproximacaoInicial, tolerancia=0.0001)


if __name__ == '__main__':
    main()
