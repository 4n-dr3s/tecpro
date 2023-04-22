-- Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

module Rules where

-- En este módulo se encuentran diferentes reglas para generar dibujos

-- Curva de Koch
rulesKoch :: Char -> String
rulesKoch c
  | c == 'F' = "F+F--F+F"
  | otherwise = [c]

-- Curva de Koch cuadrada
rulesSquaredKoch :: Char -> String
rulesSquaredKoch c
  | c == 'F' = "F+F-F-F+F"
  | otherwise = [c]

-- Copo de nieve de Koch
rulesSnowflake :: Char -> String
rulesSnowflake c
  | c == 'F' = "F-F++F-F"
  | otherwise = [c]

-- Anticopo de nieve de Koch
rulesAntiSnowflake :: Char -> String
rulesAntiSnowflake c
  | c == 'F' = "F+F--F+F"
  | otherwise = [c]

-- Isla de Minkowski
rulesMinkowski :: Char -> String
rulesMinkowski c
  | c == 'F' = "F+F-F-FF+F+F-F"
  | otherwise = [c]

-- Triángulo de Sierpinsky
rulesSierpinsky :: Char -> String
rulesSierpinsky c
  | c == 'F' = "F-G+F+G-F"
  | c == 'G' = "GG"
  | otherwise = [c]

-- Sierpinsky Arrowhead
rulesArrowhead :: Char -> String
rulesArrowhead c
  | c == 'F' = "G-F-G"
  | c == 'G' = "F+G+F"
  | otherwise = [c]

-- Curva de Hilbert
rulesHilbert :: Char -> String
rulesHilbert c
  | c == 'f' = "-g>+f>f+>g-"
  | c == 'g' = "+f>-g>g->f+"
  | otherwise = [c]

-- Curva de Gosper
rulesGosper :: Char -> String
rulesGosper c
  | c == 'F' = "F-G--G+F++FF+G-"
  | c == 'G' = "+F-GG--G-F++F+G"
  | otherwise = [c]