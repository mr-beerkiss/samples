extern crate rand;

use rand::Rng;
use std::io;

enum GameResult {
  SUCCESS,
  FAILURE,
}

fn play_game_at_difficulty(difficulty: usize) -> GameResult {
  let max_codes = 3;

  let mut rng = rand::thread_rng();
  let mut codes = Vec::new();

  for _ in 0..max_codes {
    codes.push(rng.gen_range(1, difficulty + 1))
  }

  let sum: usize = codes.iter().sum();
  let product: usize = codes.iter().product();

  println!("You need to guess three numbers.");
  println!("The sum of the three numbers is {}.", sum);
  println!("The product of the three numbers is {}.", product);

  println!("Enter guess: ");

  let mut input = String::new();
  io::stdin().read_line(&mut input).unwrap();

  let guesses: Vec<usize> = input
    .split_whitespace()
    .map(|guess_str| guess_str.parse::<usize>().unwrap())
    .collect();

  for guess in guesses {
    match codes.iter().position(|code| *code == guess) {
      Some(v) => {
        println!("{} is correct!", guess);
        codes.remove(v);
      }
      None => {
        println!("{} is incorrect!", guess);
        return GameResult::FAILURE;
      }
    }
  }

  GameResult::SUCCESS
}

fn main() {
  println!("{esc}[2J{esc}[1;1H", esc = 27 as char);
  println!(
    "You have awoken in a strange room. You do not remember how you got here. \
    You notice a faint glow a few feet away. You feel weak, and cannot stand up. \
    You crawl over to the glow. As you approach the glow you recognise the the \
    silhouette of very old computer.\n"
  );

  let mut difficulty = 2;
  let max_difficulty = 10;
  while difficulty < max_difficulty {
    match play_game_at_difficulty(2) {
      GameResult::SUCCESS => {
        println!("You win!");
        difficulty += 1;
      }
      GameResult::FAILURE => {
        println!("You failed!");
        break;
      }
    };
  }

  println!("GAME OVER");
}
