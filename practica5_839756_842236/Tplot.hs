module Tplot where

import SVG
import Turtle

getPosition :: Turtle -> Position
getPosition (_, _, p, _) = p

replaceMove :: Char -> Move
replaceMove c
  | c == '>' = Forward
  | c == '+' = TurnRight
  | c == '-' = TurnLeft

tplot :: Turtle -> String -> [Position]
tplot tortoise steps =
  map getPosition (scanl moveTurtle tortoise (map replaceMove steps))

--main = savesvg "test" (tplot (1, 0, (0, 0), 90) ">+>+>+>+")