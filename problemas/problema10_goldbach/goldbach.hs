-- Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

-- Función que indica si un número es primo o no
isPrime :: Integer -> Bool
isPrime n = all ((/= 0) . mod n) [2 .. (round . sqrt . fromInteger) n]

-- Función que devuelve una lista de primos entre 1 y n
primesn :: Integer -> [Integer]
primesn n = 1 : 2 : [x | x <- [3, 5 .. n], isPrime x]

-- Función que devuelve una lista de tuplas, cuya suma de componentes da n
goldbach :: Integer -> [(Integer, Integer)]
goldbach n = [(p1, p2) | p1 <- primes, p1 <= div n 2, p2 <- primes, p1 + p2 == n]
  where
    primes = primesn n

n = 74

main = do
  print n
  print $ goldbach n
