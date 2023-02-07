""" Crie um programa para ordenar palavras em uma linha do arquivo pelo seu tamanho, neste caso, uma
palavra é definida como uma sequência de letras, maiúsculas ou minúsculas, as palavras com apenas
uma letra também deverão ser consideradas. Seu programa fará a leitura de várias linhas de um arquivo
texto, e em seguida, deverá imprimir as palavras de uma linha em ordem decrescente em função do
tamanho das palavras, ou seja, do maior tamanho para o menor tamanho. Se o tamanho das palavras
for igual, deve-se colocar as palavras de tamanho igual em ordem lexicográfica, ou seja, como ordem do
dicionário (ordem alfabética crescente), além disso se as palavras tiverem letras MAIÚSCULAS estas
devem ser convertidas pera minúsculas antes de fazer a comparação lexicográfica.
Para ordenar a sequência de palavras o seu programa deve usar o algoritmo de ordenação MergeSort
modificado, conforme visto nas aulas do professor Israel, para atender os requisitos acima.
A entrada do seu programa será realizada por um arquivo texto com várias linhas, cada linha do arquivo
poderá conter várias palavras separadas por espaço em branco. Considere que em uma linha não
teremos palavras repetidas, mas podemos ter palavras com somente um caractere. """


def manipulateFile(orderedOutput):
    filePath = "/"  # replace with your path
    file = open(filePath + 'words.txt', 'r')
    print('Antes da ordenação:\n')
    for line in file:
        vector = line.lower().strip().split(' ')
        showList(vector)
        mergeSort(vector)
        orderedOutput.append(vector)
    file.close()


def mergeSort(vector):
    if len(vector) > 1:

        # Finding the mid of the array
        middle = len(vector) // 2

        # Dividing the array elements
        left = vector[:middle]

        # into 2 halves
        right = vector[middle:]

        # Sorting the first half
        mergeSort(left)

        # Sorting the second half
        mergeSort(right)

        i = j = k = 0

        # Copy data to temp arrays left[] and right[]
        while i < len(left) and j < len(right):
            if len(left[i]) > len(right[j]):
                vector[k] = left[i]
                i += 1
            elif len(left[i]) == len(right[j]) and left[i] < right[j]:
                vector[k] = left[i]
                i += 1
            else:
                vector[k] = right[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(left):
            vector[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            vector[k] = right[j]
            j += 1
            k += 1


# Code to show list
def showList(vector):
    for i in range(len(vector)):
        print(vector[i], end=" ")
    print()


def printMatriz(matriz):
    for i in range(len(matriz)):
        for valor in matriz[i]:
            print(valor, end=" ")
        print()


def main():
    orderedVector = []
    manipulateFile(orderedVector)
    print('\nDepois da ordenação:\n')
    printMatriz(orderedVector)
    return


if __name__ == "__main__":
    main()

