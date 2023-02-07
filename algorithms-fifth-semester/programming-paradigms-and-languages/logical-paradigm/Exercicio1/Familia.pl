/* Exercício 01

Dados os seguintes fatos:

- Joana é mãe de Pedro
- Pedro é pai de José
- Ana é mãe de Joana
- José é pai de Clara

Escreva consultas em prolog para as seguintes questões:
- Joana é avó de José?
- Pedro é avô de Clara?
- Ana é bisavó de alguém? De quem? */

mae(joana, pedro).
pai(pedro, jose).
mae(ana, joana).
pai(jose, clara).

avo(X, Y) :- mae(X,Z), mae(Z,Y).
avô(X, Y) :- pai(X,Z), pai(Z,Y).
bisavo(X, Y) :- avo(X,Z), avo(Z,Y).