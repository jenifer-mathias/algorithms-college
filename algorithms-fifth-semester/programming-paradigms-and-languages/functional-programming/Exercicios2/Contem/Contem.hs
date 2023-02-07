{- Exercício 03
Escreva uma função para verificar se um número está na lista na lista de inteiros
> contem [1,2,3] 1 
-- True
> [4,6,3,7] `contem` 5
False -}

contem :: Eq t => [t] -> t -> Bool
contem [] numero = False
contem (x:xs) numero = if (x == numero) then True
else contem xs numero