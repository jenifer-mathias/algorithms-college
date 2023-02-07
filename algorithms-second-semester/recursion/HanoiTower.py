def hanoi(n, a, b, c):
    if n == 1:
        print("move o disco %d de %s para %s" % (n, a, c))
    else:
        hanoi(n - 1, a, c, b)
        print("move o disco %d de %s para %s" % (n, a, c))
        hanoi(n - 1, b, a, c)


hanoi(3, 1, 2, 3)
