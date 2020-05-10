extern crate rand;

use rand::Rng;

struct Warrior {
    name: String,
    max_attack: u16,
    max_block: u16,
    health: u16,
    dead: bool,
    // rng: rand::thread_rng(),
}

impl Warrior {
    pub fn new(name: String, health: u16, attack: u16, block: u16) -> Warrior {
        Warrior {
            name,
            max_attack: attack,
            max_block: block,
            health,
            dead: false,
        }
    }

    pub fn attack(&self) -> u16 {
        let mut rng = rand::thread_rng();
        rng.gen::<u16>() % self.max_attack
    }

    pub fn block(&self) -> u16 {
        let mut rng = rand::thread_rng();
        rng.gen::<u16>() % self.max_block
    }

    pub fn take_damage(&mut self, amount: u16) {
        self.health = match self.health.checked_sub(amount) {
            Some(v) => v,
            None => 0,
        };
        if self.health == 0 {
            self.dead = true;
        }
    }
}

struct Battle;

impl Battle {
    pub fn start_fight(mut defender: Warrior, mut attacker: Warrior) {
        loop {
            let damage = attacker.attack();
            let block = defender.block();

            let actual = match attacker.attack().checked_sub(block) {
                Some(v) => v,
                None => 0,
            };

            defender.take_damage(actual);

            println!(
                "{} attacks {} and deals {} damage",
                attacker.name, defender.name, damage
            );
            println!("{} is down to {}", defender.name, defender.health);

            if defender.dead {
                println!(
                    "{} has died and {} is victorious!",
                    defender.name, attacker.name
                );
                println!("GAME OVER!");
                break;
            }

            std::mem::swap(&mut attacker, &mut defender);
        }
    }
}

fn main() {
    let hulk = Warrior::new(String::from("Hulk"), 135, 25, 10);
    let thor = Warrior::new(String::from("Thor"), 100, 30, 15);

    Battle::start_fight(hulk, thor);
}
