# Elabore um programa que calcule o que deve ser pago por um produto, considerando o preço
# normal de etiqueta e a escolha da condição de pagamento. Utilize os códigos da tabela seguinte
# para ler qual a condição de pagamento escolhida e efetuar o cálculo adequado.
#
# Exercício 2 - pdf aula 7
#
#
#    Código         Condições de pagamento
#      1            À vista em dinheiro ou cheque, recebe 10% de desconto
#      2            À vista no cartão de crédito, recebe 5% de desconto
#      3            Em 2 vezes, preço normal de etiqueta sem juros
#      4            Em 3 vezes, preço normal de etiqueta mais juros de 10%

print(" \n *** Bem-vindo(a) à nossa loja *** \n")

produto = input(" Digite o produto que você deseja comprar: ")

valorProduto = float(input(" Digite o valor do produto escolhido: \n"
                           " (OBS: Para produtos com valor decimal, por gentileza, "
                           "inserir o valor utilizando ponto) \n"))

condicaoPagamento = int(input(" Digite o número que corresponde a condição de pagamento: \n"
                              "1 - À vista em dinheiro ou cheque; \n"
                              "2 - À vista no cartão de crédito; \n"
                              "3 - Em 2 vezes; \n"
                              "4 - Em 3 vezes. \n"))

if condicaoPagamento == 1:
    valorTotal = valorProduto - (valorProduto * 0.10)
    formaPagamento = "à vista em dinheiro ou cheque"
    print(" Você escolheu pagar", formaPagamento, "e irá arcar com o valor de R$ %.2f" % valorTotal)
elif condicaoPagamento == 2:
    valorTotal = valorProduto - (valorProduto * 0.05)
    formaPagamento = "à vista no cartão de crédito"
    print(" Você escolheu pagar", formaPagamento, "e irá arcar com o valor de R$ %.2f" % valorTotal)
elif condicaoPagamento == 3:
    valorTotal = valorProduto / 2
    formaPagamento = "em 2 vezes"
    print(" Você escolheu pagar", formaPagamento, "e irá arcar com o valor de R$ %.2f" % valorTotal,
          "pagando esse em duas vezes, respectivamente.")
elif condicaoPagamento == 4:
    juros = valorProduto * 0.10
    valorTotal = ((valorProduto + juros) / 3)
    formaPagamento = "em 3 vezes"
    print(" Você escolheu pagar", formaPagamento, "e irá arcar com o valor de R$ %.2f" % valorTotal,
          "pagando esse valor em três vezes, respectivamente.")

print(" \n *** Agradecemos pela preferência! ***")
