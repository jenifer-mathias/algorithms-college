# em Python existe o conceito de variável auxiliar

lista = [25, 21, 22, 24, 23, 27, 26]

print(lista)

indexUltimoElemento = len(lista) - 1


def bubbleSort():
    for i in range(indexUltimoElemento, 0, -1):
        for indice in range(i):
            if lista[indice] > lista[indice + 1]:
                aux = lista[indice]
                lista[indice] = lista[indice + 1]
                lista[indice + 1] = aux


print(lista)
