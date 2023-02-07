from typing import List


def binarySearch(list, item):
    first = 0
    last = len(list) - 1
    found = False

    while first <= last and not found:
        middle = (primeiro + ultimo) // 2
        if List[middle] == item:
            found = True
        else:
            if item < list[middle]:
                ultimo = middle - 1
            else:
                primeiro = middle + 1

    return middle


list = [21, 22, 23, 24, 25, 36, 42, 42, 42, 42, 42, 42, 51, 55, 70]
print(binarySearch(list, 42))
