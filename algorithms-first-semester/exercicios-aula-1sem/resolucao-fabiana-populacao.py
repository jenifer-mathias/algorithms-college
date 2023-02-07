maior = 0
contp=0
cont=0
while (True):
    idade = int(input('Idade:'))
    if idade==-1:
        break
    sexo = input('Sexo (F/M): ').upper()
    if idade>maior:      #acha maior idade
        maior = idade
    if sexo=='F' and (idade>=18 and idade<=35):
        contp+=1         #conta quem atende a condição
    cont+=1              #conta todos
if cont!=0:
    print('Maior idade = ' , maior)
    print('Percentual de indivíduos do sexo feminino com idade entre 18 e 35 anos = ', contp/cont*100, "%")
else:
    print('Não houve procesamento')
