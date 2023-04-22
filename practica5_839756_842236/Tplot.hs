-- Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

module Tplot where

import SVG
import Turtle

-- Se devuelve la posición de una tortuga
getPosition :: Turtle -> Position
getPosition (_, _, p, _) = p

-- Se devuelve el movimiento a partir de un carácter
replaceMove :: Char -> Move
replaceMove c
  | c == '>' = Forward
  | c == '+' = TurnRight
  | c == '-' = TurnLeft

{-
  Se usa map sobre replaceMove para tranformar la lista de carácteres en una lista de movimientos a seguir por la tortuga.
  Después se emplea scanl para aplicar la función moveTurtle a la tortuga para que siga la lista de movimientos dada.
  Finalmente, se usa map getPosition para extraer la posición de la tortuga después de cada movimiento y almacenarla en una lista.
  La lista de posiciones resultante se devuelve como resultado de la función tplot.
-}
tplot :: Turtle -> String -> [Position]
tplot tortoise steps =
  map getPosition (scanl moveTurtle tortoise (map replaceMove steps))