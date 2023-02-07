# pior caso O(n)

def linearSearch(list, item):
    index = 0
    found = False

    while index < len(list) and found is False:
        if list[index] == item:
            found = True
        else:
            index += 1
    return index


list = [25, 21, 22, 24, 23, 27, 26]
print(linearSearch(list, 22))
