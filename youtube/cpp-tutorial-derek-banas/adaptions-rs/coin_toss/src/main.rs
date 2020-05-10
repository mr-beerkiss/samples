extern crate rand;

use rand::Rng;

enum CoinToss {
    HEADS,
    TAILS,
}

fn gen_coin_tosses(amount: usize) -> Vec<CoinToss> {
    let mut rng = rand::thread_rng();
    let mut tosses: Vec<CoinToss> = Vec::new();
    for _ in 0..amount {
        // `gen_range` is exclusive on the max so need to +1 to be inclusive
        let toss = rng.gen_range(0, 2);
        if toss == 0 {
            tosses.push(CoinToss::HEADS);
        } else {
            tosses.push(CoinToss::TAILS);
        }
    }
    tosses
}

fn main() {
    let vec = gen_coin_tosses(100);

    let mut heads_count = 0;
    let mut tails_count = 0;

    for t in vec {
        match t {
            CoinToss::HEADS => heads_count += 1,
            CoinToss::TAILS => tails_count += 1,
        }
    }

    println!(
        "Heads landed {} times and tails {} times",
        heads_count, tails_count
    );
}
