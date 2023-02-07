# Problema 20 - pdf aula 7
#
# Conta de água
#
# A empresa local de abastecimento de água, a Saneamento Básico da Cidade (SBC), está promovendo
# uma campanha de conservação de água, distribuindo cartilhas e promovendo ações demonstrando
# a importância da água para a vida e para o meio ambiente.
# Para incentivar mais ainda a economia de água, a SBC alterou os preços de seu fornecimento de
# forma que, proporcionalmente, aqueles clientes que consumirem menos água paguem menos pelo
# metro cúbico. Todos clientes pagam mensalmente uma assinatura de R$ 7, que inclui uma franquia de
# 10 m³ de água. Isto é, para qualquer consumo entre 0 e 10 m³, o consumidor paga a mesma quantia
# de R$ 7 reais (note que o valor da assinatura deve ser pago mesmo que o consumidor não tenha
# consumido água). Acima de 10 m³ cada metro cúbico subsequente tem um valor diferente,
# dependendo da faixa de consumo. A SBC cobra apenas por quantidades inteiras de metros cúbicos
# consumidos. A tabela abaixo especifica o preço por metro cúbico para cada faixa de consumo:
#
#
#        Faixa de consumo (m3)                  Preço (m3)
#               até 10                      incluído na franquia
#              11 a 30                            R$ 1
#              31 a 100                           R$ 2
#           101 em diante                         R$ 5
#
# Assim, por exemplo, se o consumo foi de 120 m³ , o valor da conta é:
#
#   • 7 reais da assinatura básica;
#   • 20 reais pelo consumo no intervalo 11 - 30 m³;
#   • 140 reais pelo consumo no intervalo 31 - 100 m³;
#   • 100 reais pelo consumo no intervalo 101 - 120 m³.
#
# Logo o valor total da conta de água é R$ 267
#
# Escreva um programa que, dado o consumo de uma residência em m3 , calcula o valor da conta de
# água daquela residência.
#
# Entrada
# A única linha da entrada contém um único inteiro N, indicando o consumo de água da residência,
# em m³ (0 ≤ N ≤ 10³).
#
# Saída
# Seu programa deve imprimir uma única linha, contendo o valor da conta de água daquela residência.

print(""" \n *** CAMPANHA DE PRESERVAÇÃO DE ÁGUA - 2020 *** \n
Sobre a campanha: \n
Nós da empresa SBC - Saneamento Básico da Cidade, iniciamos a Campanha de Preservação de Água 
como forma de diminuirmos o consumo de água na cidade e, consequentemente, promover a diminuição de custos 
aos clientes que obtiverem um baixo consumo por metros cúbicos. \n
Para calcularmos o valor da sua conta de água, precisamos de algumas informações. Vamos começar? \n""")

metrosCubicos = int(input("Por favor, digite a quantidade de água consumida em metros cúbicos: \n"
                          "OBS: Para computarmos o valor do  seu consumo mensal "
                          "indique apenas o valor inteiro em metros cúbicos. \n"))

assinaturaPadrao = 7.00
assinaturaSegundaFx = 27.00
assinaturaTerceiraFx = 167.00

fxOnzeAtrinta = 1.00
fxTrintaEumAcem = 2.00
fxCentoEumOuMais = 5.00
valorConsumoAgua = ""

if metrosCubicos <= 10:
    valorConsumoAgua = assinaturaPadrao
elif 10 <= metrosCubicos <= 30:
    valorConsumoAgua = (metrosCubicos - 10) * fxOnzeAtrinta + assinaturaPadrao
elif 31 <= metrosCubicos <= 100:
    valorConsumoAgua = (metrosCubicos - 30) * fxTrintaEumAcem + assinaturaSegundaFx
elif metrosCubicos >= 101:
    valorConsumoAgua = (metrosCubicos - 100) * fxCentoEumOuMais + assinaturaTerceiraFx

print(" O valor do consumo de água mensal a ser pago é de: R$ %.2f" % valorConsumoAgua,
      "\n \n Ajude sempre a preservar o planeta!"
      "\n Compartilhe a campanha nas redes sociais usando a #EuAjudoOplanetaSBC")
