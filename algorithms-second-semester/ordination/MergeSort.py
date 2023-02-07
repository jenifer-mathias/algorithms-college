def mergeSort(lista):
    if len(lista) > 1:
        meio = len(lista) // 2
        esquerda = lista[:meio]
        direita = lista[meio:]

        print("lista: ", lista)
        print("esquerda: ", esquerda)
        print("direita: ", direita)
        mergeSort(esquerda)
        mergeSort(direita)

        print("\n")

        a = 0
        b = 0
        c = 0

        while a < len(esquerda) and b < len(direita):
            if esquerda[a] < direita[b]:
                lista[c] = esquerda[a]
                a += 1
            else:
                lista[c] = direita[b]
                b += 1
            c += 1

        while a < len(esquerda):
            lista[c] = esquerda[a]
            a += 1
            c += 1

        while b < len(direita):
            lista[c] = direita[b]
            b += 1
            c += 1


lista = [25, 21, 22, 24, 23, 27, 26]
mergeSort(lista)
print(lista)
