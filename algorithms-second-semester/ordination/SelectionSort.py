def selectionSort(lista):
    for preencher_posicao in range(len(lista) - 1, 0, -1):
        indice_maximo = 0
        print("preencher_posicao: ", preencher_posicao)
        for localizacao in range(1, preencher_posicao + 1):
            print("\nlista: ", lista)
            print("localizacao: ", localizacao)
            print("\t\t[", lista[localizacao], "] > [", lista[indice_maximo], "]")
            if lista[localizacao] > lista[indice_maximo]:
                indice_maximo = localizacao
        lista[preencher_posicao], lista[indice_maximo] = lista[indice_maximo], lista[preencher_posicao]


lista = [25, 21, 22, 24, 23, 27, 26]
selectionSort(lista)
print(lista)