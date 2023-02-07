def mdc(m, n):
    if n == 0:
        return m
    else:
        return mdc(n, m % n)

# % ---> resto da divisão


print(mdc(8, 12))
