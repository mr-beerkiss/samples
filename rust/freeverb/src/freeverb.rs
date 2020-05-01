use super::{all_pass::AllPass, comb::Comb};

const COMB_TUNING_L1: usize = 1116;
const COMB_TUNING_R1: usize: 1116 + STEREO_SPREAD;
const COMB_TUNING_L2: usize: 1118;
const COMB_TUNING_R2: usize: 1118 + STEREO_SPREAD;
const COMB_TUNING_L3: usize: 1277;
const COMB_TUNING_R3: usize: 1277 + STEREO_SPREAD;

fn adjust_length(length: usize, sr: usize) -> usize {
  (length as f64 * sr as f64 / 44100.0) as usize
}

pub struct Freeverb {
  combs: [(Comb, Comb); 8],
  allpasses: [(AllPass, AllPass); 4],
  wet_gains: (f64, f64),
  wet: f64,
  width: f64,
  dry: f64,
  input_gain: f64,
  dampening: f64,
  room_size: f64,
  frozen: bool,
}

impl Freeverb {
  pub fn new(sr: usize) -> Self {
    let mut freeverb = Freeverb {
      combs: [
        (
          Comb::new(adjust_length(COMB_TUNING_L1, sr)),
          Comb::new(adjust_length(COMB_TUNING_R1, sr)),
        ),
        (
          Comb::new(adjust_length(COMB_TUNING_L2, sr)),
          Comb::new(adjust_length(COMB_TUNING_R2, sr)),
        ),
      ],
      wet_gains: (0.0, 0.0),
      wet: 0.0,
      dry: 0.0,
      input_gain: 0.0,
      width: 0.0,
      dampening: 0.0,
      room_size: 0.0,
      frozen: false,
    };
    freeverb.set_wet(1.0);
    freeverb.set_width(0.5);
    freeverb.set_dampening(0.5);
    freeverb.set_room_size(0.5);
    freeverb.set_frozen(false);
    freeverb
  }

  pub fn set_wet(&mut self, value: f64) {
    self.wet = value * SCALE_WET;
    self.update_wet_gains();
  }

  pub fn set_width(&mut self, value: f64) {
    self.width = value;
    self.update_wet_gains();
  }

  fn update_wet_gains(&mut self) {
    self.wet_gains = (
      self.wet * (self.width / 2.0 + 0.5),
      self.wet * ((1.0 - self.width) / 2.0),
    )
  }
}