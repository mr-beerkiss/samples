// `vst` uses macros, so we'll need to specify that we're using them!
#[macro_use]
extern crate vst;

use vst::plugin::{Info, Plugin, Category};

#[derive(Default)]
struct Whisper;

// We're implementing a trait `Plugin` that does all the VST-y stuff for us.
impl Plugin for Whisper {
  fn get_info(&self) -> Info {
    Info {
      name: "Whisper".to_string(),

      // Used by hosts to differeniate between plugins.
      // Don't worry much about this now - just fill in a random number.
      unique_id: 1337,

      // We don't need inputs
      inputs: 0,

      // We do need two outputs though. This is default, but let's be explicit anyways.
      outputs: 2,

      // Set our category
      category: Category::Synth,

      // We don't care about other stuff, and it can stay default
      ..Default::default()
    }
  }
}

// Make sure you call this, or nothing will happen.
plugin_main!(Whisper);