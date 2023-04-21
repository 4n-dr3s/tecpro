import Tplot
import Lsystem
import SVG

rulesArrowhead :: Char -> String
rulesArrowhead c
    | c == 'F' = "G-F-G"
    | c == 'G' = "F+G+F"
    | otherwise = [c]

--main = print ( translate ( lsystem rulesArrowhead "F" 1 ) )
--main = savesvg "arrowhead" (tplot (1, 90, (0, 0), 90) lsystem rulesArrowhead "F" 30)

main = savesvg "arrowhead" (tplot (1, 60, (0, 0), 90) ( translate ( lsystem rulesArrowhead "F" 5 ) ) )