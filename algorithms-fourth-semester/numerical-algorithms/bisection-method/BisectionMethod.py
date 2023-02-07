from math import cos


def bissection_method(f, a, b, tolerancia, numeroMaximoIteracoes=100):
    i = 1
    fa = f(a)
    sucesso = True

    while i <= numeroMaximoIteracoes:

        p = a + (b - a) / 2
        fp = f(p)

        if (fp == 0) or ((b - a) / 2 < tolerancia):
            print("\nO processo foi concluído com sucesso!")
            print(p)
            break

        i = i + 1
        if fa * fp > 0:
            a = p
            fa = fp

        else:
            b = p

    if not sucesso:
        print("\nO processo excedeu o número máximo de iterações possíveis!")


def function(x):
    print(x - 2 ** x)
    return 0


def main():
    bissection_method(cos, 1, 2, tolerancia=0.00001)


if __name__ == '__main__':
    main()
