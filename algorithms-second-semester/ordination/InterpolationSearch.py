def interpolationSearch(list, item):
    return interpolationSearchHelper(list, 0, len(list) - 1, item)


def interpolationSearchHelper(list, start, end, item):
    if start <= end and list[start] <= item <= list[end]:
        pos = start + ((end - start) // (list[end] - list[start]) * (item - list[start]))
        print("inicio: ", start, "termino: ", end, "lista[termino]: ", list[end], "lista[inicio]: ",
              list[start], "item: ", item, "pos: ", pos)
        if list[pos] == item:
            return pos
        if list[pos] < item:
            return interpolationSearchHelper(list, pos + 1, end, item)
        if list[pos] > item:
            return interpolationSearchHelper(list, start, pos - 1, item)
    return -1


list = [21, 22, 23, 24, 25, 36, 37]
print("\n", interpolationSearch(list, 36))
