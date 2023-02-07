{- Exercício 04
Escreva uma função chamada conta que conta a ocorrência de uma determinada letra em uma string
> conta 'l' "Haskell"
2
> conta 'a' "Senac"
1
> conta 's' "Mississipi"
4 -}

conta :: Char -> String -> Int 
conta y xs = length [x | x<-xs, x==y]