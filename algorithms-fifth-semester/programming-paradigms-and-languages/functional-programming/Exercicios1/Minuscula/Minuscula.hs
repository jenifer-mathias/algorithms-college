import Data.Char

{- Exercício 01
Escreva uma função que devolve verdadeiro caso o caracter passado como parâmetro seja
uma letra minúscula, e devolva falso caso contrário. -}

eh_minuscula :: Char -> Bool
eh_minuscula palavra = if (isLower palavra) then True else False
