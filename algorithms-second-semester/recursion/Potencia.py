# Implemente uma função recursiva para calcular a potência a**n,
# supondo que tanto a quanto n sejam números inteiros positivos.

# Ex: 2⁴ 2 * 2 * 2 * 2
# Condição de parada: 2⁰ = 1
# 2¹ = 2 * 2⁰

def potencia(a, n):
    if n == 0:
        return 1
    else:
        return a * potencia(a, n - 1)


print("Potência (2,0) = ", potencia(2, 2))
