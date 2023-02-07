{- Exercício 04
Usando expressões case, faça uma função que receba um número n, e uma lista L, devolva
os n elementos de L.
> obter 3 [1,2,3,4,5,6,7,8]
[1,2,3]
> obter 3 [7,8]
[7,8] -}

obter :: Int -> [Int] -> [Int]
obter n _ | n <= 0   = []  
obter _ []     = []  
obter n (x:xs) = x : obter (n-1) xs