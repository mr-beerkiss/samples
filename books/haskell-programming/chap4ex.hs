module Chapter4Exercises where

isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome s = reverse s == s

abs1 :: Int -> Int
abs1 a =
  if a < 0
    then a * (-1)
  else
    a

f :: (a,b) -> (c,d) -> ((b, d), (a, c))
f (a,b) (c,d) = ((b, d), (a, c))

x = (+)
f2 xs = w `x` 1
      where w = length xs


y a = a


f3 a = fst a 
