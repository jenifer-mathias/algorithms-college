{- Exercício 01
Escreva uma função para concatenar uma lista de listas. Utilizar casamento de padrões.
> Concatenar [[1,2,3,4,5,6],[7,8],[9,10,11]]
[1,2,3,4,5,6,7,8,9,10,11] -}

concatenar [] = []
concatenar (x:xs) = x ++ concatenar xs