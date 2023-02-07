{- Exercício 05
Fazer uma função para concatenar uma lista de listas. Neste exercício deve-se usar,
necessariamente, notação em compreensão.
> concatenar [[1,2,3],[4,5],[6,7]]
[1, 2, 3, 4, 5, 6, 7] -}

concatenar2 :: [[a]] -> [a]
concatenar2 l = [x | lista <- l, x <- lista]