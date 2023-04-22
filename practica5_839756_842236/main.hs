-- Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

import Lsystem
import Rules
import SVG
import Tplot
import Turtle

-- Devuelve una lista de tuplas con toda la información para hacer pruebas con diferentes reglas
testList :: [(String, Char -> String, String, Int, Float, Float, Heading)]
testList =
  [ ("koch", rulesKoch, "F", 5, 1, 60, 0),
    ("squaredkoch", rulesSquaredKoch, "F", 5, 1, 90, 0),
    ("snowflake", rulesSnowflake, "F++F++F", 5, 1, 60, 90),
    ("antisnowflake", rulesAntiSnowflake, "F++F++F", 5, 1, 60, 180),
    ("minkowski", rulesMinkowski, "F+F+F+F", 5, 1, 90, 90),
    ("sierpinsky", rulesSierpinsky, "F-G-G", 5, 1, 120, 180),
    ("arrowhead", rulesArrowhead, "F", 5, 1, 60, 180),
    ("hilbert", rulesHilbert, "f", 5, 1, 90, 90),
    ("gosper", rulesGosper, "F", 3, 1, 60, 90)
  ]

{-
  Aplicamos depth veces la regla al axioma empleando lsystem.
  Después transformamos la string devuelta a carácteres que pueda entender tplot ('>', '+', '-').
  A partir de una tortuga inicial, la función tplot sigue la ruta generada por lsystem.
  Finalmente, se guarda la lista de puntos devuelta por tplot en un SVG de nombre "name".
-}
test :: (String, Char -> String, String, Int, Float, Float, Heading) -> IO ()
test (name, rule, axiom, depth, step, turn, heading) = savesvg name (tplot (step, turn, (0, 0), heading) (translate (lsystem rule axiom depth)))

-- Testeamos cada tupla de la lista, generando el dibujo correspondiente
main = mapM test testList