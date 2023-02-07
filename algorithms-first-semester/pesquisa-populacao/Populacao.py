# Uma pesquisa sobre a população de uma determinada região coletou os seguintes dados, referentes a cada habitante,
#  para serem analisados:
#
#  Idade (em anos)
#  Sexo (M - masculino, F - feminino)
#
#  A fim de indicar o final da entrada, após a sequência de dados dos habitantes,
#  o usuário entrará com o valor -1 para a idade, o que deve ser interpretado pelo programa como fim de entrada de dados.
#
#  O programa deve encontrar e mostrar:
#  - a maior idade de um conjunto de indivíduos e
#  - o percentual de indivíduos do sexo feminino com idade entre 18 e 35 anos.
#
# Exercício Semanal - While

idade = 0
maiorIdade = 0
qtdMulheres = 0
qtdTotal = 0

print("\n *** PESQUISA POPULACIONAL ***")

while True:
    print("\n Dados a cadastrar: \n"
          " - idade \n"
          " - sexo (F para feminino ou M para masculino) \n \n"
          "Digite 1 para cadastrar dados \n"
          "Digite -1 para SAIR ")

    escolha = int(input("\n Digite o número correspondente a escolha que deseja seguir: "))

    if escolha == 1:
        idade = int(input(" Digite sua idade: "))

        if idade > 0 and idade > maiorIdade:
            maiorIdade = idade

        while idade < 0:
            print("\n IDADE INVÁLIDA!")
            idade = int(input(" Por favor, digite sua idade corretamente: "))

        sexo = input("Digite o sexo: \n "
                     "M - masculino \n "
                     "F - feminino: \n").lower()

        qtdTotal = qtdTotal + 1

        if sexo == "f" and 18 <= idade <= 35:
            qtdMulheres = qtdMulheres + 1

    if escolha != 1 and escolha != -1:
        print("\n OPÇÃO INCORRETA!")

    elif escolha == -1:

        percentualMulheres = ((qtdMulheres / qtdTotal) * 100.0)
        print("A maior idade de um conjunto de indivíduos é: ", maiorIdade, "anos.")
        print("O percentual de indivíduos do sexo feminino com idade entre 18 e 35 anos é de: ", percentualMulheres,
              "%")
        print("\n Agradecemos a participação!")
        break
