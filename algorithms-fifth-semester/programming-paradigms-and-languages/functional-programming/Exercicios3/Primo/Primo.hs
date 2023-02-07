{- Exercício 05
Escreva uma função que usa um gerador para verificar se um número é primo. A função recebe como argumento um número natural maior que 1, se o número informado é primo é
devolvido True e caso contrário False.
> primo 15    False
> primo 19    True
> primo 7     True
-}

primo :: Int -> Bool
primo n = if ([i | i <- [1..n], n `mod` i == 0]) == [1,n] then True
else False