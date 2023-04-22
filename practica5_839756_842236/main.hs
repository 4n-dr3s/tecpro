import Lsystem
import Rules
import SVG
import Tplot
import Turtle

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

test :: (String, Char -> String, String, Int, Float, Float, Heading) -> IO ()
test (name, rule, axiom, depth, step, turn, heading) = savesvg name (tplot (step, turn, (0, 0), heading) (translate (lsystem rule axiom depth)))

-- main = savesvg "arrowhead" (tplot (1, 60, (0, 0), 90) (translate (lsystem rulesArrowhead "F" 5)))
main = mapM test testList