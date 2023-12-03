use std::collections::HashMap;

fn compute_part1() -> i32 {
    let inputs = crate::utils::read_input_file("inputs/day2.txt");

    let mut answer = 0;
    let mut line_index = 0;

    for line in inputs {
        line_index += 1;

        let mut valid_game = true;
        let data = crate::utils::split_string(&line, ": ")[1];

        for set in crate::utils::split_string(&data, "; ") {
            let mut cube_colors = HashMap::from([("red", 0), ("green", 0), ("blue", 0)]);

            for cube in crate::utils::split_string(&set, ", ") {
                let temp = crate::utils::split_string(&cube, " ");
                let count = temp[0].parse::<u32>().unwrap();

                let entry = cube_colors.entry(temp[1]).or_insert(0);
                *entry += count;
            }

            if cube_colors["red"] > 12 || cube_colors["green"] > 13 || cube_colors["blue"] > 14 {
                valid_game = false;
                break;
            }
        }

        if valid_game {
            answer += line_index;
        }
    }

    answer
}

fn compute_part2() -> i32 {
    let inputs = crate::utils::read_input_file("inputs/day2.txt");
    let mut answer = 0;

    for line in inputs {
        let data = crate::utils::split_string(&line, ": ")[1];
        let cubes = data.replace(";", ",");
        let mut cube_colors = HashMap::from([("red", 0), ("green", 0), ("blue", 0)]);

        for cube in crate::utils::split_string(&cubes, ", ") {
            let temp = crate::utils::split_string(&cube, " ");
            let count = temp[0].parse::<i32>().unwrap();

            let entry = cube_colors.entry(temp[1]).or_insert(0);
            if *entry < count {
                *entry = count;
            }
        }

        let power = cube_colors["red"] * cube_colors["green"] * cube_colors["blue"];
        answer += power;
    }

    answer
}

pub fn compute_puzzle(part: i32) -> i32 {
    if part == 1 {
        compute_part1()
    } else {
        compute_part2()
    }
}
