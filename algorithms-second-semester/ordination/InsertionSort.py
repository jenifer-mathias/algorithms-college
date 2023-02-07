def insertionSort(lista):
    for indice in range(1, len(lista)):
        j = indice - 1
        proximo_elemento = lista[indice]
        while (lista[j] > proximo_elemento) and (j >= 0):
            lista[j + 1] = lista[j]
            j = j - 1
            lista[j + 1] = proximo_elemento


lista = [25, 21, 22, 24, 23, 27, 26]
print(lista)
insertionSort(lista)
print(lista)