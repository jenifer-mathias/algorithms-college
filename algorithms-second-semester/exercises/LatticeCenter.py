""" Entrega de trabalho - T4

Alguns algoritmos para reconhecimento ótico de caracteres compara a imagem “scanneada” com modelos
de caracteres perfeitos. Parte da dificuldade com tais comparações é decidir onde começar a comparação.
Isto se deve ao fato de que as imagens “scanneadas” estão sujeitas a distorções, resultando em mudanças
no tamanho, posição e orientação. Um procedimento que algumas vezes é utilizada para lidar com essas
mudanças na posição é “casar” o centro de gravidade do caractere “scanneado” com centro de gravidade
do modelo com o qual ele é comparado. Neste problema você determinará os centros de gravidades das
imagens dos caracteres “scanneados”.
Para os nossos propósitos, um caractere “scanneada” será uma matriz retangular de números reais com
valores em uma escala de cinza. A escala de cinza tem valores entre 0 (representando uma região
totalmente branca) e 1 (representando uma região totalmente preta).
O centro de gravidade é um elemento particular de uma matriz. Suponha um centro de gravidade na iésima linha e
j-ésima coluna. Então a diferença entre a soma dos elementos das duas porções da matriz
acima e abaixo da i-ésima linha é mínima. Do mesmo modo, a diferença entre a soma dos elementos das
duas porções a esquerda e direita da j-ésima coluna é mínima.
Como exemplo, considere que a matriz abaixo representa o caractere “o” “scanneado”. O centro de
gravidade desta matriz está singularmente na 3º linha, e 3º coluna, pois a diferença entre a soma dos
elementos em cada porção da matriz informada, ignorando a terceira linha é 0,1 (as somas das porções
abaixo e acima são 5,55 e 5,65, respectivamente). A diferença entre a soma de cada porção da matriz
formada ignorando a terceira coluna é 0,0 (a soma de ambas porções é 5,60). """


def massDifference(inputArray, indexVerified, type):
    difference = 0
    if type == 'line':
        for i in range(0, len(inputArray)):
            for j in range(0, len(inputArray[i])):
                if i == indexVerified:
                    continue
                elif i < indexVerified:
                    difference += 100 * inputArray[i][j]
                else:
                    difference -= 100 * inputArray[i][
                        j]
    if type == 'column':
        for i in range(0, len(inputArray[0])):
            for j in range(0, len(inputArray)):
                if i == indexVerified:
                    continue  #
                elif i < indexVerified:
                    difference += 100 * inputArray[j][i]
                else:
                    difference -= 100 * inputArray[j][i]
    if difference < 0: difference = -1 * difference
    return difference


def gravityCenter(inputArray):
    lineCM = 0
    columnCM = 0
    for i in range(0, len(inputArray)):
        aux = massDifference(inputArray, i, 'line')
        if i == 0:
            lowerValue = aux
        else:
            if aux < lowerValue:
                lowerValue = aux
                lineCM = i + 1
    for j in range(0, len(inputArray[i])):
        aux = massDifference(inputArray, j, 'column')
        if j == 0:
            lowerValue = aux
        else:
            if aux < lowerValue:
                lowerValue = aux
                columnCM = j + 1
    return lineCM, columnCM


def createArray(line, column):
    return [[0 for i in range(column)] for j in range(line)]


def manipulateFile(fileName, matriz):
    countLine = 0
    array = list
    file = open(fileName)
    for line in file:
        vectorizedLine = line.strip().split(" ")
        if len(line.strip()) == 0: continue
        if len(vectorizedLine) == 2:
            lineM = int(vectorizedLine[0])
            columnM = int(vectorizedLine[1])
            array = createArray(line, columnM)
            aux = countLine + lineM
        else:
            for i in range(0, len(array)):
                vectorizedLine = line.strip().split(" ")
                for j in range(0, len(array[0])):
                    array[i][j] = float(vectorizedLine[j])
        if countLine == aux: array.append(matriz)
        countLine += 1
    return


def main():
    array = []

    pathFile = " "  # replace with your path
    fileName = open(pathFile + 'lattice.txt', 'r')
    manipulateFile(fileName, array)
    for element in array:
        count = 1
        cm = gravityCenter(element)
        print(f'Caso {count}: Centro {cm}')
        count += 1
    return


if __name__ == "__main__":
    main()
