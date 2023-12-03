use std::collections::HashMap;

pub fn compute_puzzle(part: u32) -> i32 {
    let inputs = crate::utils::read_inputs("inputs/day2.txt");
    let mut answer = 0;

    let max_red = 12;
    let max_green = 13;
    let max_blue = 14;
 
    let mut line_idx = 0;
    for line in inputs {
        line_idx += 1;
 
        let mut possible = true;
        let line = line.split(": ").collect::<Vec<&str>>()[1];

        for set in line.split("; ") {
            let mut set_counts = HashMap::from([("red", 0), ("green", 0), ("blue", 0)]);
 
            for element in set.split(", ") {
                let parts = element.split(" ").collect::<Vec<&str>>();
                let amount = parts[0].parse::<u32>().unwrap();
 
                let set_entry = set_counts.entry(parts[1]).or_insert(0);
                *set_entry += amount;
            }
 
            if set_counts["red"] > max_red || set_counts["green"] > max_green || set_counts["blue"] > max_blue {
                possible = false;
                break;
            }
        }

        if possible {
            answer += line_idx;
        }
    }

    answer
}