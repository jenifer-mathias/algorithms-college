# Fibonacci é sempre a soma dos dois npumeros anteriores
# Ex: 0, 1, 1, 2, 3, 5, 8, 13, 21, 24...

def fibonacci(n):
    if n == 0 or n == 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)


print("Fib(4)=", fibonacci(4))


# condição de parada: profundidade de 0 ou 1 é 0

def profundFibonacci(n):
    if n == 0 or n == 1:
        return 0
    else:
        return profundFibonacci(n - 1) + profundFibonacci(n - 2) + 2


print("Profund =", profundFibonacci(2))



