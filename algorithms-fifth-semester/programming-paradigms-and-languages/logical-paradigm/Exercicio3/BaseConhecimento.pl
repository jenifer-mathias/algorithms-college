/* Exercício 03

  Dado a base de conhecimento a seguir:
  
- Paulo é genitor de Ana
- Rose é genitor de Ana
- Paulo é genitor de Liliane
- Rose é genitor de Liliane
- Paulo é homem
- Rose é mulher
- Ana é mulher
- Liliane é mulher

Aumente a base de conhecimentos e construa regras para:
- Pai, mãe, irmã, irmão, avô, avó, primo, prima, tio, tia, filho, filha
- Sogro, sogra, genro, nora 

**************************************************

Aumentando a base de conhecimento...

Pais de Eduardo
- Paulo é genitor de Eduardo
- Rose é genitor de Eduardo

**************************************************

Casamento Eduardo e Monica
- Eduardo é casado com Monica
- Monica é casada com Eduardo

Filha de Eduardo e Monica
- Eduardo é genitor de Celeste
- Monica é genitor de Celeste

Pais de Monica
- Arthur é genitor de Eduardo
- Sophia é genitor de Eduardo

**************************************************
Casamento Ana e Richard
- Richard é casado com Ana
- Ana é casada com Richard

Filha de Ana e Richard
- Richard é genitor de Laura
- Ana é genitor de Laura

**************************************************

Casamento Liliane e Mauro
- Mauro é casado com Liliane
- Liliane é casada com Mauro

Filho de Liliane e Mauro
- Mauro é genitor de Michel
- Liliane é genitor de Michel

*/

homem(paulo).
mulher(rose).

homem(arthur).
mulher(sophia).

mulher(ana).
homem(ricahrd).
mulher(laura).

mulher(liliane).
homem(mauro).
homem(michael).

homem(eduardo).
mulher(monica).
mulher(celeste).

/* ************************************************** */

casadx(arthur, sophia).
casadx(sophia, arthur).

genitor(arthur, monica).
genitor(sophia, monica).

/* ************************************************** */

casadx(paulo, rose).
casadx(rose, paulo).

genitor(paulo, ana).
genitor(rose, ana).

genitor(paulo, liliane).
genitor(rose, liliane).

genitor(paulo, eduardo).
genitor(rose, eduardo).

/* ************************************************** */

casadx(ana, richard).
casadx(richard, ana).

genitor(richard, laura).
genitor(ana, laura).

/* ************************************************** */

casadx(liliane, mauro).
casadx(mauro, liliane).

genitor(mauro, michael).
genitor(liliane, michael).

/* ************************************************** */

casadx(eduardo, monica).
casadx(monica, eduardo).

genitor(eduardo, celeste).
genitor(monica, celeste).

/* ************************************************** */

pai(X,Y) :- genitor(X,Y), homem(X).
mãe(X,Y) :- genitor(X,Y), mulher(X).

/* ************************************************** */

irma(X,Y) :- genitor(Z,X), genitor(Z,Y), X \== Y. 
irmao(X,Y) :- genitor(Z,X), genitor(Z,Y), X \== Y. 

/* ************************************************** */

filho(X,Y) :- genitor(Y, X), homem(X). 
filha(X,Y) :- genitor(Y, X), mulher(X).

/* ************************************************** */

avô(X, Y) :- pai(X, Z), pai(Z, Y); pai(X, Z), mãe(Z, Y).
avó(X, Y) :- mãe(X, Z), mãe(Z, Y); mãe(X, Z), pai(Z, Y).

/* ************************************************** */

tia(X,Y) :- irma(X,Z), pai(Z,Y); irma(Z, X), mãe(Z, Y).
tio(X,Y) :- irmao(X,Z), pai(Z,Y); irmao(Z, X), mãe(Z, Y).

/* ************************************************** */

prima(X,Y) :- genitor(X,Y), irma(X,Y), mulher(X).
primo(X,Y) :- genitor(X,Y), irmao(X,Y), homem(X).
/* ************************************************** */

sogro(X,Y) :- pai(X, Z), casadx(Z, Y), homem(X).
sogra(X,Y) :- mãe(X, Z), casadx(Z, Y), mulher(X).

/* ************************************************** */

genro(X,Y) :- sogro(Y, X); sogra(Y, X), homem(X).
nora(X,Y) :- sogro(Y,X); sogra(Y, X), mulher(X).