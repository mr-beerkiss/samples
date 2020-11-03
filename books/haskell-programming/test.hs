sayHello :: String -> IO ()
sayHello x = 
  putStrLn ("Hello, " ++ x ++ "!")

triple x = x * 3

double x = x * 2

square x = (*) x x

-- half :: Int -> Int ()
half x = (/) x 2

tripPlusOne x = x * 3 + 1

mutSquareByPi x = (*) pi (square x)
