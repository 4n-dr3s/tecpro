-- Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

module Lsystem where

import Data.Char

{-
  La función lsystem transforma el axioma inicial en la cadena resultante
  después de aplicar depth veces las reglas.
  Se aplica de forma iterativa la función concatMap rule a axioma para aplicar
  las reglas de sustitución creando una lista infinita.
  ConcatMap es la encargada de aplicar la regla a cada caracter de la cadena axioma.
  Con take se cogen las primeras cadenas que se les han aplicado la regla hasta depth veces.
  Con last tomamos la última cadena de la lista que es la resultante de haber aplicado
  las reglas de sustitución al axioma exactamente depth veces.
-}
lsystem :: (Char -> String) -> String -> Int -> String
lsystem rule axiom depth = last (take (depth + 1) (iterate (concatMap rule) axiom))

{-
  La función translate permite eliminar de la String recibida todos los carácteres en minúscula
  y cambiar aquellos carácteres que están en mayúscula por el carácter '>'.
-}
translate :: String -> String
translate str =
  [ (\c -> if isUpper c then '>' else c) c
    | c <- str,
      not (isLower c)
  ]