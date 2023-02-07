def soma(m, n):
    if n == 0:
        return m
    else:
        return 1 + soma(m, n - 1)


def prod(m, n):
    if n == 0:
        return 0
    else:
        return soma(m, prod(m, n - 1))


def exp(m, n):
    if n == 0:
        return 1
    else:
        return prod(m, exp(m, n - 1))


print(soma(2, 8))
