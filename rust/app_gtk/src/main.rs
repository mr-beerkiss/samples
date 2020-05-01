fn main() {
    run_main::<FreeverbModule>();
}

fn run_main<Module: AudioModule>() {
    let (command_sender, command_receiver) = crossbeam_channel::bounded(128);

    let sample_rate = 44100;
    std::thread::spawn(move || {
        portaudio_thread::run_audio::<Module(command_receiver, sample_rate)
    });
}