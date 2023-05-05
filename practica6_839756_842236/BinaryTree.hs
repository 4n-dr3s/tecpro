module BinaryTree where

data tree x = empty | leaf x | tree x (tree x) (tree x) 