-- Solução do prof: correção dos exercícios - aula 12

concatenar :: [[a]] -> [a]
concatenar [] = []
concatenar (x:xs) = x ++ concatenar xs

somar :: [Int] -> Int
somar [] = 0
somar (x: xs) = x + somar xs

contem :: [Int] -> Int -> Bool
contem [] _ = False
contem (x:xs) y | x == y = True
                | otherwise = contem xs y

obter :: Int -> [Int] -> [Int]
obter 0 _ = []
obter _ [] = []
obter n (x:xs) = [x] ++ obter(n - 1) xs

concatenar2 :: [[Int]] -> [Int]
concatenar2 xss = [x | xs <- xss, x <- xs]

crescente [] = True
crescente [x] = True
crescente (x : y : xs) | x < y = crescente (y : xs)
                       | otherwise = False

crescente1 :: [Int] -> Bool
crescente1 xs = and [x < y | (x,y) <- zip xs (tail xs)]
