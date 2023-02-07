{- Exercício 06
Escreva uma função que verifique se uma lista está em ordem crescente.
> crescente [2,3] True
> crescente [2,3,4,5,6] True
> crescente [2,3,5,4] False -}

crescente :: [Int] -> Bool
crescente [x] = True
crescente (x:y:xs) = if x > y then False
                    else crescente (y:xs)