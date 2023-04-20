import Turtle
import Distribution.Fields.LexerMonad (getPos)

getPosition :: Turtle -> Position
getPosition (_,_,p,_) = p

replaceMove :: Char -> Move
replaceMove c 
    | c == '>' = Forward
    | c == '+' = TurnRight
    | c == '-' = TurnLeft

tplot :: Turtle -> String -> [Position]
tplot tortuga instrucciones = 
    --[getPosition ( fondr moveTurtle tortuga (map replaceMove instrucciones) )]
    [getPosition ( moveTurtle (1,90,(0,0),90) Forward )]

--tplot tortuga instrucciones = foldr moveTurtle tortuga instrucciones

main :: IO ()
-- main = print ( getPosition (1,90,(0,0),90) )

main = print ( tplot (1,90,(0,0),90) ">+>+>+>+" )