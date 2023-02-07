{- Exercício 01
Escreva uma função que verifique se uma lista está em ordem crescente. Neste exercício, utilize compreensão de listas e a função zip. 

> crescente [2,3] True
> crescente [2,3,4,5,6] True
> crescente [2,3,5,4] False
-}

crescente :: [Int] -> Bool
crescente xs = and [x < y | (x,y) <- zip xs (tail xs)]