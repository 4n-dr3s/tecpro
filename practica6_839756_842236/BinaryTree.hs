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
buildBalanced [] = Empty
buildBalanced [x] = Leaf x
buildBalanced xs = Branch mid (buildBalanced left) (buildBalanced right)
  where
    sorted = sort xs
    len = length sorted
    mid = sorted !! (len `div` 2)
    left = take (len `div` 2) sorted
    right = drop (len `div` 2 + 1) sorted

preorder :: (Ord x) => Tree x -> [x]
preorder Empty = []
preorder (Leaf x) = [x]
preorder (Branch x lc rc) = [x] ++ preorder lc ++ preorder rc

postorder :: (Ord x) => Tree x -> [x]
postorder Empty = []
postorder (Leaf x) = [x]
postorder (Branch x lc rc) = postorder lc ++ postorder rc ++ [x]

inorder :: (Ord x) => Tree x -> [x]
inorder Empty = []
inorder (Leaf x) = [x]
inorder (Branch x lc rc) = inorder lc ++ [x] ++ inorder rc

balance :: (Ord x) => Tree x -> Tree x
balance Empty = Empty
balance t = buildBalanced (inorder t)

between :: (Ord x) => Tree x -> x -> x -> [x]
between t xmin xmax = [i | i <- inorder t, i >= xmin, i <= xmax]

instance Show x => Show (Tree x) where
  show Empty = "<>"
  show (Leaf x) = show x
  show (Branch x lc rc) =
    show x
      ++ "\n"
      ++ "|-"
      ++ showIndented lc
      ++ "|-"
      ++ showIndented rc
    where
      showIndented t = unlines $ map (" " ++) (lines $ show t)