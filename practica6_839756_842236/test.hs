import BinaryTree

t1 = tree 1 (tree 2 (leaf 3) (leaf 4)) (tree 5 empty (leaf 6))

t2 = add (add (add Empty 3) 2) 5

t3 = build [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]

t4 = build [3, 2, 2, 5, 1, 4, 4]

t5 = buildBalanced [1 .. 6]

names = build ["Adolfo", "Diego", "Juan", "Pedro", "Tomas"]

main = print (balance names)
