{- Exercício 06
Escreva uma função que receba três números inteiros a, b, c como entrada e devolva o menor número. -} 

menor :: Int -> Int -> Int -> Int
menor a b c |(a < b) && (a < c) = a
 | (b < a) && (b < c) = b
 | otherwise = c