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
tplot tortuga instrucciones =
  map getPosition (scanl moveTurtle tortuga (map replaceMove instrucciones))

-- main = savesvg "test" (tplot (1, 90, (0, 0), 90) ">+>+>+>+")