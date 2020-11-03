module Chapter2Exercises where

exclaim :: String -> String
exclaim s = 
  (++) s "!"

fourthIndex :: String -> Char
fourthIndex s =
  s !! 4

dropNineChars :: String -> String
dropNineChars s =
  drop 9 s


thirdLetter :: String -> Char
thirdLetter s =
  s !! 2

letterIndex :: Int -> Char
letterIndex i =
  "Curry is awesome!" !! i 

-- rvrs :: String -> String
rvrs = do
  let s = "Curry is awesome"
  let p1 = drop 9 s
  let p2 = take 4 (drop 5 s)
  let p3 = take 5 s
  concat [p1, p2, p3]


  rvrs2 = 
  concat [
    drop 9 s,
    take 4 (drop 5 s),
    take 5 s
  ] where s = "Curry is awespme"


