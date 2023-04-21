module Lsystem where
import Data.Char

lsystem :: (Char -> String) -> String -> Int -> String
lsystem rule str depth = last ( take (depth + 1) ( iterate ( concatMap rule ) str ) )

translate :: String -> String
translate str = [(\ c -> if isUpper c then '>' else c) c |
                   c <- str, not (isLower c)]