import Turtle

replaceMove :: Char -> Move
replaceMove c 
    | c == '>' = Forward
    | c == '+' = TurnRight
    | c == '-' = TurnLeft

tplot :: Turtle -> String -> [Position]
tplot tortuga instrucciones = [(0,0)]

dummy :: String -> [Move]
dummy = map replaceMove

--tplot tortuga instrucciones = foldr moveTurtle tortuga instrucciones

--main = print ( tplot (1,90,(0,0),90) ">+>+>+>+" )
main = print ">+>+>+>+"