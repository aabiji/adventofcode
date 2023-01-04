use std::fs;

fn main() {
    let inputs = fs::read_to_string("../inputs/day2.txt").expect("Error when reading file."); 
    let inputs_split = inputs.split("\r\n");
    let commands = inputs_split.collect::<Vec<&str>>();

    let mut x: i32 = 1;
    let mut y: i32 = 1;

    let grid: [[i32; 3]; 3] = [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ];

    for line in commands {
        for c in line.chars() {
            match c {
                'U' => y = if (y - 1) > 0 {y - 1} else {y},
                'D' => y = if (y + 1) < 2 {y + 1} else {y},
                'R' => x = if (x + 1) < 2 {x + 1} else {x},
                'L' => x = if (x - 1) > 0 {x - 1} else {x},
                _   => todo(),
            }
        }
        println!("{}, {}, {}", x, y, grid[y][x]);
    }   
}
