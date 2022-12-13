
fn main() {
    let mut X: i32 = 1;
    let mut cycles: i32 = 0;
    let mut signal_strength: i32 = 0;

    let file_contents = std::fs::read_to_string("day10.txt").unwrap();
    let instructions: Vec<&str> = file_contents.split("\r\n").collect();
    let checks = vec![1, 20, 60, 100, 140, 180, 220];

    for i in instructions {
        let instruction = &i[0..4];

        if instruction == "noop" {
            cycles += 1;
            if checks.contains(&cycles) { signal_strength += X * cycles }
            println!("{}", checks.contains(&cycles));

        } else if instruction == "addx" {
            let split = i.split(" ");
            let split_instruction: Vec<&str> = split.collect();
            let val = split_instruction[1].parse::<i32>().unwrap();

            cycles += 1;
            if checks.contains(&cycles) { signal_strength += X * cycles }
            X += val;
            cycles += 1;
            if checks.contains(&cycles) { signal_strength += X * cycles }
        }
        println!("{} | cycle count: {} | {}", instruction, cycles, X);
    }
}
