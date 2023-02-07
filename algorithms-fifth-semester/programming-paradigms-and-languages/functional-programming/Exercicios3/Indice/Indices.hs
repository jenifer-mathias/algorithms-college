{- Exercício 02
Escreva uma função que dado um elemento devolva a lista dos índices que esse elemento se encontra na lista. Utilize:

> indices 3 [1, 2, 3, 3, 4, 4, 3, 2, 1]
[2,3,6]
> indices 'a' ['b', 'a', 'n', 'a', 'n', 'a']
[1,3,5] -}

indices :: Eq a => a -> [a] -> [Int]
indices x ys = [i | (i,y) <- zip [0..n] ys, x == y]
  where n = length ys - 1