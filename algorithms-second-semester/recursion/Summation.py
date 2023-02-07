def somatorio(n):
    if n == 0:
        return 0
    else:
        return n + somatorio(n - 1)


print("1 ", somatorio(1))
print("2 ", somatorio(2))
print("3 ", somatorio(3))
print("4 ", somatorio(4))
print("5 ", somatorio(5))
