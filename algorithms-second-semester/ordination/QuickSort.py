import random

# Pior caso O(N²)
# é comum o pivot começar do início da lista

def quickSort(lista):
    quickSortHelper(lista, 0, len(lista) -1)


def quickSortHelper(lista, primeiro, ultimo):
    if primeiro < ultimo:
        pontoDivisao = particao(lista, primeiro, ultimo)
        quickSortHelper(lista, primeiro, pontoDivisao - 1)
        quickSortHelper(lista, pontoDivisao + 1, ultimo)


def particao(lista, primeiro, ultimo):
    pivot = lista[primeiro]
    marcaEsquerda = primeiro + 1
    marcaDireita = ultimo

    pronto = False
    while not pronto:
        while marcaEsquerda <= marcaDireita and lista[marcaEsquerda] <= pivot:
            marcaEsquerda += 1

        while lista[marcaDireita] >= pivot and marcaDireita >= marcaEsquerda:
            marcaDireita -= 1

        if marcaDireita < marcaEsquerda:
            pronto = True
        else:
            temp = lista[marcaEsquerda]
            lista[marcaEsquerda] = lista[marcaDireita]
            lista[marcaDireita] = temp

    # troca do pivot

    temp = lista[primeiro]
    lista[primeiro] = lista[marcaDireita]
    lista[marcaDireita] = temp

    return marcaDireita


lista = [random.randint(0, 20) for i in range(50)]
quickSort(lista)

print(lista)
