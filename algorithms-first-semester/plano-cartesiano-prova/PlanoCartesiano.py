# Prova
#
# Faça um programa Python para ler do usuário 2 valores (x e y)
#  no formato float, que devem representar as coordenadas de um ponto
#  em um plano cartesiano. A seguir, seu programa deve determinar qual
#  o quadrante ao qual pertence o ponto, ou se está sobre um dos eixos
#  cartesianos ou se está na origem do plano (x = y = 0)
#
#  Se o ponto estiver na origem, seu programa deve imprimir a mensagem “Origem”.
#  Se o ponto estiver sobre um dos eixos seu programa deverá imprimir
#   “Eixo X” ou “Eixo Y”,conforme for a situação.
#   Já se o ponto estiver em algum dos quadrantes,
#  seu programa imprimirá em qual quadrante ele está (Q1, Q2, Q3 ou Q4).
#
#  Atenção: Vocês podem usar qualquer editor para fazer o programa,
#  mas devem anexar na questão o arquivo .py do programa.
#  (Arquivo fora do formato anulará a resposta).
#  O campo de texto abaixo não precisa ser utilizado.
#  O programa deve usar if-elif-else.

x = float(input(" Digite o primeiro número: "))
y = float(input(" Digite o segundo número: "))

q1 = x > 0 and y > 0
q2 = x < 0 and y > 0
q3 = x < 0 and y < 0
q4 = x > 0 and y < 0
eixoX = y == 0
eixoY = x == 0
origem = x == 0 and y == 0

if origem:
    print("Origem")
elif eixoX:
    print("Eixo X")
elif eixoY:
    print("Eixo y")
elif q1:
    print("Q1")
elif q2:
    print("Q2")
elif q3:
    print("Q3")
else:
    print("Q4")
