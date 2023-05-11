-- Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

module BinaryTree where

import Data.List (sort)

data Tree x = Empty | Leaf x | Branch x (Tree x) (Tree x)

-- Devuelve un árbol vacío, sin ningún elemento
empty :: Tree x
empty = Empty

-- Devuelve un árbol que consta de una única hoja que contiene el elemento x
leaf :: x -> Tree x
leaf = Leaf

-- Devuelve un árbol que contiene en la raíz el elemento x con dos subárboles
tree :: x -> Tree x -> Tree x -> Tree x
tree = Branch

-- Devuelve el número de elementos del árbol
size :: Tree x -> Int
size Empty = 0
size (Leaf _) = 1
size (Branch _ lc rc) = 1 + size lc + size rc

-- Añade el elemento x al árbol t, devolviendo el árbol binario de búsqueda resultante
add :: Ord x => Tree x -> x -> Tree x
add Empty x = Leaf x
add (Leaf l) x
  | l > x = Branch l (Leaf x) Empty
  | otherwise = Branch l Empty (Leaf x)
add (Branch b lc rc) x
  | b > x = Branch b (add lc x) rc
  | otherwise = Branch b lc (add rc x)

-- Construye un árbol binario de búsqueda, comenzando con un árbol vacío
-- e insertando sucesivamente los elementos de la lista xs
build :: (Ord x) => [x] -> Tree x
build = foldl add Empty

-- Construye un árbol equilibrado, ordenando la lista y dividiéndola en dos por la mediana
buildBalanced :: (Ord x) => [x] -> Tree x
buildBalanced xs = buildBalancedAux (sort xs)

-- Función auxiliar de "buildBalanced"
buildBalancedAux :: (Ord x) => [x] -> Tree x
buildBalancedAux [] = Empty
buildBalancedAux [x] = Leaf x
buildBalancedAux xs = Branch m (buildBalancedAux lc) (buildBalancedAux rc)
  where (lc,m:rc) = splitAt (div (length xs) 2) xs

-- Hace recorrido en profundidad en preorden del árbol
preorder :: (Ord x) => Tree x -> [x]
preorder Empty = []
preorder (Leaf x) = [x]
preorder (Branch x lc rc) = [x] ++ preorder lc ++ preorder rc

-- Hace recorrido en profundidad en postorden del árbol
postorder :: (Ord x) => Tree x -> [x]
postorder Empty = []
postorder (Leaf x) = [x]
postorder (Branch x lc rc) = postorder lc ++ postorder rc ++ [x]

-- Hace recorrido en profundidad en inorden del árbol
inorder :: (Ord x) => Tree x -> [x]
inorder Empty = []
inorder (Leaf x) = [x]
inorder (Branch x lc rc) = inorder lc ++ [x] ++ inorder rc

-- Construye un árbol equilibrado (es decir, de altura mínima) 
-- a partir de otro cualquiera
balance :: (Ord x) => Tree x -> Tree x
balance Empty = Empty
balance t = buildBalanced (inorder t)

-- Busca en el árbol binario de búsqueda t y devuelve una lista 
-- con todos los elementos del árbol que están entre los valores 
-- xmin y xmax (ambos inclusive).
between :: (Ord x) => Tree x -> x -> x -> [x]
between Empty xmin xmax = []
between (Leaf l) xmin xmax = [l | l >= xmin && l <= xmax]
between (Branch x lc rc) xmin xmax
  | x < xmin = between rc xmin xmax
  | x > xmax = between lc xmin xmax
  | otherwise = between lc xmin xmax ++ [x] ++ between rc xmin xmax

-- Función auxiliar para mostrar el árbol por pantalla
display :: Show x => Tree x -> Int -> String
display Empty n = "<>"
display (Leaf x) n = show x
display (Branch x lc rc) n = show x ++ "\n" ++
  rep ++ display lc (n+1) ++ "\n" ++
  rep ++ display rc (n+1)
  where rep = replicate (3*n) ' ' ++ "|- "

instance Show x => Show (Tree x) where
  show t = display t 0