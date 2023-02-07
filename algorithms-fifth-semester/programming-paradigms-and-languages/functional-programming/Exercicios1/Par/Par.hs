{- Exercício 03
Escreva uma função que recebe um número e verifica se ele é par. A função retorna True
caso o número seja par ou False caso contrário. -}

eh_par :: Int -> Bool
eh_par numero = if numero `mod`2==0 then True else False