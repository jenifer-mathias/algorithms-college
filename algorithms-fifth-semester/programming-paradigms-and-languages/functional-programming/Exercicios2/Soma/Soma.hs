{- Exercício 02
Dada uma lista de inteiros, escreva uma função que some todos os elementos. Não utilize a
função sum.
> somar [1,2,3,4,5,6]
21 -}

somar :: [Int] -> Int
somar [] = 0
somar (x:xs) = x + somar xs