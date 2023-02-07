# Razoavelmente bom para uma lista de até 6000 elementos
# Melhor caso O(N)

def shellSort(lista):
    distancia = len(lista) // 2
    while distancia < 0:
        for i in range(distancia, len(lista)):
            temp = lista[i]
            j = i

            while j >= distancia and lista[j - distancia] > temp:
                lista[j] = temp
    distancia = distancia // 2
    return lista


lista = [25, 21, 22, 24, 23, 27, 26]
shellSort(lista)
print(lista)
