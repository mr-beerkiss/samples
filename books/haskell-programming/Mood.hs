module Mood where

data Mood = Blah | Woot deriving Show

changeMood :: Mood -> Mood
changeMood m = if m == Blah then Woot else Blah

