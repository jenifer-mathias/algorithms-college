""" Atividade 2 de participação
  Algumas vezes queremos armazenar dados em um arquivo texto, onde
  cada linha corresponderia a um registro. Podemos separar as várias
  informações de uma linha, utilizando um caractere específico, por exemplo
  um ponto e vírgula (“;“).
  Exemplo o arquivo texto alunos.txt
  Jose da Silva;10.0
  Manoel Pereira;5.0
  Carlos Dias;7.0
  Ana Andrade;6.5
  No arquivo alunos.txt cada linha tem os dados de um aluno com seu
  nome;nota separados por ponto e vírgula (“;“). Faça um programa que leia
  as linhas do arquivo alunos.txt. Para cada linha lida, você deve separar o
  nome e a nota do aluno. Para fazer essa separação, pesquise o método
  split() do classe String do Python. Ao final, seu programa deve informar a
  média das notas lidas e o nome e nota do aluno com a maior nota.
"""


def manipulateFile(nomeAlunos, notaAlunos):
    pathFile = " "  # replace with your path
    fileToRead = open(pathFile + 'students.txt', 'r')
    for line in fileToRead:
        values = line.replace('\n', '').split(';')
        nomeAlunos.append(values[0])
        notaAlunos.append(float(values[1]))
    fileToRead.close()


def averageGrades(studentGrades):
    return sum(studentGrades) / len(studentGrades)


def bestStudent(nameStudents, grade):
    aux = grade.index(max(grade))
    return nameStudents[aux]


def bestGrade(gradeStudent):
    return max(gradeStudent)


def main():
    print("\n*** Média e maior nota dos alunos *** \n")
    studentNames = []
    studentGrades = []
    manipulateFile(studentNames, studentGrades)
    gradeAvarage = float(averageGrades(studentGrades))
    studentsBestGrade = bestStudent(studentNames, studentGrades)
    maxGrade = bestGrade(studentGrades)
    print(f'Nota Media: {gradeAvarage}')
    print(f'a o aluno {studentsBestGrade} teve a maior nota, cujo valor é: {maxGrade}\n')

    return


if __name__ == "__main__":
    main()